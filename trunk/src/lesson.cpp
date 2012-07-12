#include "lesson.h"
#define kPartID	"P1"

Part* Lesson::getPart() {
	return aPart_;
}

void Lesson::addPart(Part* aPart) {
	aPart_ = aPart;
}


int Lesson::getRandomDuration() {
	int denominator = 0;
	for (int i = 0; i < note_durations.size(); i++)
		denominator += note_durations_p[i];
	int randomValue = LibWrapper::getRandomInt(denominator-1);
	int sum = 0;
	for (int i = 0; i < note_durations.size(); i++) {
		sum += note_durations_p[i];
		if (randomValue < sum)
			return note_durations[i];
	}
	// Default:
	return 0; // This might be bad: what if the .fmt has a problem?
}

int Lesson::getNumVoices() {
	return num_voices;
}

int Lesson::getRandomNChordSize() {
	int denominator = 0;
	for (int i = 0; i < nchord_size_p.size(); i++)
		denominator += nchord_size_p[i];
	int randomValue = LibWrapper::getRandomInt(denominator-1);
	int sum = 0;
	for (int i = 0; i < nchord_size_p.size(); i++) {
		sum += nchord_size_p[i];
		if (randomValue < sum)
			return i;
	}
	// Default:
	return 0; // This might be bad: what if the .fmt has a problem?
}

int Lesson::getMeasureLength() {
	int beat_length = 4 * divisions / beat_type;
	int measure_length = beats * beat_length;
	return measure_length;
}

void Lesson::setLength() {
	numMeasures = LibWrapper::getRandomInt(max_num_bars - min_num_bars) + min_num_bars;
}

// Returns a random note from the key pitch set
Note* Lesson::getRandomNote() {
	int i = LibWrapper::getRandomInt(keyPitchSet.size() - 1);
	Note* randomNote = keyPitchSet[i];
	Note* aNote = new Note(randomNote->getStep(), randomNote->getOctave(), randomNote->getAlter(), randomNote->getString(), randomNote->getFret());
	return aNote;
}

int Lesson::measureEndTime(int measureNo) {
	return measureNo * getMeasureLength();
}

void Lesson::read_fmtfile(char * fmtfile){
	ifstream ifs;
	ifs.open(fmtfile);
	if(ifs.fail()){
		cout << "Fatal error! No such file!" << endl;
		exit(-1);
	}
	
	int stringNum = 1;
	char buffer[2048];
	while (ifs != NULL ) {
		ifs.getline(buffer, 2048);
		if (buffer[0] != '#' && buffer[0] != '%') { // If not a comment line
			char * id;
			char * value;
			//printf ("Splitting string \"%s\" into tokens:\n",buffer);
			id = strtok (buffer,"=");
			value = strtok (NULL, "=");
			if (id != NULL && value != NULL) {
				//printf ("id=%s\n",id);
				//printf ("value=%s\n",value);
				if (strcmp(id, "beats") == 0)
					beats = atoi(value);
				if (strcmp(id, "beat_type") == 0)
					beat_type = atoi(value);
				if (strcmp(id, "divisions") == 0)
					divisions = atoi(value);
				if (strcmp(id, "key_fifths") == 0)
					key_fifths = atoi(value);
				if (strcmp(id, "clef_sign") == 0)
					clef_sign = value[0];
				if (strcmp(id, "clef_line") == 0)
					clef_line = atoi(value);
				if (strcmp(id, "num_voices") == 0)
					num_voices = atoi(value);
				if (strcmp(id, "nchord_size_p") == 0) {
					char * new_size_p;
					new_size_p = strtok (value," ");
					while(new_size_p != NULL) {
						nchord_size_p.push_back(atoi(new_size_p));
						new_size_p = strtok (NULL," ");
					}
				}
				
				if (strcmp(id, "note_duration") == 0) {
					char * new_note_dur;
					new_note_dur = strtok (value," ");
					while(new_note_dur != NULL) {
						note_durations.push_back(atoi(new_note_dur));
						new_note_dur = strtok (NULL," ");
					}
				}
				if (strcmp(id, "note_duration_p") == 0) {
					char * new_note_dur_p;
					new_note_dur_p = strtok (value," ");
					while(new_note_dur_p != NULL) {
						note_durations_p.push_back(atoi(new_note_dur_p));
						new_note_dur_p = strtok (NULL," ");
					}
				}

				if (strcmp(id, "max_num_bars") == 0)
					max_num_bars = atoi(value);
				if (strcmp(id, "min_num_bars") == 0)
					min_num_bars = atoi(value);

				if (strcmp(id, "pitch_rule") == 0)
					strncpy(pitch_rule, value,50);
				
				if (strcmp(id, "avail_frets") == 0) {
					char * new_fret;
					new_fret = strtok (value," ");
					while(new_fret != NULL) {
						avail_frets.push_back(atoi(new_fret));
						new_fret = strtok (NULL," ");
					}
				}
				
				if (strcmp(id, "avail_strings") == 0) {
					char * new_fret;
					new_fret = strtok (value," ");
					while(new_fret != NULL) {
						avail_strings.push_back(atoi(new_fret));
						new_fret = strtok (NULL," ");
					}
				}
				
				// pitch, octave
				string stringName = "string_" + LibWrapper::intToString(stringNum);
				if (strcmp(id, stringName.c_str()) == 0) {
					vector<int>* aString = new vector<int>;
					char * new_value;
					new_value = strtok (value," ");
					while(new_value != NULL) {
						aString->push_back(atoi(new_value));
						new_value = strtok (NULL," ");
					}
					open_strings.push_back(aString);
					stringNum++;
				}
				
				if (strcmp(id, "strong_beats") == 0) {
					char * new_beat;
					new_beat = strtok (value," ");
					while(new_beat != NULL) {
						strong_beats.push_back(atoi(new_beat));
						new_beat = strtok (NULL," ");
					}
				}
			}
		}
	}
	composer = "University of Denver Guitarist’s Websight";
	instrumentName = "Guitar";
	title = "(title)_A Lesson";
	partName = "(part name)";

	ifs.close();
}




