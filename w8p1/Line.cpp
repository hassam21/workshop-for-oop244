/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 19th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Line.h"
using namespace seneca;
using namespace std;
namespace seneca {
    Line::Line(string label, size_t length) : LblShape(label), m_length(length) {
    }

    void Line::getSpecs(std::istream& istr) {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(1000, '\n');
    }

    void Line::draw(ostream& os) const {
        if (m_length > 0 && label() != nullptr) {
            os << label() << endl;
            for (size_t i = 0; i < m_length; ++i) {
                os << "=";
            }
        }
    }

}