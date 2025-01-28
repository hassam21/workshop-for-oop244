/****************************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 25th july,2024

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
******************************************************************************/
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

namespace seneca {
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& os)const = 0; // pure
        virtual std::ostream& read(std::istream& is) = 0; // pure
        virtual bool conIO(std::ios& io)const = 0; // pure
        virtual operator bool()const = 0; // pure
        virtual ~Streamable() {};
        
    };

    std::ostream& operator<<(std::ostream& os, const Streamable& obj);
    std::istream& operator>>(std::istream& is, Streamable& obj);
}

#endif
