/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 3 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "BarChart.h"
using namespace std;
namespace sdds
{
    
    BarChart::BarChart()
    {
        exicution = 0;
        Umbrella = false;
    }
    BarChart::~BarChart()
    {
        
    }
    bool BarChart::validBars()
    {
        return Umbrella;
    }
    void BarChart::init(const char *title, int noOfSamples, char f)
    {
        bars = new Bar[noOfSamples];
        length = noOfSamples;
        sign = f;
        charttitle = title;
    }
    void BarChart::add(const char *bar_title, int value)
    {
        Bar *b = (Bar*)malloc(sizeof(Bar)*5);
        if (exicution <= length)
        {
            b->set(bar_title, sign, value);
            bars[exicution] = *b;
            exicution += 1;
        }
        if (exicution == length)
        {
            Umbrella = true;
        }
        else
        {
            Umbrella = false;
        }
        free(b);
    }
    void BarChart::draw() const
    {
        if (Umbrella)
        {
            bool validateBars = false;
            for (int i = 0; i < length; i++)
            {
                if (bars[i].isBarValid())
                {
                    validateBars = true;
                }
                else
                {
                    validateBars = false;
                }
            }
            if (validateBars)
            {
                cout << charttitle << endl;
                for (int d = 0; d < 71; d++)
                {
                    cout << "-";
                }
                cout << endl;
                for (int b = 0; b < length; b++)
                {
                    bars[b].draw();
                }
                for (int d = 0; d < 71; d++)
                {
                    cout << "-";
                }
                cout << endl;
            }
            
        }
        else
            {
                cout << "Invalid Chart!" << endl;
            }
    }
    void BarChart::deallocate()
    {
        delete[] bars;
    }
}
