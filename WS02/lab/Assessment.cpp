#include <iostream>
#include "Assessment.h"

using namespace std;
namespace sdds
{
	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);
	bool read(Assessment& asmnt, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
	int read(Assessment*& aptr, FILE* fptr);

}

