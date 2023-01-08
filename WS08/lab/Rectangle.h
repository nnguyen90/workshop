#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace sdds
{
	class Rectangle :public LblShape
	{
		double m_width;
		double m_height;

		Rectangle();
		Rectangle(const char* label, double width, double height);
		void draw(std::ostream& os);
		void getSpecs(std::istream& is);
		~Rectangle();

	};


}





#endif
