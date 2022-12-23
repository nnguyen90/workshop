#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Seat.h"



using namespace std;
namespace sdds {

	bool Seat::validate(int row, char letter)const {
		bool ok = false;
		if ((1 <= row && row <= 4) || (7 <= row && row <= 15) || (20 <= row && row <= 38)) {
			if (1 <= row && row <= 4) {
				if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F') {
					ok = true;
				}
			}
			else {
				if ('A' <= letter && letter <= 'F')
					ok = true;
			}
		}
		else {
			ok = false;
		}
		return ok;
	};

	Seat& Seat::alAndCp(const char* str) {
		name = nullptr;
		reset();
		if (str != nullptr && str[0] != 0) {
			if ((int)strlen(str) > 70) {
				name = new char[71];
				strncpy(name, str, 70);
			}
			else {
				name = new char[strlen(str) + 1];
				strcpy(name, str);
			}	
		}
		else {		
			reset();
		}
		return *this;
	};

	Seat& Seat::reset() {
		delete [] name;
		name = nullptr;
		m_row = 0;
		m_letter = 0;
		return *this;
	};

	bool Seat::isEmpty() const {
		return (this->name == nullptr);
	};

	bool Seat::assigned() const {
		return (validate( m_row, m_letter));
	};

	Seat::Seat() {
		name = nullptr;
		reset();

	};

	Seat::Seat(const char* passengerName) {
		alAndCp(passengerName);
		m_row = 0;
		m_letter = 0;
	};

	Seat::Seat(const char* passengerName, int row, char letter) {
		alAndCp(passengerName);
		set(row, letter);
	};

	Seat::~Seat() {
		delete[] name;
		name = nullptr;
	};
	Seat& Seat::set(int row, char letter) {
		if (validate(row, letter)) {
			this->m_row = row;
			this->m_letter = letter;
		}
		else {
			this->m_row = 0;
			this->m_letter = 0;
		}
		return *this;
	};

	int Seat::row()const {
		return (this->m_row);
	};
	char Seat::letter()const {
		return (this->m_letter);
	};

	const char* Seat::passenger()const {
		return (this->name);
	};
	std::ostream& Seat::display(std::ostream& coutRef)const {
		char* temp = nullptr;
		//int len = strlen(name);
		if (name == nullptr ) {
			coutRef << "Invalid Seat!";
		}
		else {
			if (strlen(name) > 40) {
				temp = new char[41];
				strncpy(temp, name, 40);
			}
			else {
				temp = new char[strlen(name) + 1];
				strcpy(temp, name);
			}
			coutRef.width(40);
			coutRef.fill('.');
			coutRef.setf(ios::left);
			coutRef << temp << " ";
			coutRef.unsetf(ios::left);
			coutRef.fill(' ');
			delete [] temp;
			temp = nullptr;

			if (!validate(m_row, m_letter)) {
				coutRef << "___";

			}
			else {
				coutRef << this->m_row << this->m_letter;
			}
		}
		return coutRef;
	};
	std::istream& Seat::read(std::istream& cinRef) {
		reset();
		char name[71];
		int row;
		char letter;
		cinRef.getline(name, 71, ',');
		cinRef >> row;
		cinRef >> letter;
		cinRef.ignore(1000, '\n');
		if (!cinRef.fail()) {
			alAndCp(name);
			set (row,letter);
		}
		return cinRef;
	};
}