// makes the Pitch Set, accoring to avail frets, avail strings, and tuning info
void Lesson::makeMasterPitchSet() {
	for (int i = 0; i< avail_strings.size(); i++) {
		for (int j=0; j < avail_frets.size(); j++) {
			int intPitch = (open_strings[avail_strings[i]-1]->at(0) + avail_frets[j]) % 12;
			int octave = open_strings[avail_strings[i]-1]->at(1) + ((open_strings[avail_strings[i]-1]->at(0) + avail_frets[j]) / 12);
			vector<Note*>* sameNote = LibWrapper::intToNotes(intPitch, octave, avail_strings[i], j);
			while (!sameNote->empty()) {
				masterPitchSet.addNote(sameNote->back());
				//cout << sameNote->back()->toString();
				sameNote->pop_back();
				
			}
		}
	}
	
	//cout << masterPitchSet.
}

void Lesson::makeKeyPitchNames() {
	vector<Note*>* noteNames = keyPitchNames.getPitchSet();
	
	switch (key_fifths) {
		case -7:
			noteNames->push_back(new Note('C', -1000, -1, 0, 0));
			break;
		case -6:
			noteNames->push_back(new Note('G', -1000, -1, 0, 0));
			break;
		case -5:
			noteNames->push_back(new Note('D', -1000, -1, 0, 0));
			break;
		case -4:
			noteNames->push_back(new Note('A', -1000, -1, 0, 0));
			break;
		case -3:
			noteNames->push_back(new Note('E', -1000, -1, 0, 0));
			break;
		case -2:
			noteNames->push_back(new Note('B', -1000, -1, 0, 0));
			break;
		case -1:
			noteNames->push_back(new Note('F', -1000, 0, 0, 0));
			break;
		case 0:
			noteNames->push_back(new Note('C', -1000, 0, 0, 0));
			break;
		case 1:
			noteNames->push_back(new Note('G', -1000, 0, 0, 0));
			break;
		case 2:
			noteNames->push_back(new Note ('D', -1000, 0, 0, 0));
			break;
		case 3:
			noteNames->push_back(new Note ('A', -1000, 0, 0, 0));
			break;
		case 4:
			noteNames->push_back(new Note('E', -1000, 0, 0, 0));
			break;
		case 5:
			noteNames->push_back(new Note('B', -1000, 0, 0, 0));
			break;
		case 6:
			noteNames->push_back(new Note('F', -1000, 1, 0, 0));
			break;
		case 7:
			noteNames->push_back(new Note('C', -1000, 1, 0, 0));
			break;
	}
	//cout << "Added " + noteNames->back()->toString() + " as root";
	
	// Now that we have the root letter name and accidental, we need to generate the rest.
	// To get the next note:
	//		convert root note to pitch class int
	//		get all name of this note
	//		pick the one that matches the correct letter name
	char letter;
	int stepPattern[] = {2,2,1,2,2,2};
	for (int i = 1; i < 7; i++) {
		// Get root letter name
		letter = (*noteNames)[i-1]->getStep();
		// Go up a letter name
		letter = (((letter - 65) + 1) % 7) + 65;
		// Get root pitch class int, go
		int pitchclassint = LibWrapper::noteToInt((*noteNames)[i-1]);
		// Go up a the correct number of steps
		pitchclassint = (pitchclassint + stepPattern[i-1]) % 12;
		//cout << "pitch class int: " << pitchclassint << endl;
		// Get all possible note names for this pitch
		vector<Note*>* possibleNotes = intToNotes(pitchclassint, -1000, 0,0);
		// Find the note name that matches the new letter name
		while (possibleNotes->size() > 0) {
			//cout << "checking note: " << possibleNotes->back()->toString() << " against " << letter << endl;
			if (possibleNotes->back()->getStep() == letter)
				(*noteNames).push_back(possibleNotes->back());
			possibleNotes->pop_back();
		}
	}
	
	keyPitchNames.setPitchSet(*noteNames);
	
}

