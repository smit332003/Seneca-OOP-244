/*==============================================
   Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 2 Part- 1      
  ==============================================*/


#ifndef SDDS_STUDENTS_H
#define SDDS_STUDENTS_H

namespace sdds{
    struct Student {
      char* m_name;
      int m_studentNumber;
      char m_grade;
   };

   void sort();
   bool load(Student& student);
   bool load(const char* file);
   void display(const Student& stud);
   void display();

   void deallocateMemory();
}

#endif