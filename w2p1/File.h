/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 23rd may,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/




#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
 
   bool read(char* name);
   bool read(int& empNo);
   bool read(double& salary);
}
#endif // !SENECA_FILE_H_
