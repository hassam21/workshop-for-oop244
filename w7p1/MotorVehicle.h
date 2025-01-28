/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 12th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef MotorVehicle_H__
#define MotorVehicle_H__
#include <iostream>
using namespace std;
namespace seneca {
	class MotorVehicle {
		char m_license[9]; // Statically allocated array for license plate
		char m_addr[64];     // Statically allocated array for address
		int m_year;

	public:
		MotorVehicle(const char* license, int yr);
		void moveTo(const char* address);

		ostream& write(ostream& os)const;
		istream& read(istream& is);

	
	};
	ostream& operator<<(ostream& os, const MotorVehicle& mv);
	istream& operator>>(istream& is, MotorVehicle& mv);
}

#endif