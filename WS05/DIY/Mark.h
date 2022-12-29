

namespace sdds
{
	class Mark
	{
	public:
		int m_mark = 0;
		bool isValid;

		Mark ();
		Mark (int mark);
		operator int() const;
		operator double() const;
		operator char() const;
		operator bool() const;
		bool operator == (const Mark& m) const;
		bool operator != (const Mark& m) const;
		bool operator < (const Mark& m) const;
		bool operator > (const Mark& m) const;
		bool operator <= (const Mark& m) const;
		bool operator >= (const Mark& m) const;

		Mark& operator ++ (int) ;
		Mark& operator ++ () ;
		
		Mark& operator -- (int) ;
		Mark& operator -- () ;

		bool operator ~ ();
		Mark& operator = (int);
		Mark& operator = (Mark& M);

		Mark& operator += (int);
		Mark& operator -= (int);

		Mark operator + (int value) const ;
		Mark& operator + (Mark& M);
		Mark& operator << (Mark& M);
		Mark& operator >> (Mark& M);
	};
	int operator += (int& value, const Mark& M);
	int operator -= (int& value, const Mark& M);
	int operator + (int& value, const Mark& M);
}