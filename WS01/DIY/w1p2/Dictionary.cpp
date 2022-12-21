#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

#include "Dictionary.h"


using namespace std;
namespace sdds
{
	
	int LoadDictionary(const char* filename) {

		
		FILE* fp = fopen(filename, "r");
		Dictionary dictionary;
		dictionary.size = 0;

		if (!fp) {
			return 1;
		}
		else {
			int i;
			while (!EOF) {
				int j;
				fscanf(fp, "%64[^\n]", dictionary.words[i].word[j]);

			}
			
			

		}

	}



}