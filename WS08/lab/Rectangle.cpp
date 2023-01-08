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
		m_label = nullptr;
		int len = (int)strlen(label);
		m_label = new char[len + 1];
		strcpy(m_label, label);
	
	
	};
	void Rectangle::draw(std::ostream& os);
	void Rectangle::getSpecs(std::istream& is);
	



}
