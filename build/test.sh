#!/bin/bash
cmake ../trunk && 
	#make clean && 
	make &&
	./src/GenLesson lessonAdv.fmt > out.xml && 
	musicxml2ly --no-beaming out.xml && 
	lilypond out.ly && evince out.pdf &

