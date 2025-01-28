
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Item.h"

namespace seneca {

    void Item::setName(const char* name) {
        
        
            strncpy(m_itemName, name, 20);
            m_itemName[20] = '\0';

        
    }

    void Item::setEmpty() {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }

    void Item::set(const char* name, double price, bool taxed) {

        if (price < 0 || name == nullptr) {
            setEmpty();
        }
        else{
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const {
        if (m_taxed) {
            return m_price * 0.13;
        }
        else {
            return 0.0;
        }
    }

    bool Item::isValid() const {
        return (m_price != 0.0 && m_itemName[0] != '\0');
    }

    void Item::display() const {
        if (isValid()) {
            /*std::cout << "| "
                << std::left << std::setw(20) << std::setfill('.') << m_itemName
                << " | "
                << std::right << std::setw(7) << std::setfill(' ') << std::setprecision(5) << m_price
                << " | "
                << (m_taxed ? "Yes" : "No ")
                << " |" << std::endl;*/

                // Left-justify m_itemName in a field of 20 characters padded with '.'
            std::cout << "| " << m_itemName;
            int dotCount = 20 - strlen(m_itemName);
            for (int i = 0; i < dotCount; ++i) {
                std::cout << ".";
            }

            // Right-justify m_price in a field of 7 characters with 5 digits after the decimal point
            std::cout << " | ";
            std::cout.width(7);
            std::cout.fill(' ');
            std::cout.precision(2);
            std::cout << std::fixed << std::right << m_price;

            // Print "Yes" or "No" based on m_taxed
            std::cout << " | " << (m_taxed ? "Yes" : "No ") << " |" << std::endl;
        }
        else {
            std::cout << "| "
                << std::left << std::setw(20) << std::setfill('x') << std::string(20, 'x')
                << " | "
                << std::right << std::setw(7) << std::string(7, 'x')
                << " | "
                << std::setw(3) << std::string(3, 'x')
                << " |" << std::endl;
        }
    }
}