#ifndef note_class_h
#define note_class_h

#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;


class Note {
	public:
		Note (char, int, int, int, int);
		Note ();
		char getStep();
		int getOctave();
		int getAlter();
		int getString();
		int getFret();
		void setStep(char);
		void setOctave(int);
		void setAlter(int);
		void setRandomNote();
		string toString();
	private:
		char step_;
		int octave_, alter_, string_, fret_;
};

#endif
