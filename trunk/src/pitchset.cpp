#include "pitchset.h"

PitchSet::PitchSet() {
	
}

string PitchSet::toString() {
	string out = "";
	for (int i = 0; i < pitchSet.size(); i++) {
		out += pitchSet[i]->toString();
		if (pitchSet.size() -1 != i)
			out += ", ";
	}
	return out;
}

vector<Note*>* PitchSet::getPitchSet () {
	return &pitchSet;
}

void PitchSet::setPitchSet(vector<Note*> notes) {
	pitchSet = notes;
}

void PitchSet::addNote(Note* aNote) {
	pitchSet.push_back(aNote);
}

int PitchSet::size() {
	return pitchSet.size();
}

Note* PitchSet::operator[] (int i) {
	return pitchSet[i];
}
