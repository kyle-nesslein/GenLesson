#include "part.h"

#include "voice.h"

void Part::setParent(Lesson* parent) {
	parent_ = parent;
}

Lesson* Part::getParent() {
	return parent_;
}

Part::Part () {	
}

Part::Part(int numVoices) {
	for (int i = 1; i <= numVoices; i++) {
		Voice* newVoice = new Voice;
		voices_.push_back(newVoice);
	}
}

void Part::addVoice(Voice* aVoice) {
	voices_.push_back(aVoice);
}

int Part::getNumVoices() {
	return voices_.size();
}

Voice* Part::getVoice(int voiceNo) {
	return voices_[voiceNo];
}

string Part::toString() {
	string out = "";
	for (int i = 0; i < voices_.size(); i++) {
		std::stringstream num;
		num << i;
		out += "Voice number: " + num.str() + "\n";
		out += voices_[i]->toString();
	}
	return out;
}
