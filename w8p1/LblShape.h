/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 19th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef WS8_LBLSHAPE_H
#define WS8_LBLSHAPE_H
#include "Shape.h"

namespace seneca {
    class LblShape :public Shape {
        char* m_label{};
    protected:
        char* label()const;
    public:
        LblShape() = default;
        LblShape(const std::string);
        virtual ~LblShape();
        void getSpecs(std::istream& istr);
    };

}
#endif //WS8_LBLSHAPE_H
