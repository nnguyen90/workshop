/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name     : Ngoc Diem Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 29, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Utils.h"

namespace sdds {
   int strlen(const char* str) {
      int len = 0;
      while(str[len]) {
         len++;
      }
      return len;
   }
   void strcpy(char* des, const char* src, int len) {
      int i;
      for(i = 0; src[i] && (len < 0 || i < len); i++) {
         des[i] = src[i];
      }
      des[i] = 0; // turning the char array des in to a cString by null terminating it.
   }
   int strcmp(const char* s1, const char* s2) {
      int i;
      for(i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }
}