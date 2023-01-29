/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 7 2022          
   Workshop: 6 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& numbers);
      Numbers& operator=(const Numbers& other);
      Numbers& operator+=(const double num);
      friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
      friend std::istream& operator>>(std::istream& istr, Numbers& N);
      std::ostream& display(std::ostream& ostr) const;
      double average()const;
      double max()const;
      double min()const;
      int numberCount() const;
      bool load();
      void save();
      ~Numbers();
   };
}
#endif // !SDDS_NUMBERS_H_

