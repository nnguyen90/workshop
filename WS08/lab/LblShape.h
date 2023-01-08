#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"

namespace sdds
{
	class LblShape: public Shape
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		LblShape(LblShape& L) = delete;
		LblShape& operator = (LblShape& L) = delete;
		//virtual void draw(std::ostream& os) = 0;
		void getSpecs(std::istream& is);
		~LblShape();
	};
	std::ostream& operator << (std::ostream& os, LblShape& S);
	std::istream& operator >> (std::istream& os, LblShape& S);

}


#endif SDDS_LBLSHAPE_H
