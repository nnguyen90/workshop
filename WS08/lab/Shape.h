#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

namespace sdds
{
	class Shape
	{
	public:
		virtual void draw (std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		~Shape();
	};
	std::ostream& operator << (std::ostream& os, Shape& S);
	std::istream& operator >> (std::istream& os, Shape& S);

}


#endif SDDS_SHAPE_H