/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 19th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef WS8_SHAPE_H
#define WS8_SHAPE_H
#include <ostream>
#include <istream>
#include <cstring>

namespace seneca {
    class Shape {
    public:
        virtual void draw(std::ostream&) const = 0;
        virtual void getSpecs(std::istream&) = 0;
        virtual ~Shape() = default;
    };
    std::ostream& operator<<(std::ostream& os, const Shape& right);
    std::istream& operator>>(std::istream& is, Shape& right);

} // seneca

#endif //WS8_SHAPE_H
