#ifndef part_class_h
#define part_class_h

#include "lesson.h"

// Forward declarations
class Voice;
class Lesson;

class Part {
	public:
		Part();
		Part(int);
		void addVoice(Voice*);
		int getNumVoices();
		Voice* getVoice(int);
		void setParent(Lesson*);
		Lesson* getParent();
		string toString();
	private:
		vector<Voice*> voices_;
		Lesson* parent_;
};


#endif
