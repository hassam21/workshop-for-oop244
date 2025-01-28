
/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 23rd may,2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace seneca {
    int noOfEmployees;
    Employee* employees;

    // Sort employees by employee number
    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // Load a single employee record
    bool load(Employee& emp) {
        bool ok = false;
        char name[128];
        if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {
            int nameLength = strlen(name) + 1;
            emp.m_name = new char[nameLength];
            strcpy(emp.m_name, name);
            ok = true;
        }
        return ok;
    }

    // Load all employee records from file
    bool load() {
        bool ok = false;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (int i = 0; i < noOfEmployees; ++i) {
                if (!load(employees[i])) {
                    std::cerr << "Error: incorrect number of records read; the data is possibly corrupted." << std::endl;
                    return false;
                }
            }
            ok = true;
            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // Display a single employee's details
    void display(const Employee& emp) {
        std::cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << std::endl;
    }

    // Display all employees' details
    void display() {
        std::cout << "Employee Salary report, sorted by employee number" << std::endl;
        std::cout << "no- Empno, Name, Salary" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        sort();
        for (int i = 0; i < noOfEmployees; ++i) {
            std::cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // Deallocate dynamically allocated memory
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; ++i) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
    }
}