#ifndef SDDS_WORD_H
#define SDDS_WORD_H

namespace sdds
{
	const int maxDef = 8;
	const int maxDefLen = 1024;
	const int maxTypeLen = 64;

	struct Word
	{
		char* word[maxTypeLen];
		char* type[maxDef][maxTypeLen];
		char* definition[maxDefLen];
		int defNum;

	};


}






#endif

