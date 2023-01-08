#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"

namespace sdds
{
	class Line: public LblShape
	{
		double m_length;

		Line();
		Line(double length, char* label);
		void draw(std::ostream& os) = 0;
		void getSpecs(std::istream& is) = 0;
		~Line();
	};
	std::ostream& operator << (std::ostream& os, Shape& S);
	std::istream& operator >> (std::istream& os, Shape& S);

}


#endif SDDS_LINE_H