/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 3 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/

#ifndef BARCHART
#define BARCHART
#include "Bar.h"

#include <iostream>
using namespace std;


namespace sdds
{
class BarChart
{
public:
BarChart();
~BarChart();
bool validBars();
void init(const char *title, int noOfSamples, char f);
void add(const char *bar_title, int value);
void draw() const;
void deallocate();
    private:
        const char *charttitle;
        Bar *bars;
        char sign;
        int length;
        int exicution;
        bool Umbrella;
    };
}
#endif