// makes the key pitch set: all notes and all their enharmonic names from the master pitch set
void Lesson::makeKeyPitchSet() {
	
	
	/*
	//keyPitchSet = new vector<Note*>;
	int pitchClasses[7];
	pitchClasses[0] = (key_fifths * 7) % 12;
	pitchClasses[1] = ((key_fifths * 7) + 2) % 12;
	pitchClasses[2] = ((key_fifths * 7) + 4) % 12;
	pitchClasses[3] = ((key_fifths * 7) + 5) % 12;
	pitchClasses[4] = ((key_fifths * 7) + 7) % 12;
	pitchClasses[5] = ((key_fifths * 7) + 9) % 12;
	pitchClasses[6] = ((key_fifths * 7) + 11) % 12;
    */
    
	for (int i = 0; i < masterPitchSet.size(); i++) {
		for (int j = 0; j < keyPitchNames.size(); j++) {
			if (keyPitchNames[j]->getStep() == masterPitchSet[i]->getStep() &&
				keyPitchNames[j]->getAlter() == masterPitchSet[i]->getAlter())
				keyPitchSet.addNote(masterPitchSet[i]);
		}
	}
}

/*
void Lesson::makeSimpleKeyPitchSet() {
	//simpleKeyPitchSet = new vector<Note*>;
	
	// If there's no sharps or flats, only take the natural notes.
	if (key_fifths == 0) {
		for (int i = 0; i < keyPitchSet.size(); i++) {
			if (keyPitchSet[i]->getAlter() == 0)
				simpleKeyPitchSet.addNote(keyPitchSet[i]);
		}
	}
	
	// If it is a flat key, only use flat and natural names.
	if (key_fifths < 0) {
		for (int i = 0; i < keyPitchSet.size(); i++) {
			if (keyPitchSet[i]->getAlter() == 0 || keyPitchSet[i]->getAlter() == -1)
				simpleKeyPitchSet.addNote(keyPitchSet[i]);
		}
	}
	
	// If it is a sharp key, only use sharp and natural names.
	if (key_fifths > 0) {
		for (int i = 0; i < keyPitchSet.size(); i++) {
			if (keyPitchSet[i]->getAlter() == 0 || keyPitchSet[i]->getAlter() == 1)
				simpleKeyPitchSet.addNote(keyPitchSet[i]);
		}
	}
}*/

