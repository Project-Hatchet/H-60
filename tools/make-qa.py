#!/usr/bin/env python3
# vim: set fileencoding=utf-8 :

__version__ = "0.9"

import sys
import os
import configparser
from datetime import datetime
import subprocess
from subprocess import call
import shutil
import uuid

if sys.version_info[0] == 2:
    print("Python 3 is required.")
    sys.exit(1)
    

make_target = "DEFAULT"
make_root = os.path.dirname(os.path.realpath(__file__))
make_root_parent = os.path.abspath(os.path.join(os.getcwd(), os.pardir))
os.chdir(make_root)

def getBuildNum(path):
  stringList = readVersionFileLines(path)
  buildNum = int(stringList[3].replace("#define BUILD ", ""))
  return buildNum

def readVersionFileLines(path):
  versionFile = open(path)
  stringList = versionFile.readlines()
  versionFile.close()
  return stringList

def writeVersionFileLines(path,lines):
  versionFile = open(path, "w")
  versionFile.write("".join(lines))
  versionFile.close()

def updateVersionFile(path,buildNum,buildName):
  stringList = readVersionFileLines(path)
  stringList[3] = "#define BUILD "+str(buildNum)+"\n"
  stringList[4] = "#define RELEASENAME "+buildName+"\n"
  stringList[5] = "#define BRANCH "+ getGitBranch()+"\n"
  stringList[6] = "#define BUILDHASH "+ (str(uuid.uuid4())[:8])
  writeVersionFileLines(path,stringList)

def getBuildName():
    gitBranch = getGitBranch()
    return datetime.today().strftime('HATCHET-QA-%d%b%y').upper()

def getGitBranch():
  output = subprocess.check_output(["git","branch","--show-current"])
  output = str(output).replace("b'","").replace("\\n'","").replace("/","-")
  return output.upper()

def getBuildConfig():
  cfg = configparser.ConfigParser()
  try:
    cfg.read(os.path.join(make_root, "make.cfg"))
    # Project name (with @ symbol)
    project = cfg.get(make_target, "project", fallback="@"+os.path.basename(os.getcwd()))
    # Release archive prefix
    module_root = cfg.get(make_target, "module_root", fallback=os.path.join(make_root_parent, "addons"))
    release_dir = cfg.get(make_target, "release_dir", fallback="release")
    versionFilePath = module_root+"\\main\\script_version.hpp"
    return {
      "addonName": project,
      "moduleRoot": module_root,
      "releaseDir": release_dir,
      "versionFilePath": versionFilePath
    }
  except:
      print("Something went wrong.")
      traceback.print_exc()
      sys.exit(1)

def packBuild(buildConfig,fileName):
  shutil.make_archive(fileName, 'zip', buildConfig["releaseDir"]+"\\"+buildConfig["addonName"])
  shutil.move(make_root+"\\"+fileName+".zip", buildConfig["releaseDir"])

def makeQABuild():
  buildConfig = getBuildConfig()
  buildName = getBuildName()
  buildNum = getBuildNum(buildConfig["versionFilePath"]) + 1
  fileName = buildName+"-"+getGitBranch()+"-"+str(buildNum)

  updateVersionFile(buildConfig["versionFilePath"],buildNum,buildName)
  call(["py", "make.py"])
  packBuild(buildConfig,fileName)


print(getBuildName())
makeQABuild()