/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper: public VehicleBasic {
		double m_capacity;
		double m_load; 

	public:
		Dumper();
		Dumper(char* license, int year, double capacity, char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);

	};
	std::ostream& operator << (std::ostream& os, const Dumper& D);
	std::istream& operator >> (std::istream& is, Dumper& D);
	
	
}
#endif

