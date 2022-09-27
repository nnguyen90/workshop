
#include <iostream>
using namespace std;
int read() {
   int num{};
   bool done = false;
   cout << "Enter a number: ";
   while(!done) {
      cin >> num;
      if(cin.fail()) {
         cin.clear();
         cin.ignore(10000, '\n');
         cout << "Bad number try again: ";
      }
      else {
         done = true;
      }
   }
   return num;
}
int main() {
   int value;
   value = read();

   cout << "you enterd " << value << endl;

   return 0;
}