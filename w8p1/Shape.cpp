/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 19th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <ostream>
#include "Shape.h"
namespace seneca {
    std::ostream& operator<<(std::ostream& os, const Shape& right) {
        right.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, Shape& right) {
        right.getSpecs(is);
        return is;
    }
} 