#!/usr/bin/env bash

# Based on the 'Travis CI Arduino Init Script' https://github.com/adafruit/travis-ci-arduino

# define colors
GRAY='\033[1;30m'; RED='\033[0;31m'; LRED='\033[1;31m'; GREEN='\033[0;32m'; LGREEN='\033[1;32m'; ORANGE='\033[0;33m'; YELLOW='\033[1;33m'; BLUE='\033[0;34m'; LBLUE='\033[1;34m'; PURPLE='\033[0;35m'; LPURPLE='\033[1;35m'; CYAN='\033[0;36m'; LCYAN='\033[1;36m'; LGRAY='\033[0;37m'; WHITE='\033[1;37m';

FAIL_MSG="""$LRED""ERROR!"
PASS_MSG="""$LGREEN""OK!"

export ARDUINO_IDE_VERSION="1.8.9"
export ARDUINO_SAMD_VERSION="1.8.1"
export ARDUINO_PATH="$PWD/.arduino"

echo -e "${LGRAY}\n########################################################################";
echo -e "${YELLOW}INSTALLING ARDUINO IDE"
echo -e "${LGRAY}########################################################################";


echo -e "${LGRAY}ARDUINO_IDE_VERSION = ${ORANGE}${ARDUINO_IDE_VERSION}"
echo -e "${LGRAY}ARDUINO_PATH        = ${ORANGE}${ARDUINO_PATH}"
echo -e "${LGRAY}########################################################################";

# http://downloads.arduino.cc/arduino-${ARDUINO_IDE_VERSION}-linux64.tar.xz

echo -ne "${LGRAY}ARDUINO IDE STATUS: "

# remove cache if version changed
if [ ! -f "$ARDUINO_PATH/$ARDUINO_IDE_VERSION" ] && [ -f "$ARDUINO_PATH/arduino" ]; then
  echo -ne "${ORANGE}REMOVING OLD VERSION... "
  echo "Y" | rm -r "${ARDUINO_PATH}"
  if [ $? -ne 0 ]; then echo -ne "${FAIL_MSG} "; else echo -ne "${PASS_MSG} "; fi
fi

# if not already cached, download and install arduino IDE
if [ ! -f "$ARDUINO_PATH/arduino" ]; then
  echo -ne "${ORANGE}DOWNLOADING... \n${LCYAN}"
  curl -f -# http://downloads.arduino.cc/arduino-${ARDUINO_IDE_VERSION}-linux64.tar.xz -o arduino.tar.xz 2>&1
  RET=$?
  echo -ne "${ORANGE}                    DOWNLOADED "
  if [ $RET -ne 0 ]; then echo -ne "${FAIL_MSG}"; else echo -ne "${PASS_MSG}"; fi
  echo -ne "${ORANGE}UNPACKING... "
  [ ! -d "$ARDUINO_PATH/" ] && mkdir "$ARDUINO_PATH"
  tar xf arduino.tar.xz -C "$ARDUINO_PATH/" --strip-components=1
  if [ $? -ne 0 ]; then echo -e "${FAIL_MSG}"; else echo -e "${PASS_MSG}"; fi
  touch "$ARDUINO_PATH/$ARDUINO_IDE_VERSION"
  if [ -f arduino.tar.xz ]; then rm arduino.tar.xz; fi
else
  echo -e "${ORANGE}CACHED ${PASS_MSG}"
fi

# make the IDE portable
mkdir -p "$ARDUINO_PATH/portable"

# add the IDE to the path
export PATH="$ARDUINO_PATH:$PATH"

echo -e "${LGRAY}\n########################################################################";
echo -e "${YELLOW}INSTALLING MKRVIDOR4000"
echo -e "${LGRAY}########################################################################";

echo -ne "${LGRAY}ADD BOARD URL: "
BOARD_URL_OUTPUT=$(arduino --pref "boardsmanager.additional.urls=http://downloads.arduino.cc/packages/package_staging_index.json" --save-prefs 2>&1)
if [ $? -ne 0 ]; then echo -e "${FAIL_MSG}"; else echo -e "${PASS_MSG}"; fi

echo -ne "${LGRAY}INSTALLING BOARD: "
if [ ! -d "$ARDUINO_PATH/portable/packages/arduino/hardware/samd/${ARDUINO_SAMD_VERSION}" ]; then
  DEPENDENCY_OUTPUT=$(arduino --install-boards arduino:samd 2>&1)
  if [ $? -ne 0 ]; then echo -e "${FAIL_MSG}"; else echo -e "${PASS_MSG}"; fi
else
  echo -e "${ORANGE}CACHED ${PASS_MSG}"
fi

echo -ne "${LGRAY}SWITCHING BOARD: "
SWITCH_OUTPUT=$(arduino --board arduino:samd:mkrvidor4000 --save-prefs 2>&1)
if [ $? -ne 0 ]; then echo -e "${FAIL_MSG}"; else echo -e "${PASS_MSG}"; fi

echo -e "${LGRAY}\n########################################################################";
echo -e "${YELLOW}DONE!"
echo -e "${LGRAY}########################################################################";
