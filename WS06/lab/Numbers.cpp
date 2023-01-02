#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include <iomanip>
using namespace std;
namespace sdds
{

    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            deallocate();
            setEmpty();
            m_isOriginal = false;
        }
    }

    Numbers::Numbers(const Numbers& N) {
        int len = strlen(N.m_filename);
        this->setEmpty();
        m_isOriginal = false;
        this->m_numCount = N.m_numCount;
        this->m_filename = new char[len + 1];
        strcpy(this->m_filename, N.m_filename);
        this->m_numbers = new double[N.m_numCount];
        for (int i = 0; i < N.m_numCount; i++) {
            this->m_numbers[i] = N.m_numbers[i];
        }
    };

    Numbers& Numbers::operator = (const Numbers& N) {
        int len = strlen(N.m_filename);
        if (this != &N) {
            this->deallocate();
            this->setEmpty();
            m_isOriginal = false;
            this->m_filename = new char[len + 1];
            strcpy(this->m_filename, N.m_filename);
            this->m_numCount = N.m_numCount;
            this->m_numbers = new double[N.m_numCount];
            for (int i = 0; i < N.m_numCount; i++) {
                this->m_numbers[i] = N.m_numbers[i];
            }
        }
        return *this;
    };


    Numbers::~Numbers() {
        save();
        deallocate();
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::deallocate() {
        delete[] m_filename;
        delete[] m_numbers;
    }

    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }



    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    Numbers& Numbers::sort(bool ascending) {
        bool check = true;
        while (check) {
            check = false;
            for (int i = 0; i <= m_numCount - 2; i++) {
                if (ascending) {
                    if (m_numbers[i] > m_numbers[i + 1]) {
                        swap(m_numbers[i], m_numbers[i + 1]);
                        check = true;
                    }
                }
                else {
                    if (m_numbers[i] < m_numbers[i + 1]) {
                        swap(m_numbers[i], m_numbers[i + 1]);
                        check = true;
                    }
                }
                // n = m_numcount
                // 0 <= i <= n-1
                // 0 <= i+1 <= n-1 => -1 <= i <= n-2  => i < n-1
            }
        }
    };


    Numbers Numbers::operator-()const {
       Numbers N =  *this;
       N.sort(false);
       return N;
    }

    Numbers Numbers::operator+()const {
        Numbers N = *this;
        N.sort(true);
        return N;
    }

    int Numbers::numberCount() const {
        ifstream file(m_filename);
        int count = 0;
        if (file.is_open()) {
            char c;
            while (!file.eof()) {
                file >> c;
                if (c == '\n') {
                    count++;
                }
            }
        }
        file.close();
        return count;
    };

    bool Numbers::load() {
        ifstream file(m_filename);
        bool ok = false;
        if (file.is_open()) {
            int count = numberCount();
            this->m_numbers = new double[count];
            for (int i = 0; i < count; i++) {
                file >> this->m_numbers[i];
            }
            ok = true;
        }
        file.close();
        return ok;
    };


    void Numbers::save() {
        if (this->m_isOriginal = true && !(this->isEmpty())) {
            ofstream file(m_filename);
            if (file) {
                for (int i = 0; i < this->m_numCount; i++) {
                    file << m_numbers[i] << endl;
                }
            }
            file.close();
        }
    };

    Numbers& Numbers::operator +=(double val) {
        double* temp = new double [m_numCount + 1];
        for (int i = 0; i < m_numCount; i++) {
            temp[i] = this->m_numbers[i];
        }
        temp[m_numCount] = val;
        delete[] m_numbers;
        m_numbers = temp;
        m_numCount++;
        return *this;
    };

    std::ostream& Numbers::display(std::ostream& ostr) const {
        if (this->isEmpty()) {
        }
        else {
            ostr << "=========================" << endl;
            if (this->m_isOriginal) {
                ostr << m_filename << endl;
            }
            else {
                ostr << "*** COPY ***" << endl;
                for (int i = 0; i < m_numCount; i++) {
                    ostr << m_numbers << ", ";
                }
                ostr << endl;
                ostr << "-------------------------" << endl;
                ostr << "Total of" << m_numCount << " number(s)" << endl;
                ostr << "Largest number: " << fixed << setprecision(2) << max();
                ostr << "Smallest number: " << fixed << setprecision(2) << min();
                ostr << "Average: " << fixed << setprecision(2) << average();
                ostr << "=========================";
            }
        }
        return ostr;
    };


    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    };

    istream& operator>>(istream& istr, Numbers& N) {
        double temp;
        istr >> temp;
        if (!istr.fail()) {
            N += temp;
        }
        return istr;
    };

}
