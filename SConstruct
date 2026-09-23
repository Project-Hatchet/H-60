from SCons.Script import *

import os.path
import glob
import winreg
import urllib.request
import os
import zipfile
import json
import subprocess
import re
import hashlib

env = Environment(tools=[])

# Utility functions

def allFilesIn(path):
    return [s.replace("$", "$$") for s in glob.glob(path + '/**/*', recursive=True) if os.path.isfile(s)]

def getSettings():
    with open("tools/build.json") as file:
        return json.load(file)

def targetDefinition(target, description):
    return env.Help(f"\n{target.ljust(20)}\t - {description}")

def isJunction(path):
    process = subprocess.run(["fsutil", "reparsepoint", "query", path], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return process.returncode == 0

# Useful paths
def a3toolsPath():
    with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r"SOFTWARE\Bohemia Interactive\Arma 3 Tools") as key:
        return winreg.QueryValueEx(key, "path")[0]

def arma3Path():
    reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
    with winreg.OpenKey(reg, r"SOFTWARE\Wow6432Node\bohemia interactive\arma 3") as key:
        return winreg.EnumValue(key,1)[1]

def addonBuilderPath():
    return os.path.join(a3toolsPath(), "AddonBuilder", "AddonBuilder.exe")

class Object(object):
    pass

def getPboInfo(settings):
    def addInfo(name):
        pboInfo = Object()
        pboInfo.name = name
        pboInfo.folder = os.path.join(settings["addonsFolder"], name)
        pboInfo.outputPath = pboInfo.folder + ".pbo"
        pboInfo.builtpath = os.path.join(settings["outputFolder"], name + ".pbo")
        pboInfo.filename = "hct_h60_" + name + ".pbo"
        pboInfo.filepath = os.path.join(settings["outputFolder"], pboInfo.filename)
        with open(os.path.join(pboInfo.folder,"$PBOPREFIX$"), "r") as file:
            pboInfo.pboPrefix = file.readline().strip()
        try:
            pboInfo.a3symlink = os.path.join("P:",pboInfo.pboPrefix)
        except:
            pboInfo.a3symlink = None

        pboInfo.buildSymlink = os.path.join("build",pboInfo.pboPrefix)

        if (name in settings["excludePboSymlinks"]):
            pboInfo.a3symlink = None
        return pboInfo
    return list(map(addInfo,filter(lambda x: os.path.isdir(os.path.join(settings["addonsFolder"], x)), os.listdir(settings["addonsFolder"]))))

def removeSymlink(pathTo):
    if pathTo is None:
        return []
    commands = []
    if isJunction(pathTo):
        commands.append(f'fsutil reparsepoint delete \"{pathTo}\"')
    if os.path.isdir(pathTo):
        commands.append(Delete(pathTo))
    return commands

def buildSymlink(pathFrom, pathTo):
    if pathTo is None:
        return []
    commands = removeSymlink(pathTo)
    if not os.path.isdir(os.path.dirname(pathTo)):
        commands.append(Mkdir(os.path.dirname(pathTo)))
    commands.append(f'mklink /J "{pathTo}" "{pathFrom}"')
    return commands

def modVersion():
    with open(os.path.join("addons", "main", "script_version.hpp")) as file:
        defines = dict(re.findall(r"#define\s+(\w+)\s+(\d+)", file.read()))
    return "{MAJOR}.{MINOR}.{PATCHLVL}.{BUILD}".format(**defines)

# RPT pbo listings print the pbo header's 'version' property; AddonBuilder never
# writes one, so every H-60 pbo reported "unknown" and server/client build
# mismatches were invisible per-pbo. Insert the script_version.hpp version into
# the sreV properties block and refresh the trailing SHA1 checksum.
def stampPboVersion(pboPath, version):
    with open(pboPath, "rb") as file:
        data = file.read()
    if not data.startswith(b"\x00sreV"):
        raise Exception(pboPath + ": no sreV header entry, cannot stamp version")
    body, trailer = data[:-21], data[-21:]
    if trailer[:1] != b"\x00" or trailer[1:] != hashlib.sha1(body).digest():
        raise Exception(pboPath + ": trailing checksum invalid, cannot stamp version")
    pos = 21  # empty filename + the 5 uint32 fields of the sreV entry
    props = []
    while True:
        end = body.index(b"\x00", pos)
        if end == pos:
            break
        props.append(body[pos:end])
        pos = end + 1
    if len(props) % 2:
        raise Exception(pboPath + ": malformed header properties, cannot stamp version")
    pairs = [props[i:i+2] for i in range(0, len(props), 2)]
    pairs = [p for p in pairs if p[0].lower() != b"version"]
    pairs.append([b"version", version.encode("ascii")])
    propBlock = b"".join(p[0] + b"\x00" + p[1] + b"\x00" for p in pairs)
    newBody = body[:21] + propBlock + body[pos:]
    with open(pboPath, "wb") as file:
        file.write(newBody + b"\x00" + hashlib.sha1(newBody).digest())

