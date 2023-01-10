#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include <iostream>


namespace sdds
{
	class HtmlText: public Text
	{
		char* m_title;

	public:
		HtmlText();
		HtmlText(HtmlText& H);
		HtmlText& operator = (const HtmlText& H);
		~HtmlText();
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
		
	};

	

}




#endif