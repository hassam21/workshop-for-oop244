/****************************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 25th july,2024

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
******************************************************************************/
#include<iostream>
#include"Streamable.h"

using namespace std;

namespace seneca {
    ostream& operator<<(ostream& os, const Streamable& obj) {
        obj.write(os);
        return os;
    }

    istream& operator>>(istream& is, Streamable& obj) {
        obj.read(is);
        return is;
    }
}
