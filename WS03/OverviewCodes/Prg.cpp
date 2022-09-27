#include <iostream>
using namespace std;

int main() {
   char* name = nullptr;
   name = new char[71];
   cout << "Enter your name: ";
   cin.getline(name, 71);
   if(cin) {
      cout << "Hello " << name << endl;
   }
   else {
      cout << "Your name is too long!" << endl;
   }
   delete[] name;
   return 0;
}