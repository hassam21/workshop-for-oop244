/*******************************************************************
NAME         : Hassam Anas
SENECA EMAIL : hcheruvallykudy-anas@myseneca.ca
STUDENT ID   : 138932223
DATE         : 26th july,2024
WORKSHOP     : 9


I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.
*********************************************************************/

#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
#include <ostream>
namespace seneca {
   class Text {
      char* m_filename{};
      char* m_content{};
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
       // implement rule of three here
       Text(const Text&);
       ~Text();
       Text& operator=(const Text&);

      void read();
      virtual void write(std::ostream& os)const;

   };
    std::ostream& operator<<(std::ostream&,const Text&);
}
#endif // !SENECA_PERSON_H__