#include <iostream>
#include <cstring>
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
		m_content = nullptr;
	};
	Text::Text(Text& T) {
			this->m_content = new char[strlen(T.m_content) + 1];
			strcpy (this->m_content, T.m_content);
	};

	Text& Text::operator = (const Text& T) {
		if (this != &T) {
			delete[] m_content;
			this->m_content = new char[strlen(T.m_content) + 1];
			strcpy(this->m_content, T.m_content);
		}
		return *this;
	};

	Text::~Text() {
		delete[] m_content;
		m_content = nullptr;
	};

	std::istream& Text::read(std::istream& is) {
		delete[] m_content;
		m_content = nullptr;
		int len = (int)getFileLength(is);
		this->m_content = new char [len + 1];
		int i = 0;
		while (!is.eof()) {
			is >> std::noskipws >> m_content[i];
			if (is.fail()) {
				break;
			}
			else {
				i++;
			}
		}
		m_content[i] = '\0';
		if (i > 0) {
			is.clear();
		}
		return is;
	};

	std::ostream& Text::write(std::ostream& os) const {
		if (this->m_content != nullptr) {
			os << this->m_content;
		}
		return os;
	};
	
	unsigned Text::getFileLength(istream& is) {
		unsigned len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// tell what is the positions (end position = size)
			len = unsigned(is.tellg());
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}

	std::istream& operator >> (std::istream& is, Text& T) {
		return T.read(is);
	};


	std::ostream& operator << (std::ostream& os, Text& T) {
		return T.write(os);
	};
}

