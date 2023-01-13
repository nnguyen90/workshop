#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include <iostream>
#include "Text.h"


namespace sdds
{
	class HtmlText: public Text
	{
		char* m_title;

	public:
		HtmlText();
		HtmlText(const char* title);
		HtmlText(HtmlText& H);
		HtmlText& operator = (const HtmlText& H);
		~HtmlText();
		std::ostream& write(std::ostream& os) const;
		
	};

	

}




#endif