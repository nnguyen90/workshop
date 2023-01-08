#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

#include "LblShape.h"
#include "Rectangle.h"

using namespace std;
namespace sdds
{
	Rectangle::Rectangle():LblShape() {
		m_width = 0;
		m_height = 0;
	};
	Rectangle::Rectangle(const char* label, double width, double height) : LblShape(label) {
		m_width = width;
		m_height = height;
		
		if (m_height < 3 || m_width < strlen(label + 2)) {
			m_width = 0;
			m_height = 0;
		}
	};
	void Rectangle::draw(std::ostream& os) {
		if (m_width != 0 && m_height != 0) {
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '+' << endl;

			os << '|';
			os.width(m_width - 2);
			os.fill(' ');
			os.setf(ios::left);
			os << label();
			os.unsetf(ios::left);
			os << '|' << endl;

			for (int i = 0; i < m_height - 4; i++) {
				os << '|';
				os.width(m_width - 2);
				os.fill(' ');
				os << '|' << endl;
			}
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '+' << endl;
		}
	
	};

	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		is.ignore(1000, '\n');
	};
	



}
