/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 12th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "MotorVehicle.h"
using namespace std;
namespace seneca {

	MotorVehicle::MotorVehicle(const char* license, int yr) {
		strncpy(m_addr, "Factory", 63);
		m_addr[63] = '\0';
		
		m_year = yr;

		strcpy(m_license,license);
		m_license[8] = '\0';


	}

	void MotorVehicle::moveTo(const char* address) {
		if (address != nullptr && strcmp(m_addr, address) != 0) {//the content of address is different
			cout << "|"
				<< setw(8) << right
				<< m_license
				<< "| |"
				<< setw(20) << m_addr
				<< " ---> "
				<< setw(20) << left << address
				<< "|" << endl;
			strncpy(m_addr, address, 64);
			m_addr[63] = '\0';
		}

	}

	ostream& MotorVehicle::write(ostream& os)const {
		cout << "| " << m_year << " | " << m_license << " | " << m_addr;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		cin >> m_year;
		cout << "License plate: ";
		cin >> m_license;
		cout << "Current location: ";
		cin >> m_addr;
		return in;
	}


	std::ostream& operator<<(std::ostream& os, const MotorVehicle& M) {
		return M.write(os);
	}
	std::istream& operator>>(std::istream& is, MotorVehicle& M) {
		return M.read(is);
	}



}
