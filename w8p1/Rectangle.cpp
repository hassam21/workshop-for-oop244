/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 19th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Rectangle.h"
#include <cstring>
#include <iomanip>
using namespace seneca;
using namespace std;
namespace seneca {
    Rectangle::Rectangle(string label, size_t width, size_t height) : LblShape(label), m_height(height), m_width(width) {
        if (m_height < 3 || m_width < (strlen(label.c_str())) + 2) {
            m_width = 0;
            m_height = 0;
        }
    }
    void Rectangle::getSpecs(std::istream& istr) {
        LblShape::getSpecs(istr);
        istr >> m_width;
        istr.ignore(1, ',');
        istr >> m_height;
        istr.ignore(1000, '\n');
    }

    void Rectangle::draw(std::ostream& os) const {
        if (m_width > 0 && m_height > 0 && label() != nullptr) {
            
            os << "+" << std::string(m_width - 2, '-') << "+" << endl;
            
            os << "|" << left << setw((int)m_width - 2) << label() << "|" << endl;
            
            for (size_t i = 0; i < m_height - 3; ++i) {
                os << '|' << string(m_width - 2, ' ') << '|' << endl;
            }
            //END
            os << '+' << string(m_width - 2, '-') << '+';
        }
    }

}