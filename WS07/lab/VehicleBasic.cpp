/*
Name:
Email:
Student ID:
Data:
Section:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	
	VehicleBasic::VehicleBasic() {
		m_license[0] = '\0';
		m_address[0] = '\0';
		m_year = 0;
	};
	VehicleBasic::VehicleBasic(const char* license, int year) {
		strcpy(m_license, license);
		m_year = year;
		strcpy (m_address, "Factory");
		
	};

	void VehicleBasic::NewAddress(const char* address) {
		if (strcmp(this->m_address,address) != 0) {
	
			cout << "|";
			cout.width(8);
			cout.fill(' ');
			cout.setf(ios::right);
			cout << m_license;
			cout.unsetf(ios::right);
			cout << "| |";
			cout.width(20);
			cout.fill(' ');
			cout.setf(ios::right);
			cout << m_address;
			cout.unsetf(ios::right);
			cout << " ---> ";

			strcpy(m_address, address);

			cout.width(20);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << address;
			cout.unsetf(ios::left);
			cout << "|" << endl;
		}
	};

	std::ostream& VehicleBasic::write(std::ostream& os) {
		os << "| " << m_year << " | " << m_license << " | " << m_address;
		return os;
	};

	std::istream& VehicleBasic::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_year;
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');

		}

		in.ignore(1000, '\n');
		cout << "License plate: ";
		in >> m_license;
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
		}

		in.ignore(1000, '\n');
		cout << "Current location: ";
		//in >> m_address;
		in.getline (m_address, 64, '\n');
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
		}
		
		in.ignore(1000, '\n');
		return in;
	};
	
	std::ostream& operator << (std::ostream& os, VehicleBasic& V) {
		V.write(os);
		return os;
	};
	std::istream& operator >> (std::istream& is, VehicleBasic& V) {
		V.read(is);
		return is;
	};
}
