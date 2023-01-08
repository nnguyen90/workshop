#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds
{
	Line::Line():LblShape() {
		m_length = 0;
	};

	Line::Line( const char* label,int length):LblShape(label) {
		m_length = length;
	};

	void Line::draw(std::ostream& os)const {
		if (m_length > 0 && label() != nullptr) {
			os.width(m_length);
			os.fill('=');
			os.setf(ios::left);
			os << label();
			os.unsetf(ios::left);
		}
	};

	void Line::getSpecs(std::istream& is){
		LblShape::getSpecs(is);
		is >> m_length;
		is.clear();
		is.ignore(1000, '\n');
	};
	Line::~Line() {};
}