def buildPbo(settings,env, pbo):
    optBinarize = "-binarize=C:\\Windows\\System32\\print.exe" if pbo.name in settings["noBinarize"] else ""
    cfgConvertArg = "-cfgconvert=asdfafds" # + a3toolsPath() + "\\CfgConvert\\CfgConvert.exe"
    def stampAction(target, source, env, path=os.path.abspath(pbo.filepath)):
        stampPboVersion(path, modVersion())
        return 0
    env.Command(pbo.outputPath, allFilesIn(pbo.folder)+["build"],[
        f'"{addonBuilderPath()}" "{os.path.abspath(pbo.buildSymlink)}" "{os.path.abspath(settings["outputFolder"])}" "-project=build" "-prefix={pbo.pboPrefix}" -include=tools\\buildExtIncludes.txt {optBinarize}',
        Move(os.path.abspath(settings["outputFolder"]) + "/" + pbo.filename, os.path.abspath(pbo.builtpath)),
        Action(stampAction, f"stampPboVersion({pbo.filename})")
        ])
    targetDefinition(pbo.name, f"Build the {pbo.name} pbo.")
    return env.Alias(pbo.name, pbo.outputPath)

def downloadNaturaldocs(target, source, env):
    url = "https://www.naturaldocs.org/download/natural_docs/2.1.1/Natural_Docs_2.1.1.zip"
    zipFilePath = r"buildTools\NaturalDocs.zip"
    urllib.request.urlretrieve(url, zipFilePath)
    with zipfile.ZipFile(zipFilePath, 'r') as zip_ref:
        zip_ref.extractall(r"buildTools")

print(addonBuilderPath())
settings = getSettings()
pbos = getPboInfo(settings)

pboAliases = [buildPbo(settings,env, pbo) for pbo in pbos]

env.Command("buildTools", [], Mkdir("buildTools"))

buildDir = env.Command("build", allFilesIn("include"), [Copy("build", "include")] + sum(map(lambda pbo: buildSymlink(pbo.folder, pbo.buildSymlink),pbos),[]))

env.Command(r"buildTools\Natural Docs", [], [downloadNaturaldocs, Delete(r"buildTools\NaturalDocs.zip")])

allPbos = env.Alias("all", pboAliases)
targetDefinition("all", "Build all pbos.")

buildDocs = env.Command(r"apidocs\index.html",
    [s for s in allFilesIn(settings["addonsFolder"]) if s.endswith(".sqf")] + [r"buildTools\Natural Docs"],
    [Mkdir("apidocs"), r'"buildTools\Natural Docs\NaturalDocs.exe" naturaldocs'])
env.AlwaysBuild(buildDocs)

env.Alias("docs", r"apidocs\index.html")
targetDefinition("docs", "Generate naturaldocs documentation")
env.Help("\n")

if GetOption('clean'):
    env.Execute(sum(map(lambda pbo: removeSymlink(pbo.buildSymlink), pbos),[]))
env.Clean(["build", "all"], r"build")
env.Clean(["buildTools", "all"], r"buildTools")
env.Clean(["docs", "all"], ["apidocs", r"naturaldocs\Working Data"])

try:
    settings = getSettings()
    a3dir = arma3Path()
    symlinks = env.Alias("symlinks", [], sum(map(lambda pbo: buildSymlink(pbo.folder, pbo.a3symlink), pbos),[]))
    env.AlwaysBuild(symlinks)

    removeSymlinks = env.Alias("rmsymlinks", [], sum(map(lambda pbo: removeSymlink(pbo.a3symlink), pbos),[]))
    env.AlwaysBuild(removeSymlinks)
except Exception as e:
    print(e)
    print("Error: Couldn't find arma 3, cannot make or remove symlinks")

env.Default("all")
