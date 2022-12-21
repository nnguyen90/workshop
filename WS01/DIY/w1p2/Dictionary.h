#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include "Word.h"

namespace sdds
{
	const int wordNum = 100;

	struct Dictionary
	{
		Word words [wordNum];
		int size = 0;
				
	};

	int LoadDictionary(const char* filename);
	void SaveDictionary(const char* filename);
	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
	int UpdateDefinition(const char* word, const char* type, const char* definition);

}


#endif

