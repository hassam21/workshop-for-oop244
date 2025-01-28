/****************************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 03rd August,2024

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
******************************************************************************/
#ifndef SENECA_UTILS_H__
#define SENECA_UTILS_H__
#include <iostream>
namespace seneca {
    class Utils {
    public:
        size_t getInt(size_t,size_t);
        void getCstr( char* str, size_t len );
    };
    extern Utils ut;
}
#endif // SENECA_UTILS_H__
