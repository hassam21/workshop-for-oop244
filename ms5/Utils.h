/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 1.0
// Author	Hassam Anas
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Hassam Anas        07/25                 done
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H__
#define SENECA_UTILS_H__
#include <iostream>
namespace seneca {
    class Utils {
    public:
        size_t getInt(size_t,size_t);
        int getMemberNum();
        char getType(unsigned int);
    };
    extern Utils ut;
}
#endif // SENECA_UTILS_H__
