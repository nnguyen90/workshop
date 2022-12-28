#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {
      if (validNumber(number) && validBalance(balance))
      {
         m_number = number;
         m_balance = balance;
      }
      else {
         setInValid();
      }
   }
   std::ostream& Apartment::display() const
   {
      if (this->isActive())
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   };

   bool Apartment::isActive() const {
       return (this->m_number >= 1000 && this->m_number <= 9999
           && this->m_balance >= 0.0);
   };

   bool Apartment::validNumber(int number) const {
       return (number >= 1000 && number <= 9999);
   };

   bool Apartment::validBalance(double balance) const {
       return (balance >= 0.0);
   };

   void Apartment::setInValid() {
       this->m_number = -1; 
       this->m_balance = 0.0;           
   };

   Apartment::operator bool() const {
       return (this->isActive() == true);
   };
   Apartment::operator int() const {
        return this->m_number;
   };
   Apartment::operator double() const {
        return this->m_balance;
   };
   bool Apartment::operator~() const {
        return (this->m_balance < 0.00001);
   };

   Apartment& Apartment::operator = (const int number) {
       if (this->isActive() && validNumber(number)) {
          this->m_number = number;
       }
       else {
          this->setInValid();
       }
       return *this;
   };

   Apartment& Apartment::operator = (Apartment& a) {
       if (this->isActive()) {
           std::swap(this->m_number, a.m_number);
           std::swap(this->m_balance, a.m_balance);
       }   
       return *this;
   };

   Apartment& Apartment::operator += (double balance) {
       if (this->isActive() && balance >= 0.0) {
           this->m_balance += balance;
       }
       return *this;
   };

   Apartment& Apartment::operator -= (double balance) {
       if (this->isActive() && 0.0 <= balance && balance <= this->m_balance) {
           this->m_balance -= balance;
       }
       return *this;
   };

   Apartment& Apartment::operator << (Apartment& a) {
       if ((this != &a) && a.isActive() && this->isActive()) {
           this->m_balance += a.m_balance;
           a.m_balance = 0.0;
       }
       return *this;
   };

   Apartment& Apartment::operator >> (Apartment& a) {
       if ((this != &a) && a.isActive() && this->isActive()) {
           a.m_balance += this->m_balance;
           this->m_balance = 0.0;
       }
       return *this;
   };

   double operator + (const Apartment& a, const Apartment& b) {
       double sum = 0.0;
       if (a.isActive() && b.isActive()) {
           sum = a.m_balance + b.m_balance;
       }
       else {
           sum = 0.0;
       }
       return sum;
   };
   
   double operator += (double& value, const Apartment& a) {
       if (a.isActive()) {
           value += double(a);
       }
       return value;
   };


}