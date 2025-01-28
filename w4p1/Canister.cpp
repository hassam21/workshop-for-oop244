/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 8th june,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"


using namespace std;
namespace seneca {
    const double PI = 3.14159265;
    //private
    void Canister::setToDefault() {

        m_contentName = nullptr;
        m_diameter = 10.0; // in centimeters
        m_height = 13.0;   // in centimeters
        m_contentVolume = 0.0;  // in CCs
        m_usable = true;
    }
    void Canister::setName(const char* Cstr) {
        
        if (Cstr != nullptr && m_usable) {
            delete[] m_contentName;                           
            m_contentName = nullptr;                            
            m_contentName = new char[strlen(Cstr) + 1];        
            strcpy(m_contentName, Cstr);                
        }

    }
    bool Canister::isEmpty()const {

        return (m_contentVolume < 0.00001);
    }
    bool Canister::hasSameContent(const Canister& C)const {
        

        return strcmp(m_contentName, C.m_contentName);
    }
    //--public
    Canister::Canister() {

        setToDefault();
    }
    Canister::Canister(const char* contentName) {

        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();

        if (height < 10 || diameter < 10 || height > 40 || diameter > 30) {
            m_usable = false;
        }
        else {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0;
            setName(contentName);
        }
    }
    Canister::~Canister() {
        delete[] m_contentName;
        m_contentName = nullptr;
    }
    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (hasSameContent(contentName)) {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(double quantity) {
        
        if (m_usable && quantity > 0 && ((quantity + volume()) <= capacity())) {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(Canister& C) {//I add the name Can
        
        this->setContent(C.m_contentName);
        if (C.volume() > (this->capacity() - this->volume())) {
            C.m_contentVolume -= (this->capacity() - this->volume());
            this->m_contentVolume = this->capacity();
        }
        else {
            this->pour(C.volume());
            C.m_contentVolume = 0.0;
        }
        return *this;
    }
    double Canister::volume()const {
        return m_contentVolume;


    }
    std::ostream& Canister::display()const {
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout.setf(ios::right);
            cout << m_contentVolume << "cc   " << m_contentName;
        }
        return cout;
    }
    double Canister::capacity()const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }
    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}
