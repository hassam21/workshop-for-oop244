/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 23rd may,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/



#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace seneca {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    
   bool read(char* name) {
       return fscanf(fptr, "%[^\n]\n", name) == 1;
   }
   bool read(int& empNo) {
       return fscanf(fptr, "%d,", &empNo) == 1;
   }
   bool read(double& salary) {
       return fscanf(fptr, "%lf,", &salary) == 1;
   }
  
}