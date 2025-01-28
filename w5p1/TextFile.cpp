/*
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 5th july,2024


I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/






#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"


using namespace std;
namespace seneca {
   Line::operator const char* () const {
      return m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1];
      strcpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
      m_value = nullptr;
   }

   void TextFile::setEmpty() {
       if (m_textLines != nullptr) {
           delete[] m_textLines;
           m_textLines = nullptr;
       }

       if (m_filename != nullptr) {
           delete[] m_filename;
           m_filename = nullptr;
       }
       m_noOfLines = 0;

   }

   void TextFile::setFilename(const char* fname, bool isCopy) {
       if (m_filename != nullptr) {
           delete[] m_filename;
           m_filename = nullptr;
       }

       if (isCopy) {
           m_filename = new char[strlen(fname)+3];
           strcpy(m_filename, "C_");
           strcat(m_filename, fname);
           
       }
       else {
           m_filename = new char[strlen(fname) + 3];
           strcpy(m_filename, fname);

       }
   }

   void TextFile::setNoOfLines() {
       ifstream fin;
       fin.open(m_filename);
       if(fin.is_open()){

           int lineCount = 0;
           string line;
           while (std::getline(fin, line)) {
               lineCount++;
           }
           

       }

       if (m_noOfLines == 0) {
           setEmpty();
       }
   }

   void TextFile::loadText() {
       if (m_textLines != nullptr) {
           delete[] m_textLines;
           m_textLines = nullptr;
       }

       if (m_filename) {
           m_textLines = new Line[m_noOfLines];
           ifstream fst;
           fst.open(m_filename);
           if (fst.is_open()) {
               string line1;
               int no = 0;
               while (getline(fst,line1))
               {
                   m_textLines[no++] = line1.c_str();

               }
               m_noOfLines =no+1;
               fst.close();
           }
       }       

   }

   void TextFile::saveAs(const char* fileName)const {
       ofstream fout(fileName);

       if (fout.is_open()) {
           for (unsigned i = 0; i < (lines()-1); i++) {
               fout << m_textLines[i].m_value << endl;
           }

           fout.close();

       }
       

   }

   TextFile::TextFile(unsigned pageSize){
       setEmpty();
       m_pageSize = pageSize;
   
   
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
       m_pageSize = pageSize;
       setEmpty();
       if (filename!=nullptr&&filename[0]!='\0') {
           setFilename(filename);
           
           setNoOfLines();
           loadText();
           


       }
       
   }

   TextFile::TextFile(const TextFile& ab) {
       m_pageSize = ab.m_pageSize;
       setEmpty();

       if (ab.m_filename) {
           setFilename(ab.m_filename, true);
           ab.saveAs(m_filename);
           setNoOfLines();
           loadText();

       }


   }

   TextFile& TextFile::operator=(const TextFile& cd) {
       if (this!=&cd&&*this&&cd) {
           delete[] m_textLines;
           m_textLines = nullptr;
           cd.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }

       return *this;

   }

   TextFile::~TextFile() {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;

   }

   unsigned TextFile::lines()const {
       return m_noOfLines;
   }

   std::ostream& TextFile::view(std::ostream& ostr)const {
       if (m_filename) {
           cout << m_filename << endl;
           cout << "==========" << endl;
           for (unsigned i = 1; i < lines(); i++) {
               cout << m_textLines[i - 1].m_value << endl;
               if (i % m_pageSize == 0) {
                   cout << "Hit ENTER to continue...";
                   char ch = ' ';
                   while (ch != '\n') {
                       ch = getchar();
                   }

                   char cstr[3];
                   scanf("%[^\n]", cstr);
               }
           }
       }
       return ostr;


   }

   std::istream& TextFile::getFile(std::istream& istr) {

       char name[100];
       istr >> name;
       setFilename(name);
       setNoOfLines();
       loadText();
       return istr;

   }

   TextFile::operator bool()const {
       return m_filename;
   }

   
   const char* TextFile::name()const {
       return m_filename;
   }
   const char* TextFile::operator[](unsigned index)const {
       return (m_textLines) ? m_textLines[index % (m_noOfLines - 1)].m_value : nullptr;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
       return text.view(ostr);
   }
   std::istream& operator>>(std::istream& istr, TextFile& text) {
       return text.getFile(istr);
   }


}

