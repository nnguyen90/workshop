#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

#include "LblShape.h"


using namespace std;
namespace sdds
{
	const char* LblShape::label() const {
		return m_label;
	};
	LblShape::LblShape() {
		m_label = nullptr;
	};

	LblShape::LblShape(const char* label) {
		m_label = nullptr;
		int len = (int)strlen(label);
		m_label = new char [len + 1];
		strcpy(m_label, label);
	};

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	};

	void LblShape::getSpecs(std::istream& is) {
		char label[100];
		is.get (label, 100, ',');
		is.ignore(1000, ',');
		delete[] m_label;
		m_label = new char [strlen(label) + 1];
		strcpy (m_label, label);
	};
}