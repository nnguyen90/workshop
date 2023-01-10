#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>


namespace sdds
{
	class Text
	{
		char* m_content;
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		Text(Text& T);
		Text& operator = (const Text& T);
		~Text();
		std::istream& read (std::istream& is);
		virtual std::ostream& write (std::ostream& os) const;	
		unsigned getFileLength(istream& is);
	};

	std::istream& operator >> (std::istream& is, Text& T);
	std::ostream& operator << (std::ostream& os, Text& T);

}




#endif