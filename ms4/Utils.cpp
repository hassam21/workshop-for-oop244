/****************************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 03rd August,2024

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
******************************************************************************/

#include <iostream>
#include "Utils.h"

using namespace std;
namespace seneca {


    size_t Utils::getInt(size_t min, size_t max) {
        size_t val{};
        cin >> val;
        while ( cin.fail() || val < min || val >max) {
            cout << "Invalid Selection, try again: ";
            cin.clear( );
            cin.ignore( 12000, '\n' );
            cin >> val;
        }
        cin.ignore( 12000, '\n' );
        return val;
    }

    void Utils::getCstr( char* str, size_t len ) {
        cin.getline( str, len + 1 );
        while ( cin.fail( ) ) {
            cin.clear( );
            cin.ignore( 12000, '\n' );
            cin.getline( str, len + 1 );
        }
    }

}