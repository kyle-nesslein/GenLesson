#include "LibWrapper.h"

namespace LibWrapper {

	// Returns a string decribing the graphical notation of a note duration
	// Only returns base value!
	string get_k_type(int duration, int divisions) {
		// These are all the defined base values in musicxml->xsd
		float val = (float)duration/(float)divisions;
		if ( val >= 16 )
			return "long";
		if ( val >= 8 )
			return "breve";
		if ( val >= 4 )
			return "whole";
		if ( val >= 2 )
			return "half";
		if ( val >= 1 )
			return "quarter";
		if ( val >= 0.5 )
			return "eighth";
		if ( val >= 0.25 )
			return "16th";
		if ( val >= 0.125 )
			return "32nd";
		if ( val >= 0.0625 )
			return "64th";
		if (val >= 0.03125 )
			return "128th";
		if ( val >= 0.015625)
			return "256th";
		
		// Default:
		return "";
	}

	//------------------------------------------------------------------------
	Sxmlattribute newAttribute(const string& name, const string& value)
	{
		Sxmlattribute attribute = xmlattribute::create();
		attribute->setName(name);
		attribute->setValue(value);
		return attribute;
	}

	//------------------------------------------------------------------------
	Sxmlattribute newAttributeI(const string& name, int value)
	{
		Sxmlattribute attribute = xmlattribute::create();
		attribute->setName(name);
		attribute->setValue(value);
		return attribute;
	}

	//------------------------------------------------------------------------
	Sxmlelement newElement(int type, const string& value)
	{
		Sxmlelement elt = factory::instance().create(type);
		elt->setValue (value);
		return elt;
	}

	//------------------------------------------------------------------------
	Sxmlelement newElementI(int type, int value)
	{
		Sxmlelement elt = factory::instance().create(type);
		elt->setValue (value);
		return elt;
	}

	string intToString(int anInt) {
		char intChars[50];
		sprintf(intChars, "%d",anInt);
		string s = intChars;
		return s;
	}

	// Statistically accurate random ints, no bias
	int getRandomInt(int max) {
		if (max <= 0)
			return 0;
		else {
			// Get the smallest power of 2 greater than max:
			int power = RAND_MAX;
			while ((power / 2) > max)
				power = power / 2;
			
			// Generate random numbers until smaller than max
			int r = rand() % power;
			while (r > max)
				r = rand() % power;
				
			return r;
		}
	}


	int noteToInt(Note* aNote) {
		int base;
		switch (aNote->getStep()) {
			case 'C':
				base = 0;
				break;
			case 'D':
				base = 2;
				break;
			case 'E':
				base = 4;
				break;
			case 'F':
				base = 5;
				break;
			case 'G':
				base = 7;
				break;
			case 'A':
				base = 9;
				break;
			case 'B':
				base = 11;
				break;
		}
		
		return (base + aNote->getAlter()) % 12;
	}

	// This is what should be used after the rule engine can limit the key.
	vector<Note*>* intToNotes(int pitch, int octave, int string, int fret) {
		vector<Note*>* notes = new vector<Note*>;
		Note* note1;
		Note* note2;
		Note* note3;
		
		switch (pitch) {
			case 0:
				note1 = new Note('B', octave -1, 1, string, fret);
				note2 = new Note('C', octave, 0, string, fret);
				note3 = new Note('D', octave, -2, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 1:
				note1 = new Note('B', octave -1, 2, string, fret);
				note2 = new Note('C', octave, 1, string, fret);
				note3 = new Note('D', octave, -1, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 2:
				note1 = new Note('C', octave, 2, string, fret);
				note2 = new Note('D', octave, 0, string, fret);
				note3 = new Note('E', octave, -2, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 3:
				note1 = new Note('D', octave, 1, string, fret);
				note2 = new Note('E', octave, -1, string, fret);
				note3 = new Note('F', octave, -2, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 4:
				note1 = new Note('D', octave, 2, string, fret);
				note2 = new Note('E', octave, 0, string, fret);
				note3 = new Note('F', octave, -1, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 5:
				note1 = new Note('E', octave, 1, string, fret);
				note2 = new Note('F', octave, 0, string, fret);
				note3 = new Note('G', octave, -2, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 6:
				note1 = new Note('E', octave, 2, string, fret);
				note2 = new Note('F', octave, 1, string, fret);
				note3 = new Note('G', octave, -1, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 7:
				note1 = new Note('F', octave, 2, string, fret);
				note2 = new Note('G', octave, 0, string, fret);
				note3 = new Note('A', octave, -2, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 8:
				note1 = new Note('G', octave, 1, string, fret);
				note2 = new Note('A', octave, -1, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				break;
			case 9:
				note1 = new Note('G', octave, 2, string, fret);
				note2 = new Note('A', octave, 0, string, fret);
				note3 = new Note('B', octave, -2, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 10:
				note1 = new Note('A', octave, 1, string, fret);
				note2 = new Note('B', octave, -1, string, fret);
				note3 = new Note('C', octave + 1, -2, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
			case 11:
				note1 = new Note('A', octave, 2, string, fret);
				note2 = new Note('B', octave, 0, string, fret);
				note3 = new Note('C', octave + 1, -1, string, fret);
				notes->push_back(note1);
				notes->push_back(note2);
				notes->push_back(note3);
				break;
		}
		return notes;
	}

	// Limit the pitch set to these pitches until the rule engine can limit the key
	vector<Note*>* intToNotesOLD(int pitch, int octave, int string, int fret) {
		vector<Note*>* notes = new vector<Note*>;
		Note* note1;
		Note* note2;
		
		switch (pitch) {
			case 0:
				note2 = new Note('C', octave, 0, string, fret);
				notes->push_back(note2);
				break;
			case 1:
				note2 = new Note('C', octave, 1, string, fret);
				notes->push_back(note2);
				break;
			case 2:
				note2 = new Note('D', octave, 0, string, fret);
				notes->push_back(note2);
				break;
			case 3:
				note1 = new Note('D', octave, 1, string, fret);
				notes->push_back(note1);
				break;
			case 4:
				note2 = new Note('E', octave, 0, string, fret);
				notes->push_back(note2);
				break;
			case 5:
				note2 = new Note('F', octave, 0, string, fret);
				notes->push_back(note2);
				break;
			case 6:
				note2 = new Note('F', octave, 1, string, fret);
				notes->push_back(note2);
				break;
			case 7:
				note2 = new Note('G', octave, 0, string, fret);
				notes->push_back(note2);
				break;
			case 8:
				note1 = new Note('G', octave, 1, string, fret);
				notes->push_back(note1);
				break;
			case 9:
				note2 = new Note('A', octave, 0, string, fret);
				notes->push_back(note2);
				break;
			case 10:
				note1 = new Note('A', octave, 1, string, fret);
				notes->push_back(note1);
				break;
			case 11:
				note2 = new Note('B', octave, 0, string, fret);
				notes->push_back(note2);
				break;
		}
		return notes;
	}

}
