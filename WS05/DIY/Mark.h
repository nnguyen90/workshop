

namespace sdds
{
	class Mark
	{
	public:
		int m_mark = 0;
		bool isValid;

		Mark (int mark);
		operator int() const;
		operator double() const;
		operator char() const;
		operator bool() const;
		bool operator == (Mark& m) const;
		bool operator != (Mark& m) const;
		bool operator < (Mark& m) const;
		bool operator > (Mark& m) const;
		bool operator <= (Mark& m) const;
		bool operator >= (Mark& m) const;

		Mark& operator ++ () ;
		Mark operator ++ (int mark) ;
		

		Mark operator -- (int mark) ;
		Mark& operator -- () ;


	};
}