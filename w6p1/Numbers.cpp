/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 7 2022          
   Workshop: 6 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }

   Numbers::Numbers(const Numbers& numbers)
   {
       setEmpty();
       m_isOriginal = false;
       *this = numbers;
   }

   Numbers& Numbers::operator=(const Numbers& other)
   {
       delete[] m_numbers;
       delete[] m_filename;
       setEmpty();
       m_numCount = other.m_numCount;
       if(m_numCount > 0)
       {
	       m_numbers = new double[m_numCount];
       	   for(int i = 0; i < m_numCount; ++i)
       	   {
        		m_numbers[i] = other.m_numbers[i];
       	   }
       }
       setFilename(other.m_filename);

       return *this;
   }


   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   int Numbers::numberCount() const
   {
       std::string line;
       int count = 0;
       std::ifstream file(m_filename);
       while (std::getline(file, line))
       {
           count++;
       }
       return count;
   }

   bool Numbers::load()
   {
       if(m_numCount > 0)
       {
           m_numbers = new double[m_numCount];
           std::ifstream file(m_filename);
           int i = 0;
           while(file && i < m_numCount)
           {
               file >> m_numbers[i++];
           }
           return i == m_numCount;
       }
       return false;
   }

   void Numbers::save()
   {
       if(m_isOriginal && !isEmpty())
       {
           std::ofstream file{ m_filename };
           for(int i = 0; i < m_numCount; ++i)
           {
               file << m_numbers[i] << '\n';
           }
       }
   }

   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   Numbers& Numbers::operator+=(const double num)
   {
       auto temp = new double[m_numCount + 1];
       for(int i = 0; i < m_numCount; ++i)
       {
           temp[i] = m_numbers[i];
       }
       
       temp[m_numCount++] = num;

       delete[] m_numbers;
       m_numbers = temp;
       sort();

       return *this;
   }

   std::ostream& Numbers::display(std::ostream& ostr) const
   {
       if (isEmpty())
           ostr << "Empty list";
       else
       {
           ostr << "=========================\n";
           if (m_isOriginal)
               ostr << m_filename << '\n';
           else
               ostr << "*** COPY ***\n";
           for(int i = 0; i < m_numCount - 1; ++i)
           {
               ostr << m_numbers[i] << ", ";
           }
           ostr << m_numbers[m_numCount - 1] << '\n';
           ostr << "-------------------------\n";
           ostr << "Total of " << m_numCount << " number(s)\n";
           ostr << "Largest number:  " << max() << '\n';
           ostr << "Smallest number: " << min() << '\n';
           
           ostr << "Average :        " << average() << '\n';
           ostr << "=========================";
       }

       return ostr;
   }

   std::ostream& operator<<(std::ostream& os, const Numbers& N)
   {
       return N.display(os);
   }

   std::istream& operator>>(std::istream& istr, Numbers& N)
   {
       double num;
       istr >> num;
       N += num;
       return istr;
   }
}
