#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{
	Mark::Mark(int mark = 0) {
		if (0 <= mark && mark <= 100) {
			this->m_mark = mark;
			isValid = true;
		}
		else {
			cout << "Invalid";
			this->m_mark = -1;
			isValid = false;
		}
	};

	Mark::operator int () const {
		return isValid? m_mark : 0;
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
		double grade = 0.0;
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

	bool Mark::operator == (Mark& m) const {
		return this->m_mark == int(m);
	};

	bool Mark::operator != (Mark& m) const {
		return this->m_mark != int(m);
	};

	bool Mark::operator < (Mark& m) const {
		return this->m_mark < int(m);
	};

	bool Mark::operator > (Mark& m) const {
		return this->m_mark > int(m);
	};

	bool Mark::operator <= (Mark& m) const {
		return this->m_mark <= int(m);
	};

	bool Mark::operator >= (Mark& m) const {
		return this->m_mark >= int(m);
	};

	Mark& Mark::operator ++ () const {
		
	};

	Mark Mark::operator ++ (int mark) const {
		
	};

	Mark& Mark::operator -- () const {

	};

	Mark Mark::operator -- (int mark) const {


	};

}