//------------------------------------------------------------------------
Sxmlelement Lesson::makeAttributes() {
	Sxmlelement attributes = factory::instance().create(k_attributes);
	attributes->push (LibWrapper::newElementI(k_divisions, divisions));
	char string_holder[20];
	Sxmlelement time = factory::instance().create(k_time);
	snprintf(string_holder, 20, "%i", beats);
	time->push (LibWrapper::newElement(k_beats, string_holder));
	snprintf(string_holder, 20, "%i", beat_type);
	time->push (LibWrapper::newElement(k_beat_type, string_holder));
	attributes->push (time);

	Sxmlelement clef = factory::instance().create(k_clef);
	snprintf(string_holder, 20, "%c", clef_sign);
	clef->push (LibWrapper::newElement(k_sign, string_holder));
	snprintf(string_holder, 20, "%i", clef_line);
	clef->push (LibWrapper::newElement(k_line, string_holder));
	attributes->push (clef);
	
	Sxmlelement key = factory::instance().create(k_key);
	snprintf(string_holder, 20, "%i", key_fifths);
	key->push (LibWrapper::newElement(k_fifths, string_holder));
	attributes->push (key);
	
	return attributes;
}

Sxmlelement Lesson::convertPart(int numMeasures, Part* aPart) {
	Sxmlelement part = factory::instance().create(k_part);
	part->add (newAttribute("id", kPartID));
	
	// Initialize voice vector iterators:
	int nChordNo[aPart->getNumVoices()];
	for (int i = 0; i < aPart->getNumVoices(); i++)
		nChordNo[i] = 0;
	
	// For each measure,
	for (int measureNo = 1; measureNo <= numMeasures; measureNo++) {
		Sxmlelement measure = factory::instance().create(k_measure);
		measure->add (newAttributeI("number", measureNo));
		if (measureNo==1) {									//  creates specific elements of the first measure
			measure->push(makeAttributes());		// division, time, clef...
		}
		
		// For each voice,
		for (int voiceNo = 0; voiceNo < aPart->getNumVoices(); voiceNo++) {
			Voice* currentVoice = aPart->getVoice(voiceNo);
			
			// For each NChord ending before or equal to the end of the measure,
			NChord* currentNChord = currentVoice->getNChordAt(nChordNo[voiceNo]);
			while (currentNChord->getEndTime() <= measureEndTime(measureNo)) {
				// For each Note in this NChord,
				for (int noteNo = 0; noteNo < currentNChord->getNumNotes(); noteNo++) {
					Note* noteHolder = currentNChord->getNoteAt(noteNo);
					Sxmlelement note = factory::instance().create(k_note);		// creates the note
					
					if (noteNo != 0) // Then is must be have a chord tag
						note->push (LibWrapper::newElement(k_chord, ""));
					
					Sxmlelement pitch = factory::instance().create(k_pitch);	// creates a pitch
					string stepStr;
					stepStr += noteHolder->getStep();
					pitch->push (LibWrapper::newElement(k_step, stepStr));				// sets the pitch to a random value

					pitch->push (LibWrapper::newElement(k_alter, intToString(noteHolder->getAlter()))); 					// sets alteration (accidental)
					pitch->push (LibWrapper::newElementI(k_octave, noteHolder->getOctave()));		// sets the octave to a random value
					note->push (pitch);	
															// adds the pitch to the note
					int duration;
					if (nChordNo[voiceNo] == 0)
						duration = currentNChord->getEndTime();
					else {
						NChord* previousNChord = currentVoice->getNChordAt(nChordNo[voiceNo]-1);
						duration = currentNChord->getEndTime() - previousNChord->getEndTime();
					}
					note->push (LibWrapper::newElementI(k_duration, duration));	
					note->push (LibWrapper::newElement(k_type, get_k_type(duration, divisions)));				// creates the graphic elements of the note
					
					note->push (LibWrapper::newElementI(k_voice, voiceNo + 1));				// Set the voice

					// Beaming info:
					//Sxmlelement beam = factory::instance().create(k_beam);
					//beam->push (LibWrapper::newElement(k_beam, ""));
					//note->push (beam);
					//note->push (LibWrapper::newElement(k_beam,
					//cout << "adding noteNo,nchordno,voiceNo,measureNo,: " << noteNo << ", " << nChordNo[voiceNo] << ", " <<  voiceNo << ", " << measureNo << endl;
					measure->push (note);										// and finally adds the note to the measure
				}
				
				// If the NChord has no notes, then it is a rest.
				if (currentNChord->getNumNotes() == 0) {
					Sxmlelement note = factory::instance().create(k_note);		// creates the note
					note->push (LibWrapper::newElement(k_rest, ""));
					int duration;
					if (nChordNo[voiceNo] == 0)
						duration = currentNChord->getEndTime();
					else {
						NChord* previousNChord = currentVoice->getNChordAt(nChordNo[voiceNo]-1);
						duration = currentNChord->getEndTime() - previousNChord->getEndTime();
					}
					note->push (LibWrapper::newElementI(k_duration, duration));	
					note->push (LibWrapper::newElement(k_type, get_k_type(duration, divisions)));
					
					note->push (LibWrapper::newElementI(k_voice, voiceNo + 1));				// Set the voice
					measure->push (note);
				}
				
				if (nChordNo[voiceNo] + 1 == currentVoice->getNumNChords())
					break;
				nChordNo[voiceNo]++; // Iterate, next NChord for this voice
				currentNChord = currentVoice->getNChordAt(nChordNo[voiceNo]);
				
			}
			// If not the last voice, need backup tags
			if 	(voiceNo != aPart->getNumVoices()) {
				Sxmlelement backup = factory::instance().create(k_backup);
				backup->push (LibWrapper::newElementI(k_duration, getMeasureLength()) );
				measure->push (backup);
			}
		
		}
		part->push(measure);
	}
	return part;
}


