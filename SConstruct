from SCons.Script import *

import os.path
import glob
import winreg
import urllib.request
import os
import zipfile
import json
import subprocess

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

def buildPbo(settings,env, pbo):
    optBinarize = "-binarize=C:\\Windows\\System32\\print.exe" if pbo.name in settings["noBinarize"] else ""
    env.Command(pbo.outputPath, allFilesIn(pbo.folder)+["build"], 
        f'"{addonBuilderPath()}" "{os.path.abspath(pbo.buildSymlink)}" "{os.path.abspath(settings["addonsFolder"])}" "-project=build" "-prefix={pbo.pboPrefix}" -include=tools\\buildExtIncludes.txt {optBinarize}')
    targetDefinition(pbo.name, f"Build the {pbo.name} pbo.")
    return env.Alias(pbo.name, pbo.outputPath)

def downloadNaturaldocs(target, source, env):
    url = "https://www.naturaldocs.org/download/natural_docs/2.1.1/Natural_Docs_2.1.1.zip"
    zipFilePath = r"buildTools\NaturalDocs.zip"
    urllib.request.urlretrieve(url, zipFilePath)
    with zipfile.ZipFile(zipFilePath, 'r') as zip_ref:
        zip_ref.extractall(r"buildTools")

settings = getSettings()
pbos = getPboInfo(settings)

pboAliases = [buildPbo(settings,env, pbo) for pbo in pbos]

env.Command("buildTools", [], Mkdir("buildTools"))

buildDir = env.Command("build", allFilesIn("include"), [Copy("build", "include")] + sum(map(lambda pbo: buildSymlink(pbo.folder, pbo.buildSymlink),pbos),[]))

env.Command(r"buildTools\Natural Docs", [], [downloadNaturaldocs, Delete(r"buildTools\NaturalDocs.zip")])

allPbos = env.Alias("all", pboAliases)
targetDefinition("all", "Build all pbos.")

buildDocs = env.Command(r"docs\index.html",
    [s for s in allFilesIn(settings["addonsFolder"]) if s.endswith(".sqf")] + [r"buildTools\Natural Docs"], 
    [Mkdir("docs"), r'"buildTools\Natural Docs\NaturalDocs.exe" naturaldocs'])
env.AlwaysBuild(buildDocs)

env.Alias("docs", r"docs\index.html")
targetDefinition("docs", "Generate naturaldocs documentation")
env.Help("\n")

if GetOption('clean'):
    env.Execute(sum(map(lambda pbo: removeSymlink(pbo.buildSymlink), pbos),[]))
env.Clean(["build", "all"], r"build")
env.Clean(["buildTools", "all"], r"buildTools")
env.Clean(["docs", "all"], ["docs", r"naturaldocs\Working Data"])

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