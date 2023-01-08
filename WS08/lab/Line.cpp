#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds
{
	Line::Line():LblShape() {
		m_length = 0.0;
	};

	Line::Line(double length, char* label):LblShape(label) {
		m_length = length;
	};

	void Line::draw(std::ostream& os) {};
	void Line::getSpecs(std::istream& is)]{
		LblShape:getSpecs();
	};
	Line::~Line() {};
}