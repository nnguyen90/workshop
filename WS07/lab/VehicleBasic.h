/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	const int MAX_LICENSE_LEN = 9;
	const int MAX_ADDRESS_LEN = 64;

	class VehicleBasic
	{
		char m_license[MAX_LICENSE_LEN] {};
		char m_address[MAX_ADDRESS_LEN] {};
		int m_year ;

	public:
		VehicleBasic();
		VehicleBasic(const char* license, int year);
		void NewAddress(const char* address);
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	
	};
	std::ostream& operator << (std::ostream& os, VehicleBasic& V);
	std::istream& operator >> (std::istream& is, VehicleBasic& V);

}

#endif

