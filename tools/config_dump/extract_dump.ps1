# VTX H-60 - Phase 1 config-dump extractor (WP0)
# Parses the VTXDUMP lines that dump_configs.sqf wrote to the Arma 3 RPT and
# writes them out as diffable per-class text files under dumps\<Label>\.
# If the RPT holds several dump runs, the LAST complete run wins.
#
# Usage (from the repo root):
#   powershell -ExecutionPolicy Bypass -File tools\config_dump\extract_dump.ps1 -Label baseline-f3edead
#   ... optionally -RptPath "C:\path\to\specific.rpt" (default: newest RPT in %LOCALAPPDATA%\Arma 3)

[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$Label,
    [string]$RptPath
)

$ErrorActionPreference = 'Stop'

if ($Label -notmatch '^[A-Za-z0-9._-]+$') {
    throw "Label '$Label' must contain only letters, digits, dot, underscore, dash (it becomes a folder name)."
}

if (-not $RptPath) {
    $rptDir = Join-Path $env:LOCALAPPDATA 'Arma 3'
    $newest = Get-ChildItem -Path $rptDir -Filter '*.rpt' -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($null -eq $newest) { throw "No .rpt files found in $rptDir - pass -RptPath explicitly." }
    $RptPath = $newest.FullName
}
if (-not (Test-Path $RptPath)) { throw "RPT not found: $RptPath" }

$files = @{}        # routing key (class/root name) -> List[string] of logical lines
$pending = $null    # logical line being assembled (may span VTXDUMP+| continuations)
$beginSeen = $false
$doneSeen = $false

function Flush-Pending {
    if ($null -eq $script:pending) { return }
    $payload = $script:pending
    $script:pending = $null
    $sep = $payload.IndexOf('|')
    $key = if ($sep -ge 0) { $payload.Substring(0, $sep) } else { $payload }
    if ($key -eq 'META') { $key = '_meta' }
    if ($key -notmatch '^[A-Za-z0-9_]+$') { $key = '_malformed' }
    if (-not $script:files.ContainsKey($key)) {
        $script:files[$key] = New-Object 'System.Collections.Generic.List[string]'
    }
    $script:files[$key].Add($payload)
}

foreach ($line in [System.IO.File]::ReadLines($RptPath)) {
    $i = $line.IndexOf('VTXDUMP|')
    if ($i -ge 0) {
        Flush-Pending
        $payload = $line.Substring($i + 8)
        if ($payload.StartsWith('META|BEGIN')) {
            # A fresh dump run: keep only the last run found in the RPT.
            $files.Clear()
            $beginSeen = $true
            $doneSeen = $false
        }
        if ($payload.StartsWith('META|DONE')) { $doneSeen = $true }
        $pending = $payload
        continue
    }
    $i = $line.IndexOf('VTXDUMP+|')
    if ($i -ge 0) {
        if ($null -ne $pending) { $pending += $line.Substring($i + 9) }
        continue
    }
}
Flush-Pending

if (-not $beginSeen) { throw "No VTXDUMP data found in $RptPath - did the in-game dump run?" }
if (-not $doneSeen) { Write-Warning 'DONE marker missing: the capture looks incomplete. Re-run the in-game dump and extract again.' }

$outDir = Join-Path $PSScriptRoot "dumps\$Label"
New-Item -ItemType Directory -Force -Path $outDir | Out-Null
$utf8NoBom = New-Object System.Text.UTF8Encoding($false)
$total = 0
foreach ($key in ($files.Keys | Sort-Object)) {
    $outFile = Join-Path $outDir ($key + '.txt')
    [System.IO.File]::WriteAllText($outFile, ([string]::Join("`n", $files[$key]) + "`n"), $utf8NoBom)
    Write-Host ('  {0,-42} {1,8} lines' -f ($key + '.txt'), $files[$key].Count)
    $total += $files[$key].Count
}
Write-Host ''
Write-Host "Wrote $($files.Keys.Count) files / $total lines to $outDir"
Write-Host "Source RPT: $RptPath"
Write-Host 'Diff against another capture with:'
Write-Host "  git diff --no-index tools/config_dump/dumps/<old> tools/config_dump/dumps/$Label"
