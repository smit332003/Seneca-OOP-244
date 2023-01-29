/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jun 20 2022          
   Workshop: 5 Part- 2     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#ifndef HERO_H
#define HERO_H
#include <iostream>
#include "Power.h"
namespace sdds
{
    const int Max_namelenth = 50;
    const int Max_powerlenth = 20;

    class Hero
    {
        char Mname[Max_namelenth + 1];
        Power Mpower[Max_powerlenth];
        int P_level;
        void create_hero(const char *name, Power *power, int power_level);
        void create_empty();

    public:
        Hero();
        Hero(const char *name, Power *power, int power_count);
        friend std::ostream &operator<<(std::ostream &output, Hero hero);
        std::ostream &display() const;
        int calculate_sum_of_rarity_of_power();
        const char *m_get_name() const;
        const Power *get_power(int i) const;
        int get_power_level() const;
        void set_power_level(int power_level);
        void add_power(const Power *power);

        Power operator+=(Power power);
        int operator-=(int level);
        bool operator<(Hero hero);
        bool operator>(Hero hero);
        Power operator<<(Power power);
        friend Power operator>>(Power &power, Hero &hero);
    };

    void displayDetails(Power *powers, int size);

}

#endif