//------------------------------------------------------------------------
// creates the part list element
//------------------------------------------------------------------------
Sxmlelement Lesson::makePartList() {
	Sxmlelement partlist = factory::instance().create(k_part_list);
	Sxmlelement scorepart = factory::instance().create(k_score_part);
	scorepart->add (newAttribute("id", kPartID));
	scorepart->push (LibWrapper::newElement(k_part_name, partName));
	Sxmlelement scoreinstr = factory::instance().create(k_score_instrument);
	scoreinstr->add (newAttribute("id", "I1"));
	scoreinstr->push (LibWrapper::newElement(k_instrument_name, instrumentName));
	scorepart->push (scoreinstr);
	partlist->push(scorepart);
	return partlist;
}

//------------------------------------------------------------------------
// creates the identification element
//------------------------------------------------------------------------
Sxmlelement Lesson::makeIdentification() {
	Sxmlelement id = factory::instance().create(k_identification);
	Sxmlelement encoding = factory::instance().create(k_encoding);

	Sxmlelement creator = LibWrapper::newElement(k_creator, composer);
	creator->add(newAttribute("type", "Composer"));
	id->push (creator);
	
	encoding->push (LibWrapper::newElement(k_software, "MusicXML Library v2"));
	id->push (encoding);
	return id;
}

//------------------------------------------------------------------------
// the function that creates and writes the score
//------------------------------------------------------------------------
Sxmlelement Lesson::convertToXml(Part* aPart) {
	Sxmlelement score = factory::instance().create(k_score_partwise);
	score->push (LibWrapper::newElement(k_movement_title, title));
	score->push (makeIdentification());
	score->push (makePartList());
	score->push (convertPart(numMeasures, aPart));			// Convert the part to xml and add it to the score
	return score;
}

