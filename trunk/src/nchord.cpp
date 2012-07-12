#include "nchord.h"

NChord::NChord (int endTime, vector<Note*> notes) {
	endTime_ = endTime;
	notes_ = notes;
}

NChord::NChord (int endTime, Note* aNote) {
	endTime_ = endTime;
	notes_.push_back(aNote);
}

NChord::NChord(int endTime) {
	endTime_ = endTime;
}

int NChord::getEndTime() {
	return endTime_;
}

void NChord::setEndTime(int endTime) {
	endTime_ = endTime;
}

vector<Note*>& NChord::get_notes() {
	return notes_;
}

int NChord::getNumNotes() {
	return notes_.size();
}

Note* NChord::getNoteAt(int index) {
	return notes_[index];
}

void NChord::addNote(Note* aNote) {
	notes_.push_back(aNote);
}
/*
void NChord::print() {
	cout << "NChord: ";
	cout << "EndTime: " << endTime_ << "  ";
	for (int i = 0; i < notes_.size(); i++) {
		notes_[i]->print();
		cout << " ";
	}
}*/

string NChord::toString() {
	string out;
	//out += "NChord: ";
	for (int i = 0; i < notes_.size(); i++) {
		std::stringstream num;
		num << i;
		out = out + "Note " + num.str() + ": " + notes_[i]->toString() + "\n";
	}
	std::stringstream num;
	num << endTime_;
	out += "EndTime: " + num.str() + "\n";
	return out;
}
