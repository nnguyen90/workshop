#include <iostream>
using namespace std;
int main() {
   cout.width(4);
   cout.fill('0');
   cout.setf(ios::right);
   cout << 32 << endl;
   cout.fill(' ');
   cout.unsetf(ios::right);

   return 0;
}