#!/bin/bash
cmake ../trunk && 
	#make clean && 
	make &&
	./src/GenLesson lessonAdv.fmt | less
	
