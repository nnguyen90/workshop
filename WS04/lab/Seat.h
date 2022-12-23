#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
#include <iostream>

namespace sdds {
   class Seat {
	   char* name = nullptr;
	   int m_row = 0;
	   char m_letter = 0;

	   bool validate(int row, char letter)const;
	   Seat& alAndCp(const char* str);
   public:
	   Seat& reset();
	   bool isEmpty() const;
	   bool assigned() const;
	   Seat();
	   Seat(const char* passengerName);
	   Seat(const char* passengerName, int row, char letter);
	   ~Seat();
	   Seat& set(int row, char letter);
	   int row()const;
	   char letter()const;
	   const char* passenger()const;
	   std::ostream& display(std::ostream& coutRef = std::cout)const;
	   std::istream& read(std::istream& cinRef = std::cin);

   };
}
#endif // !SDDS_SEAT_H_


