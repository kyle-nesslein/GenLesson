#ifndef voice_class_h
#define voice_class_h

#include <vector>
#include <iostream>
#include "nchord.h"
#include "part.h"
// Forward declarations
class Part;
//class NChord;

using namespace std;

class Voice {
	public:
		Voice();
		void addNChord(NChord*);
		NChord* getNChordAt(int);
		NChord* getNChordWhen(int);
		int getTimeLeftInMeasure();
		int getNumNChords();
		int getMeasureLength();
		vector<NChord*>* getMeasure(int measureNo);
		float wnbd(vector<NChord*>* measure);
		int wnbdOLD(vector<NChord*>* measure);
		void print();
		void deleteLastNChord();
		Part* getParent();
		void setParent(Part*);
		string toString();
	private:
		vector<NChord*> nChords_;
		Part* parent_;
};

#endif
