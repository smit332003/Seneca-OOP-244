/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 3 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/


#include <bits/stdc++.h>
#include "Bar.h"
using namespace std;
namespace sdds
{
    Bar::Bar()
    {
        car1 = nullptr;
        bike1 = nullptr;
        car2 = ' ';
        bike2 = 0;
        bike3 = 0;
        running = false;
    }
    Bar::Bar(const char *title, char symbol, int value)
    {
        car1 = new char[strlen(title) + 1];
        strcpy(car1, title);
        car2 = symbol;
        bike2 = value;
        bike3 = 0;
        running = true;
    }
    Bar::~Bar()
    {
        delete[] car1;
        car1 = nullptr;
        bike1 = nullptr;
    }
    void Bar::set(const char *title, char symbol, int value)
    {
        if(value<=0 || value>100){
            running = false;
            return ;
        }
        value/=2;
        car1 = new char[strlen(title) + 1];
        strcpy(car1, title);
        car2 = symbol;
        bike2 = value;
        bike3 = 0;
        running = true;
    }
    bool Bar::isBarValid() const
    {
        return running;
    }
    void Bar::draw() const
    {
        if (running)
        {
            int ind = 0;
            for(ind = 0; car1[ind] != '\0'; ind++){
                cout<<car1[ind];
            }
            while(ind < 20){
                cout<<".";
                ind++;
            }
            cout<<"|";
            for (int i = 0; i < bike2; i++)
            {
                cout << car2;
            }
            cout<<endl;
        }
    }
}