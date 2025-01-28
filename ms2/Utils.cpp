
/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 25th july,2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <cstring>
#include "Utils.h"
using namespace std;

namespace seneca {


    int getInt(int minRange, int maxRange, const char* errorMessage) {
        int selectedItem = 0;
        bool trueInt = false;
        while (trueInt == false)
        {
            cin >> selectedItem;
            if (cin.fail() || selectedItem < minRange || selectedItem > maxRange)
            {
                cout << errorMessage;
                cin.clear();
                cin.ignore(1000, '\n');
                trueInt = false;
            }
            else
            {
                trueInt = true;
            }

        }
        return selectedItem;
    };
}
