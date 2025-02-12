/*******************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 26th july,2024
WORKSHOP     : 9


I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.
*********************************************************************/

#include <fstream>
#include <cstring>
#include "Text.h"
using namespace std;
namespace seneca {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

    Text::Text(const Text &right){
        if (right.m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
            m_filename = new char[strlen(right.m_filename) + 1];
            strcpy(m_filename, right.m_filename);
        }

        if (right.m_content != nullptr) {
            delete[] m_content;
            m_content = nullptr;
            m_content = new char[strlen(right.m_content) + 1];
            strcpy(m_content,right.m_content);
        }
    }

    Text& Text::operator=(const Text &right) {
       if(this == &right){
           return *this;
       }
       if(right.m_filename != nullptr){
           delete[] m_filename;
           m_filename = nullptr;
           m_filename = new char[strlen(right.m_filename) + 1];
           strcpy(m_filename,right.m_filename);
       } else{
           m_filename = nullptr;
       }
       if(right.m_content != nullptr){
           delete[] m_content;
           m_content = nullptr;
           m_content = new char[strlen(right.m_content) + 1];
           strcpy(m_content,right.m_content);
       }else{
           m_content = nullptr;
       }
        return *this;
    }

    Text::~Text() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }

    void Text::read() {
        int fileLength = getFileLength();
        m_content = new char[fileLength + 1];
        ifstream fin(m_filename);
        int len = 0;
        while (fin) {
            m_content[len] = fin.get();
            len += !!fin;
        }
        m_content[fileLength] = '\0';
    }

    void Text::write(ostream &os) const {
        if(m_content != nullptr ){
            os << m_content;
        }
    }

    const char &Text::operator[](int index) const {
        return m_content[index];
    }

    Text::Text(const char *filename) {
        if(filename != nullptr){
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename,filename);
            read();
        }
    }

    std::ostream& operator<<(std::ostream& os,const Text &T){
       T.write(os);
        return os;
   }

}