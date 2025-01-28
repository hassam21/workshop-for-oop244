/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 11th june,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      //type conversion operator
      operator bool() const;
      operator int() const;
      operator double() const;

      //unary member operator
      bool operator ~()const;

      //assignment operator
      Account& operator=(int number);
      Account& operator=(Account&);
      Account& operator+=(double num);
      Account& operator-=(double num2);
      
      friend Account& operator<<(Account& left, Account& right);
      friend Account& operator>>(Account& left1, Account& right1);

      friend double operator+(const Account& lf, const Account& rh);
      friend double operator+=(double&, const Account& rh);


   };

   //double operator+(const Account& lf, const Account& rh);


   
   
}
#endif // SENECA_ACCOUNT_H_