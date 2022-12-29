#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{
	Mark::Mark() {
		m_mark = 0;
		isValid = true;
	};

	Mark::Mark(int mark) {
		if (0 <= mark && mark <= 100) {
			this->m_mark = mark;
			isValid = true;
		}
		else {
			
			this->m_mark = -1;
			isValid = false;
		}
	};

	Mark::operator int () const {
		return isValid? m_mark : -1;
	};

	Mark::operator double() const {
		double gpa = 0.0;
		if (isValid) {
			if (m_mark < 50) {
				gpa = 0.0;
			}
			else if (m_mark < 60){
				gpa = 1.0;
			}
			else if (m_mark < 70) {
				gpa = 2.0;
			}
			else if (m_mark < 80) {
				gpa = 3.0;
			}
			else if (m_mark <= 100) {
				gpa = 4.0;
			}		
		}
		return gpa;
	};

	Mark::operator char() const {
		char grade;
		if (isValid) {
			if (m_mark < 50) {
				grade = 'F';
			}
			else if (m_mark < 60) {
				grade = 'D';
			}
			else if (m_mark < 70) {
				grade = 'C';
			}
			else if (m_mark < 80) {
				grade = 'B';
			}
			else if (m_mark <= 100) {
				grade = 'A';
			}
		}
		else {
			grade = 'X';
		}
		return grade;
	};
	
	Mark::operator bool() const {
		return (this->isValid);
	};

	bool Mark::operator == (const Mark& m) const {
		return this->m_mark == int(m);
	};

	bool Mark::operator != (const Mark& m) const {
		return this->m_mark != int(m);
	};

	bool Mark::operator < (const Mark& m) const {
		return this->m_mark < int(m);
	};

	bool Mark::operator > (const Mark& m) const {
		return this->m_mark > int(m);
	};

	bool Mark::operator <= (const Mark& m) const {
		return this->m_mark <= int(m);
	};

	bool Mark::operator >= (const Mark& m) const {
		return this->m_mark >= int(m);
	};

	Mark& Mark::operator ++ (int) {      // var++
		int oldValue = -1;
		
		if (this->isValid) {			
			oldValue = this->m_mark;
			this->m_mark++;
			if (m_mark > 100) {
				//oldValue = -1;
				this->isValid = false;
			}
		}			
		Mark res(oldValue);
		return res;
	};

	Mark& Mark::operator ++ () {		  // ++var
		int newValue = -1;	
		if (this->isValid) {		
			this->m_mark++;	
			newValue = this->m_mark;
			if (m_mark > 100) {
				this->isValid = false;
			}
		}	
		Mark res(newValue);
		return res;
	};

	Mark& Mark::operator -- (int) {			// var--
		int oldValue = -1;
		if (this->isValid) {
			oldValue = this->m_mark;
			m_mark--;
			if (m_mark < 0) {
				this->isValid = false;
			}
		}
		Mark res(oldValue);
		return res;
	};

	Mark& Mark::operator -- () {			 // --var
		int newValue = -1;
		if (this->isValid) {
			this->m_mark--;
			newValue = this->m_mark;
			if (m_mark > 100 || m_mark < 0) {
				this->isValid = false;
			}
		}
		Mark res(newValue);
		return res;
	};

	bool Mark::operator ~ () {
		bool pass = false;
		if (50 <= this->m_mark && this->m_mark <= 100) {
			pass = true;
		}
		else {
			pass = false;
		}
		return pass;
	};

	Mark& Mark::operator = (int value) {
		if (value < 0 || value > 100) {
			this->m_mark = value;
			this->isValid = false;
		}
		else {
			this->m_mark = value;
			this->isValid = true;
		}
		return *this;
	};

	Mark& Mark::operator = (Mark& M) {
		if (M.isValid) {
			this->m_mark = M.m_mark;
			this->isValid = true;		
		}
		else {
			this->m_mark = M.m_mark;
			this->isValid = false;
		}
		return *this;
	};

	Mark& Mark::operator += (int value) {
		this->m_mark += value;
		if (m_mark < 0 || m_mark > 100) {
			this->m_mark = 0;
			this->isValid = false;
		}
		else {
			this->isValid = true;
		}
		return *this;
	};

	Mark& Mark::operator -= (int value) {
		this->m_mark -= value;
		if (m_mark < 0 || m_mark > 100) {
			this->m_mark = 0;
			this->isValid = false;
		}
		else {
			this->isValid = true;
		}
		return *this;

	};

	int operator += (int& value, const Mark& M) {
		if (M.isValid) {
			value += M.m_mark;
		}
		return value;
	};

	int operator -= (int& value, const Mark& M) {
		if (M.isValid) {
			value -= M.m_mark;
		}
		return value;
	};

	Mark Mark::operator + (int value) const {
		Mark res = *this;
		res.m_mark += value;
		if (res.m_mark < 0 || res.m_mark > 100) {
			res.m_mark = -1;
			res.isValid = false;
		}	
		else {
			res.isValid = true;
		}
		return res;
	};

	Mark& Mark::operator + (Mark& M) {
		if (this->isValid && M.isValid) {
			this->m_mark += M.m_mark;
			if (this->m_mark < 0 || this->m_mark > 100) {
				m_mark = 0;
				this->isValid = false;
			}
		}
		return *this;
	};

	Mark& Mark::operator << (Mark& M) {
		if (this->isValid && M.isValid) {
			this->m_mark += M.m_mark;
			M.m_mark = 0;
			if (this->m_mark < 0 || this->m_mark > 100) {			
				this->isValid = false;
			}
		}
		return * this;
	};

	Mark& Mark::operator >> (Mark& M) {
		if (this->isValid && M.isValid) {
			M.m_mark += this->m_mark;
			this->m_mark = 0;
			if (M.m_mark < 0 || M.m_mark > 100) {
				M.m_mark = 0;
				M.isValid = false;
			}
		}
		return *this;
	};

	int operator + (int& value, const Mark& M) {
		if (M.isValid) {
			value += M.m_mark;
		}
		return value;
	};
}