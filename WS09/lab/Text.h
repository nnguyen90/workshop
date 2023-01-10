#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

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
		std::ostream& write (std::ostream& os);
		std::istream& operator >> (std::istream& is) const;
		std::ostream& operator << (std::ostream& os);

	};


}




#endif