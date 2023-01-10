#include <iostream>
#include "HtmlText.h"

using namespace std;
namespace sdds
{
	HtmlText::HtmlText() {};
	HtmlText::HtmlText(HtmlText& H) {};
	HtmlText& HtmlText::operator = (const HtmlText& H) {};
	HtmlText::~HtmlText() {};
	
	std::ostream& HtmlText::write(std::ostream& os) const {};



}