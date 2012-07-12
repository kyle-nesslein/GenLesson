#include "note.h"

Note::Note(char step, int octave, int alter, int string, int fret) {
	step_ = step;
	octave_ = octave;
	alter_ = alter;
	string_ = string;
	fret_ = fret;
}

char Note::getStep() {
	return step_;
}

int Note::getOctave() {
	return octave_;
}

int Note::getAlter() {
	return alter_;
}

int Note::getString() {
	return string_;
}

int Note::getFret() {
	return fret_;
}

void Note::setStep(char step) {
	step_ = step;
}

void Note::setOctave(int octave) {
	octave_ = octave;
}

void Note::setAlter(int alter) {
	alter_ = alter;
}

// For debugging
string Note::toString() {
	string out = "";
	//void* buf = malloc(4);
	out += step_;
	switch (alter_) {
		case -2:
			out += "bb";
			break;
		case -1:
			out += "b";
			break;
		case 0:
			out += "";
			break;
		case 1:
			out += "#";
			break;
		case 2:
			out += "##";
	}
	//itoa(octave_, buf, 10);
	std::stringstream num;
	num << octave_;
	out += num.str();
	return out;
}
