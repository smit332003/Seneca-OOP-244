/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jun 10 2022          
   Workshop: 4 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/

#include <bits/stdc++.h>
#include "Car.h"
using namespace std;
namespace sdds{
    void Car::resetInfo()
    {
        delete[] var1;
        delete[] mo;
        delete[] tggc;
        var1 = nullptr;
        mo = nullptr;
        tggc = nullptr;
        p1 = 0;
        p2 = 0;
        mkbhd = 0;
    }
    Car::Car()
    {
        var1 = nullptr;
        mo = nullptr;
        tggc = nullptr;
        resetInfo();
    }
    Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        if(type != nullptr && brand != nullptr && model != nullptr && year > 0 && code > 0 && price > 0)
        { 
            var1 = new char[strlen(type) + 1];
            strcpy(var1, type);
            mo = new char[strlen(brand) + 1];
            strcpy(mo, brand);
            tggc = new char[strlen(model) + 1];
            strcpy(tggc, model);
            p1 = year;
            p2 = code;
            mkbhd = price;
        }
        else
        {
            resetInfo();
        }
    }
    Car::~Car()
    {
        delete[] var1;
        delete[] mo;
        delete[] tggc;
        var1 = nullptr;
        mo = nullptr;
        tggc = nullptr;
    }
    
    Car& Car::setInfo(const char *type,const char *brand, const char *model,int year,int code,double price)
    {
        this->resetInfo();
        if(type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code <= 99 || price <= 0)
        {
            return *this;
        }
        else
        {
            var1 = new char[strlen(type) + 1];
            strcpy(var1, type);
            mo = new char[strlen(brand) + 1];
            strcpy(mo, brand);
            tggc = new char[strlen(model) + 1];
            strcpy(tggc, model);
            p1 = year;
            p2 = code;
            mkbhd = price;
        }
        return *this;
    }

    void Car::printInfo()const
    {

        if(var1 != nullptr && mo != nullptr && tggc != nullptr && p1 >= 1990 && p2 > 99 && mkbhd > 0){
            printf("| %-10s | %-15s  | %-15s  | %-4d | %4d |  %8.2lf |\n",var1,mo,tggc,p1,p2,mkbhd);
        }
        
    }

    bool Car::isValid()const
    {
       
        if(var1 != nullptr && mo != nullptr && tggc != nullptr && p1 >= 1990 && p2 >= 100 && mkbhd > 0)
        {
           
            return true;
        }
        else{
            
            return false;
        }
    }

    bool Car::isSimilarTo(const Car& other)const
    {
            if(var1 == other.var1 && mo == other.mo && tggc == other.tggc && p1 == other.p1)
            {
                return true;
            }
            else
            {
                return false;
            }
            return false;
    }

    bool has_similar(const Car car[],const int num_cars)
    {
        for(int i = 0; i < num_cars; i++)
        {
            for(int j = i + 1; j < num_cars; j++)
            {
                if(car[i].isSimilarTo(car[j]))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool has_invalid(const Car car[], const int num_cars)
    {
        for(int i = 0; i < num_cars; i++)
        {
            if(!car[i].isValid())
            {
                return true;
            }
        }
        return false;
    }

   void print(const Car car[], const int num_cars)
   {
        for(int i = 0; i < num_cars; i++)
        {
            car[i].printInfo();
        }
    }
}
