#include "voice.h"

Voice::Voice() {
}


void Voice::addNChord(NChord* anNChord) {
	nChords_.push_back(anNChord);
}

NChord* Voice::getNChordAt(int nChordNo) {
	return nChords_[nChordNo];
}

// Returns a NULL pointer when there is no such event!
NChord* Voice::getNChordWhen(int eventStartTime) {
	int nChordNo = 0; // Start with first nChord
	if (nChords_.size() == 0) // If no events, return null.
		return NULL;
	while (eventStartTime >= nChords_[nChordNo]->getEndTime()) {
		if (nChordNo +1 < nChords_.size())
			nChordNo++;
		else
			break;
	}
	if (eventStartTime >= nChords_[nChordNo]->getEndTime())
		return NULL;
	else
		return nChords_[nChordNo];
}



int Voice::getTimeLeftInMeasure () {
	int measure_length = getMeasureLength();
	if (nChords_.size() == 0) 
		return measure_length;
	else {
		int time = 0;
		NChord* last = nChords_.back();
		time = last->getEndTime() % measure_length;
		if (time == 0) // begin new measure
			return measure_length;
		else
			return measure_length - time;
	}
}

void Voice::deleteLastNChord() {
	nChords_.pop_back();
}

int Voice::getNumNChords() {
	return nChords_.size();
}

void Voice::print() {
	cout << "Voice:" << endl;
	for (int i = 0; i < nChords_.size(); i++) {
		cout << nChords_[i]->toString();
		cout << endl;
	}
}

void Voice::setParent(Part* aPart) {
	parent_ = aPart;
}

Part* Voice::getParent() {
	return parent_;
}

int Voice::getMeasureLength() {
	return parent_->getParent()->getMeasureLength();
}

string Voice::toString() {
	string out = "";
	for (int i = 0; i < nChords_.size(); i++) {
		std::stringstream num;
		num << i;
		out += "NChord number: " + num.str() + "\n";
		out += nChords_[i]->toString() + "\n";
	}
	return out;
}

vector<NChord*>* Voice::getMeasure(int measureNo) {
	vector<NChord*>* measure = new vector<NChord*>;
	
	int measureStartTime = (measureNo-1) * parent_->getParent()->getMeasureLength();
	int measureEndTime = measureNo * parent_->getParent()->getMeasureLength();
	
	for (int i = 0; i < nChords_.size(); i++) {
		if (nChords_[i]->getEndTime() > measureStartTime &&
			nChords_[i]->getEndTime() <= measureEndTime) {
			measure->push_back(nChords_[i]);
		}
			
	}
	
	return measure;
}

float Voice::wnbd(vector<NChord*>* measure) {
	float sum = 0;
	
	int e_i = 0;
	int e_i1 = 0;
	int e_i2 = 0;
	int x = 0;
	int x_end = 0;
	
	int measureLength = getMeasureLength();
	int measureStartTime = measure->back()->getEndTime() - measureLength;
	int measureNo = measureStartTime / measureLength;
	vector<int>* beatTimes = getParent()->getParent()->getStrongBeats();
	
	// Initialize beats:
	// ASSUMPTION
	// There are different cases here for different numbers of beats...
	e_i = (*beatTimes)[0];
	e_i1 = (*beatTimes)[1];
	e_i2= (*beatTimes)[2];
	
	int beatTimesIndex = 0;
	
	for (int i = 0; i < measure->size(); i++) {
		// Setup note times
		if (i==0) {
			x = 0;
		} else {
			x = (*measure)[i-1]->getEndTime() - measureStartTime;
		}
		x_end = (*measure)[i]->getEndTime() - measureStartTime;
		
		// Setup the e_i beats according to the current note:
		int beatTimesIndex = beatTimes->size() -1;
		while ( (*beatTimes)[beatTimesIndex] > x) {
			beatTimesIndex--;
		}
		// All 3 beats are in this measure:
		if (beatTimesIndex + 2 <= (beatTimes->size()) - 1) { 
			e_i = (*beatTimes)[beatTimesIndex];
			e_i1 = (*beatTimes)[beatTimesIndex+1];
			e_i2= (*beatTimes)[beatTimesIndex+2];
		} 
		// e_i2 is outside only
		if (beatTimesIndex + 1 == (beatTimes->size()) - 1) {
			e_i = (*beatTimes)[beatTimesIndex];
			e_i1 = (*beatTimes)[beatTimesIndex+1];
			e_i2= (*beatTimes)[0] + measureLength;
		}	
		// e_i1 and e_i2 are outside
		if (beatTimesIndex == (beatTimes->size()) - 1) {
			e_i = (*beatTimes)[beatTimesIndex];
			e_i1 = (*beatTimes)[0] + measureLength;
			e_i2= (*beatTimes)[1] + measureLength;
		}
		
		
		// Add the D(x) to the sum
		if (x == e_i) {
			sum += 0;
		}
		
		if (x != e_i && x_end <= e_i1) {
			// D(x)=1/T(x)
			float tx1 = x - e_i;
			float tx2 = e_i1 - x;
			if (tx1 < 0)
				tx1*=-1.0;
			if (tx2 < 0)
				tx2*=-1.0;
			if (tx1 < tx2)
				sum += 1 / tx1;
			else
				sum += 1 / tx2;
		}
		
		if (x != e_i && x_end > e_i1 && x_end <= e_i2) {
			// D(x)=2/T(x)
			float tx1 = x - e_i;
			float tx2 = e_i1 - x;
			if (tx1 < 0)
				tx1*=-1.0;
			if (tx2 < 0)
				tx2*=-1.0;
			if (tx1 < tx2)
				sum += 2 / tx1;
			else
				sum += 2 / tx2;
		}
		
		if (x != e_i && x_end > e_i2) {
			// D(x)=1/T(x)
			float tx1 = x - e_i;
			float tx2 = e_i1 - x;
			if (tx1 < 0)
				tx1*=-1.0;
			if (tx2 < 0)
				tx2*=-1.0;
			if (tx1 < tx2)
				sum += 1 / tx1;
			else
				sum += 1 / tx2;
		}
		
		
	}	
	float relativeMeasure = sum / measure->size();
	return relativeMeasure * getParent()->getParent()->getDivisions();
}

