/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 12th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Truck.h"

using namespace std;
namespace seneca {
	Truck::Truck(const char* licens, int year, double max, const char* addr) :MotorVehicle(licens, year) {
		m_curr = 0;
		m_max = max;
		moveTo(addr);



	}

	bool Truck::addCargo(double cargo) {
		if ((m_curr+cargo) < m_max) {
			m_curr +=cargo;
			return true;
		}
		else if (m_curr == m_max) {
			return false;
		}
		else if((m_curr+cargo)>m_max){
			m_curr = m_curr + (m_max - m_curr);
			return true;
		}
		
		
		return false;

	}
	bool Truck::unloadCargo() {
		if (m_curr != 0) {
			m_curr = 0;
			return true;
		}

		return false;



	}

	ostream& Truck::write(ostream& os) {
		MotorVehicle::write(os) << " | " << m_curr << "/" << m_max;
		return os;
	}
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		cin >> m_max;
		cout << "Cargo: ";
		cin >> m_curr;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, Truck& tr) {
		return tr.write(os);
	}
	std::istream& operator>>(std::istream& is, Truck& tr) {
		return tr.read(is);

	}
}