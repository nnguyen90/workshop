#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
 
   public:
      Numbers();
      Numbers(const char* filename); 
      Numbers(const Numbers& N);
      Numbers& operator = (const Numbers& N);
      Numbers operator-()const;
      Numbers operator-()const;
      Numbers operator+()const;

      double average()const;
      double max()const;
      double min()const;
      ~Numbers();

      Numbers& sort();
      int numberCount() const;
      bool load();
      void save();
      Numbers& operator +=(double val);
      std::ostream& display(std::ostream& ostr) const;

   };

   ostream& operator<<(ostream& os, const Numbers& N);
   istream& operator>>(istream& istr, Numbers& N);


}
#endif // !SDDS_NUMBERS_H_