bool Lesson::isPlayable(Part* aPart, int eventStartTime) {
	int numFrettedStrings = 0;
	int minFret = 36;
	int maxFret = 0;
	int fretRange = 0;
	int numOpenStrings = open_strings.size();
	
	bool used [numOpenStrings];
	for (int i = 0; i < numOpenStrings; i++) {
		used[i] = false;
	}
	
	// in this part:
	// for each voice:
	// find the nchord:
	// for each note, use it.
	
	for (int voiceNo = 0; voiceNo < aPart->getNumVoices(); voiceNo++) {
		Voice* aVoice = aPart->getVoice(voiceNo);
		NChord* anNChord = aVoice->getNChordWhen(eventStartTime);
		if (anNChord != NULL) {
			for (int noteNo = 0; noteNo < anNChord->getNumNotes(); noteNo++) {
				// 'use' the note
				Note* aNote = anNChord->getNoteAt(noteNo);
				int string = aNote->getString();
				if (used[string -1] == false) // If unused,
					used[string -1] = true; // Mark it used.
				else
					return false; // Used a string more than once.
				if (aNote->getFret() > maxFret)
					maxFret = aNote->getFret();
				if (aNote->getFret() < minFret)
					minFret = aNote->getFret();
			}
		}
	}
	
	for (int i = 0; i < numOpenStrings; i++) {
		if (used[i] == true)
			numFrettedStrings++;
	}
	fretRange = maxFret - minFret + 1;
	
	if (numFrettedStrings <= 1)
		return true;
		
	if(numFrettedStrings == 2) {
		if(fretRange > 5)
			return false;
		else
			return true;
	}

	if(numFrettedStrings == 3){
		if(fretRange > 4)
			return false;
		else
			return true;
	}
	else {
		if(fretRange > 3)
			return false;
		else
			return true;
	}
}

void Lesson::generate(Part* aPart) {
	int nChordNo[aPart->getNumVoices()];
	for (int i = 0; i < aPart->getNumVoices(); i++)
		nChordNo[i] = 0;	
	
	for (int voiceNo = 0; voiceNo < aPart->getNumVoices(); voiceNo++) {
		Voice* aVoice = aPart->getVoice(voiceNo);
		int currentEndTime = 0;
		int partEndTime = getMeasureLength() * numMeasures;
		
		while (currentEndTime < partEndTime) {	
			int prevEndTime = 0;
			if (aVoice->getNumNChords() == 0)
				prevEndTime = 0;
			else
				prevEndTime = aPart->getVoice(voiceNo)->getNChordAt(nChordNo[voiceNo]-1)->getEndTime();
			int duration = getRandomDuration();
			// Make sure the NChord fits in the measure!
			//cout << "timeleft" << aVoice->getTimeLeftInMeasure(mus_env) << endl;
			//cout << "prevtime" << prevEndTime << endl;

			// Possible infinite loop
			while(duration > aVoice->getTimeLeftInMeasure() || (duration + prevEndTime) > partEndTime)
				duration = getRandomDuration();

			// Create NChord with the correct end time
			NChord* aChord = new NChord(duration + prevEndTime);
			int numNotes = getRandomNChordSize();

			int noteNo = 0;
			while (noteNo < numNotes) {
				Note* aNote = getRandomNote(); // makes a new note!
				aChord->addNote(aNote);
				noteNo++;
			}
			
			
			aVoice->addNChord(aChord);
			if (!isPlayable(aPart, prevEndTime)) {
				//beatNo--;
				aVoice->deleteLastNChord();
			}
			else {
				nChordNo[voiceNo]++;
				currentEndTime+=duration;
			}
		}
	}
}

void Lesson::outputXML() {
	// Output musicXML file
	SXMLFile f = TXMLFile::create();
	f->set( new TXMLDecl("1.0", "", TXMLDecl::kNo));
	f->set( new TDocType("score-partwise"));
	f->set( convertToXml(aPart_));
	f->print(cout);
	cout << endl;
}


PitchSet Lesson::getMasterPitchSet() {
	return masterPitchSet;
}

PitchSet Lesson::getKeyPitchSet() {
	return keyPitchSet;
}
/*
PitchSet Lesson::getSimpleKeyPitchSet() {
	return simpleKeyPitchSet;
}
*/
PitchSet Lesson::getKeyPitchNames() {
	return keyPitchNames;
}

string Lesson::toString() {
	//string out = "";
	//for (int i = 0; i < parts_.size(); i++) {
//out += "Part number: " + i;
	//	out += aPart_[i]->toString();
	
	return aPart_->toString();
}

vector<int>* Lesson::getStrongBeats() {
	return &strong_beats;
}

int Lesson::getDivisions() {
	return divisions;
}

