#ifndef pitch_set_h
#define pitch_set_h

#include <string>
#include <vector>
#include <iostream>
#include "note.h"

// Forward declarations
//class Note;
//class string;
//class vector;

using namespace std;

class PitchSet {
	public:
	PitchSet();
	vector<Note*>* getPitchSet();
	void addNote(Note*);
	string toString();
	int size();
	Note* operator[](int i);
	void setPitchSet(vector<Note*> notes);

	private:
	vector<Note*> pitchSet;

};

#endif
