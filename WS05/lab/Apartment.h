
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
     
   public:
       int m_number = -1;
       double m_balance = 0.0;

      Apartment(int number, double balance);
      std::ostream& display()const;
      bool isActive () const;
      bool validNumber (int number) const;
      bool validBalance(double balance) const;
      void setInValid();
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      Apartment& operator = (const int number);
      Apartment& operator = (Apartment& a);
      Apartment& operator += (double balance);
      Apartment& operator -= (double balance);
      Apartment& operator << (Apartment& a);
      Apartment& operator >> (Apartment& a);

      
   };
   double operator + (const Apartment& a, const Apartment& b);
   double operator += (double& value, const Apartment& a);
}

#endif // SDDS_APARTMENT_H_