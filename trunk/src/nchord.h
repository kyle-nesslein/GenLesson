#ifndef n_chord_class_h
#define n_chord_class_h

#include <vector>
#include "note.h"
#include <iostream>
// Forward declarations
//class Note;
class NChord;

using namespace std;

class NChord {
	public:
		NChord (int, vector<Note*>);
		NChord (int, Note*);
		NChord (int);
		NChord ();
		int getEndTime();
		//int getStartTime();
		void setEndTime(int);
		vector<Note*>& get_notes();
		int getNumNotes();
		Note* getNoteAt(int);
		void addNote(Note*);
		string toString();
	private:
		// endTime is used to store the point in time a given NChord ends. The duration can be calculated by subtraction.
		int endTime_;
		vector<Note*> notes_;
};

#endif
