/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 12th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef TRUCK_H_
#define TRUCK_H_
#include <iostream>
#include "MotorVehicle.h"
namespace seneca {
	class Truck : public MotorVehicle {
		double m_max{};
		double m_curr{};

	public:
		Truck(const char* licens, int year, double max, const char* addr);
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os);
		istream& read(istream& in);


	};
	ostream& operator<<(ostream& os, Truck& tr);
	istream& operator>>(istream& is, Truck& tr);
}




#endif