
/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 23rd may,2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Bill.h"
#include "Item.h"

namespace seneca {

    void Bill::setEmpty() {
        m_title[0] = '\0';
        delete[] m_items;
        m_items = nullptr;
    }

    bool Bill::isValid() const {
        if (m_title[0] == '\0') {
            return false;
        }

        for (int i = 0; i < m_noOfItems; ++i) {
            if (!m_items[i].isValid()) {
                return false;
            }
        }

        return true;
    }

    double Bill::totalTax() const {
        double totalTax = 0.0;
        for (int i = 0; i < m_noOfItems; ++i) {
            totalTax += m_items[i].tax();
        }
        return totalTax;
    }

    double Bill::totalPrice() const {
        double totalPrice = 0.0;
        for (int i = 0; i < m_noOfItems; ++i) {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    }

    void Bill::Title() const {
        std::cout << "+--------------------------------------+" << std::endl;
        if (isValid()) {

            int spaces = 36 - (strlen(m_title));

            // Output the formatted string
            std::cout << "| " << m_title;
            for (int i = 0; i < spaces; ++i) {
                std::cout << " ";
            }
            std::cout << " |" << std::endl;
            std::cout << "+----------------------+---------+-----+" << std::endl;
            std::cout << "| Item Name            | Price   + Tax |" << std::endl;
            std::cout << "+----------------------+---------+-----+" << std::endl;
        }
        else {
            std::cout << "| Invalid Bill                         |" << std::endl;
            std::cout << "+----------------------+---------+-----+" << std::endl;
            std::cout << "| Item Name            | Price   + Tax |" << std::endl;
            std::cout << "+----------------------+---------+-----+" << std::endl;
        }
    }

    void Bill::footer() const {
        std::cout << "+----------------------+---------+-----+" << std::endl;
        if (isValid()) {
            std::cout << "|                Total Tax: "
                << std::right << std::setw(10) << std::fixed << std::setprecision(2) << totalTax()
                << " |" << std::endl;

            // Output Total Price
            std::cout << "|              Total Price: "
                << std::right << std::setw(10) << std::fixed << std::setprecision(2) << totalPrice()
                << " |" << std::endl;

            // Output Total After Tax
            std::cout << "|          Total After Tax: "
                << std::right << std::setw(10) << std::fixed << std::setprecision(2) << (totalTax() + totalPrice())
                << " |" << std::endl;
            std::cout << "+--------------------------------------+" << std::endl;
        }
        else {
            std::cout << "| Invalid Bill                         |" << std::endl;
            std::cout << "+--------------------------------------+" << std::endl;

        }
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
        }
        else {
            strncpy(m_title, title, 36);
            m_title[36] = '\0';

            m_noOfItems = noOfItems;
            m_itemsAdded = 0;

            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; ++i) {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            ++m_itemsAdded;
            return true;
        }
        return false;
    }

    void Bill::display() const {
        Title();
        for (int i = 0; i < m_noOfItems; ++i) {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }

}