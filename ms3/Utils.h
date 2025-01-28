/****************************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 25th july,2024

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
******************************************************************************/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace seneca {
  class Utils {
    public:
      Utils() = delete;
    static void getChar(std::istream & is, char ch); //extract a given char
    static void getChar(std::istream & is); //if next char is digit set istr fail or extract it otherwise
    static int getInt(std::istream & is, int min, int max,
      const char *
        message = nullptr); //get a int with validation and error message
    static void copyStr(char * & des,
      const char * src); //copy a string of dynamic length
    static char * readInput(std::istream & is, char delimeter = '\n'); //read a dynamic string from istr
  };
}
#endif // SDDS_UTILS_H__

