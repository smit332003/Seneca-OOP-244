/*==============================================
   Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 2 Part- 1      
  ==============================================*/


#ifndef FILE_H_
#define FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
  
   //for reading name
   bool read(char *stuName);

   //for reading student number
   bool read(int &stuNumber);

   //for reading grade
   bool read(char &stuGrade);

}
#endif // !SDDS_FILE_H_
