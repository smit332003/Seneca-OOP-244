/*==============================================
   Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 2 Part- 1      
  ==============================================*/


#include <iostream>
#include <string.h>
#include "Student.h"
#include "File.h"
using namespace std;

namespace sdds{
   int no_of_Students;
   Student* students;

   void sort() {
      int i=no_of_Students - 1;
      int j=0;
      Student temp;
      while(i>0){
         while(j<i){
            if (students[j].m_grade > students[j + 1].m_grade) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            j++;
         }
         }
         i--;
      }
   }

   bool load(Student& student){
      char sname[128];
      if(read(sname) && read(student.m_studentNumber) && read(student.m_grade)){
         student.m_name = new char[strlen(sname) + 1];
         strcpy(student.m_name, sname);
      }
      return true;
   }

   bool load(const char* file){   
      int i = 0,j=0;
      if(openFile(file)){
         no_of_Students = noOfRecords();
         students = new Student[no_of_Students];
         for(j=0;j<no_of_Students;j++){
            i += load(students[j]);
         }
          if(i!=no_of_Students){
            cout<<"Error: incorrect number of records read; the data is possibly corrupted.\n";
         }
         closeFile();
      }
      return true;
   }

   void display(const Student& stud){
      cout<<stud.m_name<<", "<<stud.m_studentNumber<<": "<<stud.m_grade<<endl;
   }

   void display(){
      sort();
      int i=0;
      while(i<no_of_Students){
         cout<<i+1<<": ";
         i++;
      }
   }

   void deallocateMemory(){
      int i=0;
      while(i<no_of_Students){
         delete[] students[i].m_name;
         i++;
      }
      delete[] students;
   }
}
