#include <iostream>
#include "Text.h"

using namespace std;
namespace sdds
{
	const char& Text::operator[](int index) const {
		char temp;
		if (m_content != nullptr || index < strlen(m_content)) {
			temp = m_content[index];
		}
		else {
			temp = m_content[strlen(m_content)];
		}
		return temp;
	};

	Text::Text() {
		delete[] m_content;
		m_content = nullptr;
	};
	Text::Text(Text& T) {};
	Text& Text::operator = (const Text& T) {};
	Text::~Text() {};
	std::istream& Text::read(std::istream& is) {};
	std::ostream& Text::write(std::ostream& os) const {};
	unsigned Text::getFileLength(istream& is) {};

	std::istream& operator >> (std::istream& is, Text& T);
	std::ostream& operator << (std::ostream& os, Text& T);
}

