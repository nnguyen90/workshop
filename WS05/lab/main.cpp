/***********************************************************************
// OOP244 Workshop 5 p1: tester program
//
// File  main.cpp
// Version 1.0
// Date  summer of 2022
// Author  Kalimullah Jawad
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2022/10/06      peer review
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Apartment.h"
using namespace std;
using namespace sdds;

void aprtmentsDisplay(const Apartment* apt, int num);
void aprtmentDisplay(const Apartment& apt);
void allApartmentsDisplay(const Apartment* apt, int num);
void balancesDisplay(const Apartment* apt, int num);
int emptyApartments(const Apartment* apt, int num);

int main() {
    double value;
    Apartment mixed[] = {
       {1111, 112.11},
       {2222, 223.22},
       {33333, 334.333}, // invalid
       {4444, 4435.44},
       {55555, 544.55},  // invalid
       {66666, 666.66},   // invalid
       {7777, 788.77}
    };
    cout << "Using bool conversion overload and operator ~ to print the apartments " << endl;
    aprtmentsDisplay(mixed, 7);
    cout << "Charging apartment #1 $50.02 using += operator:" << endl;
    aprtmentDisplay(mixed[0] += 50.02);
    cout << "Transferring $100.01 from apartment #2 using -= operator:" << endl;
    aprtmentDisplay(mixed[1] -= 100.01);
    cout << "Transferring extra amount from apartment #4 using -= operator:" << endl;
    aprtmentDisplay(mixed[3] -= 5555.55);
    cout << "Charging and transferring negative amounts on apartment #4:" << endl;
    aprtmentDisplay(mixed[3] -= -5.55);
    aprtmentDisplay(mixed[3] += -50.55);
    cout << "Info on two departments: " << endl;
    aprtmentsDisplay(mixed, 2);
    cout << "Changing the charges of apartment 1 to 2:" << endl;
    mixed[0] >> mixed[1];
    aprtmentsDisplay(mixed, 2);
    cout << "Changing the charges of aprtment 2 to 1:" << endl;
    mixed[0] << mixed[1];
    aprtmentsDisplay(mixed, 2);
    cout << "Changing charges of an apartment to itself" << endl;
    aprtmentDisplay(mixed[0] << mixed[0]);
    cout << "Combined balance of apartment 5 and 7" << endl << "   in three different ways: ";
    cout << (value = mixed[4] + mixed[6]) << ", ";
    value = 0;
    value += mixed[4];
    value += mixed[6];
    cout << value << ", and ";
    value = double(mixed[4]);
    value += double(mixed[6]);
    cout << value << endl;
    cout << "changing the apartment from Apartment #6 to Apartment #7 using operator=:" << endl;
    cout << "Before: " << endl;
    aprtmentsDisplay(&mixed[5], 2);
    mixed[6] = mixed[5];
    cout << "After: " << endl;
    aprtmentsDisplay(&mixed[5], 2);
    cout << "Displaying all apartments: " << endl;
    aprtmentsDisplay(mixed, 7);
    cout << "Changing number of aprtment #6:" << endl;
    aprtmentDisplay(mixed[5] = 12121);
    allApartmentsDisplay(mixed, 7);
    balancesDisplay(mixed, 7);
    cout << "Total of " << emptyApartments(mixed, 7) << " Invalid Apartments" << endl;
    return 0;
}

void aprtmentsDisplay(const Apartment* apt, int num) {
   cout << "+-----+------+--------------+" << endl;
   cout << "|ROW# | APT# |    BALANCE   |" << endl;
   cout << "+-----+------+--------------+" << endl;
   for(int i = 0; i < num; i++) {
      cout << "| ";
      cout.width(3);
      cout.fill('0');
      cout << (i + 1) << " | ";
      cout.fill(' ');
      apt[i].display() << "|" << endl;
   }
   cout << "+-----+------+--------------+" << endl;
}
void aprtmentDisplay(const Apartment& apt) {
   aprtmentsDisplay(&apt, 1);
}
void allApartmentsDisplay(const Apartment* apt, int num) {
   cout << "Display numbers of all the apartments " << endl;
   cout << " int conversion operator should be implemented" << endl;
   for(int i = 0; i < num; i++) {
      cout << int(apt[i]) << " ";
   }
   cout << endl;
}
void balancesDisplay(const Apartment* apt, int num) {
   cout << "Display total income balance: " << endl;
   cout << " double conversion operator should be used" << endl;
   for(int i = 0; i < num; i++) {
      cout << double(apt[i]) << " ";
   }
   cout << endl;
}

int emptyApartments(const Apartment* apt, int num) {
   int sum = 0;
   for(int i = 0; i < num; i++) {
      sum += !apt[i] && ~apt[i]; 
   }
   return sum;
}