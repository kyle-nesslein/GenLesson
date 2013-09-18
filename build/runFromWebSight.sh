#!/bin/bash
echo "pwd" `pwd`
echo "HELL YEAH*************************"
# The starting directory of this script is where ever it is being run from. Since it is being run from the webserver, the directory is wherever the webserver is started from.
cd ../GenLesson/build/ &&
  ./src/GenLesson lessonAdv.fmt > out.xml &&
  musicxml2ly --no-beaming out.xml && 
	lilypond -fpng out.ly  &&
  cp -rf out.png ../../WebSight/app/assets/images/out.png &&
  echo "script.sh Complete."
#  echo `pwd`
