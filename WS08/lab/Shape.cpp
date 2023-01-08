#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds
{
	Shape::~Shape() {};
	std::ostream& operator << (std::ostream& os, Shape& S) {
		S.draw(os);
		return os;
	};

	std::istream& operator >> (std::istream& is, Shape& S) {
		S.getSpecs(is);
		return is;
	};
}