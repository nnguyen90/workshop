/*
Name:
Email:
Student ID:
Data:
Section:
*/
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	
	Dumper::Dumper() {
		m_capacity = 0.0;
		m_load = 0.0;
	};
	Dumper::Dumper(const char* license, int year, double capacity, const char* address):VehicleBasic (license, year) {
		m_capacity = capacity;
		m_load = 0.0;
		this->NewAddress(address);
	};

	bool Dumper::loaddCargo(double cargo) {
		bool ok = false;
		if (this->m_load + cargo <= this->m_capacity) {
			this->m_load += cargo;
			ok = true;
		}
		else {
			ok = false;
		}
		return ok;
	};

	bool Dumper::unloadCargo() {
		bool ok = false;
		if (this->m_load > 0) {
			m_load = 0;
			ok = true;
		}
		else {
			ok = false;
		}
		return ok;
	};
	std::ostream& Dumper::write(std::ostream& os) {
		VehicleBasic::write(os);
		os << " | " << m_load << "/" << m_capacity;
		return os;
	};

	std::istream& Dumper::read(std::istream& in) {
		VehicleBasic::read(in);
		std::cout << "Capacity: ";
		in >> m_capacity;
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');

		}
		in.ignore(1000, '\n');
		std::cout << "Cargo: ";
		in >> m_load;
		if (in.fail()) {
			in.clear();
			in.ignore(1000, '\n');
		}

		return in;
	};
	
	std::ostream& operator << (std::ostream& os, Dumper& D) {
		D.write(os);
		return os;
	};
	std::istream& operator >> (std::istream& is, Dumper& D) {
		D.read(is);
		return is;
	
	};
}

