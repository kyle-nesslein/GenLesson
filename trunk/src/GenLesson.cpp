/*
 * TODO:
 * make pitch class object with toString()
 * max n-chord size in .fmt isn't used - it only goes by the probabilities.
 * Implement Rule engine
 *   Stay in the key
 *   Rest format rules
 * CLEAN UP CODE
 *   fix poor comments
 * Check random duration + nchord size functions, make sure distribution is statictically accurate
*/

#include <ctime>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include <vector>

#ifdef WIN32
#include <windows.h>
#endif

#include "elements.h"
#include "factory.h"
#include "xml.h"
#include "xmlfile.h"


#include "lesson.h"
#include "part.h"
#include "voice.h"
#include "LibWrapper.h"

using namespace MusicXML2;
using namespace LibWrapper;
using namespace std;


#define MAX_NUM_DURATIONS 20
#define MAX_PITCHES 30
#define MAX_FRETS 36
#define MIN_OCTAVE 3
#define OCTAVE_SPAN 2


int main (int argc, char * argv[]) {
	// sets the random numbers seed
	#ifdef WIN32
	srand((unsigned)time(0));
	#else
	srandom((unsigned)time(0));
	#endif
	
	Lesson aLesson;
	if (argc != 2 ) {
		cout << "Insufficient number of parameters! Exiting..." << endl;
		exit(-1);
	}

	aLesson.read_fmtfile(argv[1]);
	aLesson.makeMasterPitchSet();
	
	//aLesson.makeSimpleKeyPitchSet();
	aLesson.makeKeyPitchNames();
	aLesson.makeKeyPitchSet();
	/*
	cout << "Key Pitch Names: ";
	cout << aLesson.getKeyPitchNames().toString();
	cout << endl;
	cout << "Key Pitch Set: ";
	cout << aLesson.getKeyPitchSet().toString();
	cout << endl;
	cout << "Master Pitch Set: ";
	cout << aLesson.getMasterPitchSet().toString();
	cout << endl << endl;
	*/
	aLesson.setLength();
	Part* aPart = new Part(aLesson.getNumVoices());
	for (int i = 0; i < aLesson.getNumVoices(); i++) {
		aPart->getVoice(i)->setParent(aPart);
	}
	aPart->setParent(&aLesson);
	aLesson.addPart(aPart);
	aLesson.generate(aPart);
	aLesson.outputXML();
	
	//cout << aLesson.toString();
	Voice* holder = aLesson.getPart()->getVoice(0);
	vector<NChord*>* measure = holder->getMeasure(2);
	//cout << ((&measure)[0])->toString();
	//cout << ((&measure)[0])->toString();
	cout << "wnbd: " << holder->wnbd(measure);

    return 0;
    
}

