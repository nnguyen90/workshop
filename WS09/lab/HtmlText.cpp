#include <iostream>
#include <cstring>
#include "HtmlText.h"

using namespace std;
namespace sdds
{
	HtmlText::HtmlText() {
		m_title = nullptr;
	};

	HtmlText::HtmlText(char* title) {
		if (title != nullptr) {
			strcpy (m_title, title);
		}
	};

	HtmlText::HtmlText(HtmlText& H) {
		this->m_title = new char[strlen(H.m_title) + 1];
		strcpy(this->m_title, H.m_title);
	
	};

	HtmlText& HtmlText::operator = (const HtmlText& H) {
		if (this != &H) {
			delete[] m_title;
			this->m_title = new char[strlen(H.m_title) + 1];
			strcpy(this->m_title, H.m_title);
		}
		return *this;
	};


	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	};
	
	std::ostream& HtmlText::write(std::ostream& os) const {
		bool MS = false;
		os << "<html><head><title>";
		if (m_title != nullptr) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			os << "<h1>" << m_title << "</h1>\n";
		}
		int i = 0;
		while((*this)[i] != '\0'){
			char c = (*this)[i];
			switch(c){
				case ' ':
					if(MS) os << "&nbsp;";
					else{
						MS = true;
						os << " ";
					}
					break;
				case '<':
					os << "&lt;";
					MS = false;
					break;
				case '>':
					os << "&gt;";
					MS = false;
					break;
				case '\n':
					os << "<br />\n";
					MS = false;
					break;
				default:
					os << c;
					MS = false;
					break;
			}
			i++;
		}
		return os;
	};



}