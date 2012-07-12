#ifndef lesson_class_h
#define lesson_class_h

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "LibWrapper.h"
#include "note.h"
#include "part.h"
#include "voice.h"
#include "pitchset.h"

// Libmusicxml2
#include "elements.h"
#include "factory.h"
#include "xml.h"
#include "xmlfile.h"

using namespace LibWrapper;
using namespace MusicXML2;
using namespace std;

// Forward declarations
//class Note;
//class Sxmlelement;
class Part;



class Lesson {
	public:
	int getRandomDuration();
	int getRandomNChordSize();
	Note* getRandomNote();
	void makeMasterPitchSet();
	void makeKeyPitchSet();
	//void makeSimpleKeyPitchSet();
	int measureEndTime(int);
	void read_fmtfile(char*);
	int getMeasureLength();
	Sxmlelement makeAttributes();
	Sxmlelement convertPart(int numMeasures, Part* aPart);
	Sxmlelement makePartList();
	Sxmlelement makeIdentification();
	Sxmlelement convertToXml(Part*);
	bool isPlayable(Part*, int);
	void generate(Part*);
	void setLength();
	int getNumVoices();
	void outputXML();
	void addPart(Part*);
	Part* getPart();
	void makeKeyPitchNames();
	PitchSet getKeyPitchNames();
	PitchSet getMasterPitchSet();
	PitchSet getKeyPitchSet();
	//PitchSet getSimpleKeyPitchSet();
	string toString();
	vector<int>* getStrongBeats();
	int getDivisions();
	
	private:
	string composer;
	string title;
	string instrumentName;
	string partName;
	
	int beats;
	int beat_type;
	int divisions;
	char clef_sign;
	int clef_line;

	int key_fifths;

	//int max_polyphony; // max simultanious notes for ALL voices and NChords, not yet implemented
	int num_voices;
	
	// vector of probabilites for NChord sizes, beginning with 0 (rests)
	vector<int> nchord_size_p;

	int num_note_dur;
	vector<int> note_durations;
	vector<int> note_durations_p;

	int syncopation_level;

	char pitch_rule[50];
	
	int min_num_bars;
	int max_num_bars;
	int numMeasures;

  	vector<int> avail_frets; // vector of fret numbers that can be used
	vector<int> avail_strings; // vector of each string ID number that can be used

  	vector<vector<int>*> open_strings; // vector of each string and its tuning: pitch,octave
  	
  	vector<int> strong_beats;
  	
  	// vector of all possible pitches, to be derived from avail_frets and avail_strings
  	//vector<Note*> pitchSet; 
  	PitchSet masterPitchSet;
  	PitchSet keyPitchNames;
	PitchSet keyPitchSet;
	//PitchSet simpleKeyPitchSet;
	
	Part* aPart_;
};

#endif
