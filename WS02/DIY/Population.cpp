#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {
	extern FILE* fptr;
	Population* pp = nullptr;
	int size;
	bool load(const char* file_name) {
		bool res = false;
		if (openFile(file_name)) {
			 size = noOfRecords();
			if (size > 0) {
				pp = new Population[size];
				for (int i = 0; i < size; i++) {
					fscanf(fptr, "\n%3[^,]\n", pp[i].postal_code);
					fscanf(fptr, ",%d[^\n]", &pp[i].population);
				}
				res = true;
			}
			else {
				cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
				res = false;
			}
		}
		else {
			cout << "Could not open data file: " << file_name << endl;
			res = false;
		}
		return res;
	}

	void display() {
		cout << "Postal Code: population\n";
		cout <<"-------------------------\n";
		int sum = 0;
		int temp;
		for (int i = 0; i < size; i++) {		
			 for (int j = 0; j )


			cout << i + 1 <<"- " << pp[i].postal_code << ":" << pp[i].population << endl;			
			sum += pp[i].population;
		} 
	
		cout << "-------------------------\n";
		cout << "Population of Canada: " << sum << endl;
	}

	void deallocateMemory() {
		delete [] pp;
		pp = nullptr;
	}

}