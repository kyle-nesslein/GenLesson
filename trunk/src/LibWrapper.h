#ifndef lib_wrapper_namespace_h
#define lib_wrapper_namespace_h

#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include "note.h"

// Libmusicxml2
#include "elements.h"
#include "factory.h"
#include "xml.h"
#include "xmlfile.h"

using namespace MusicXML2;
using namespace std;

// Forward declarations
//class Sxmlattribute;
//class Sxmlelement;
//class Note;

namespace LibWrapper
{
	string get_k_type(int duration, int divisions);
	Sxmlattribute newAttribute(const string& name, const string& value);
	Sxmlattribute newAttributeI(const string& name, int value);
	Sxmlelement newElement(int type, const string& value);
	Sxmlelement newElementI(int type, int value);
	string intToString(int anInt);
	int getRandomInt(int max);
	int noteToInt(Note* aNote);
	vector<Note*>* intToNotesALL(int pitch, int octave, int string, int fret);
	vector<Note*>* intToNotes(int pitch, int octave, int string, int fret);
};

#endif
