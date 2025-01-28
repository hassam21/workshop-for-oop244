/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 11th june,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const {
       return m_number >=10000&&m_number<=99999&&  m_balance >= 0;
   }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }


   bool Account::operator ~() const{
       return m_number == 0;

   }

   Account& Account::operator=(int number) {
       if (m_number == 0) { // Check if account is new
           if (number >= 10000 && number <= 99999) {
               m_number = number;
           }
           else {
               m_number = -1; // Invalid account number
               m_balance = 0.0;
           }
       }
       return *this; // Return reference to the current object


   }

   Account& Account::operator=(Account& other) {
       if (m_number == 0 && other.m_number!=-1){
           m_balance = other.m_balance;
           other.m_balance = 0;
           m_number = other.m_number;
           other.m_number = 0;
        }
       return *this;
        
   }
   //considered valid if the account number is a 5 digit integer with a zero or positive balance.
   Account& Account::operator+=(double num) {
       if (m_number != -1 && num>=0) {
           m_balance += num;
       }
       return *this;


   }

   Account& Account::operator-=(double num2) {
       if (m_number!=-1 && num2<=m_balance&& num2>=0) {
           m_balance -= num2;
       }
       return *this;


   }

   Account& operator<<(Account& left,Account& right) {
       if(left.m_number!=right.m_number){
           left.m_balance = +right.m_balance;
           right.m_balance = 0;
       }
       return left;


   }

   Account& operator>>(Account& left1, Account& right1) {
       if (left1.m_number != right1.m_number) {
           right1.m_balance+=left1.m_balance;
           left1.m_balance = 0;
       }
       return right1;


   }

   double operator+(const Account& lf, const Account& rh) {
       if (lf.m_number == -1 || rh.m_number == -1) {
           return 0;

       }
       else {
           return lf.m_balance + rh.m_balance;

       }

   }

   double operator+=(double& op, const Account& rh) {
       if (rh.m_number !=  -1) {
           op += rh.m_balance;

           

       }
       return op;

   }


}