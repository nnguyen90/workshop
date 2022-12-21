#include <iostream>
#include <cstring>
#include "CC.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    bool CC::validate(const char* name,
        unsigned long long cardNo,
        short cvv,
        short expMon,
        short expYear)const {
        bool ok = false;
        return name != nullptr && (strlen(name) + 1) > 2 &&
            (4000000000000000 < cardNo || cardNo < 4099999999999999) &&
            (100 <= cvv && cvv <= 999) &&
            (1 <= expMon && expMon <= 12) &&
            (22 <= expYear && expYear <= 32);
    };

    void CC::prnNumber()const {
        unsigned long long temp = cardNo;
        int forth = temp % 10000;
        temp = temp /10000;
        int third = temp % 10000;
        temp = temp / 10000;
        int second = temp % 10000;
        temp = temp / 10000;
        int first = temp % 10000;
        temp = temp / 10000;

        cout << first << " " << second << " " << third << " " << forth << endl;

    };

    void CC::set() {
       name = nullptr;
       cardNo = 0;
       cvv = 0;
       expMon = 0;
       expYear = 0;
    };

    void CC::cleanUp() {
        delete [] name;
        set();
    };

    bool CC::isEmpty() const {
        return name == nullptr;
    };

    void CC::set(const char* cc_name,
        unsigned long long cc_no,
        short cvv,
        short expMon,
        short expYear) {
        this->cleanUp();
        if (validate) {
            name = new char (strlen(cc_name) + 1);
            sdds::strcpy (name, cc_name);
            cardNo = cc_no;
            this->cvv = cvv;
            this->expMon = expMon;
            this->expYear = expYear;
        }
    };

    bool CC::read() {
        cleanUp();
        cout << "Card holder name: ";
        cin.getline(name, 71, '\n');
        if (!cin.fail()) {
            cout << "Credit card number: ";
            cin >> cardNo;


        }
    };
    void CC::display(int row = 0) const {
        if (this->isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            if (row <= 0) {
                cout << "Name: " << name << endl;
                cout << "Creditcard No: " << cardNo << endl;
                cout << "Card Verification Value: " << cvv<< endl;
                cout << "Expiry Date: " << expMon << "/" << expYear << endl;
            }
        }

    };


}

