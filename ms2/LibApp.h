
/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 25th july,2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace seneca {
    class LibApp {

        void load();
        void save();
        void search();

        bool confirm(const char* message);

        void returnPub();
        void newPublication();

        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        void checkOutPub();

    public:

        LibApp();
        ~LibApp();
        void run();

        void removePublication();


    };

}


#endif
