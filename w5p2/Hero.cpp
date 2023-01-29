/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jun 20 2022          
   Workshop: 5 Part- 2     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "Power.h"
using namespace std;

namespace sdds
{
    void Hero::create_empty()
    {

        Mname[0] = '\0';
        P_level = 0;
    }
    int Hero::calculate_sum_of_rarity_of_power()
    {
        int sum = 0;
        int size = 0;
        for (int i = 0; i < Max_powerlenth; i++)
        {
            if (!Mpower[i].isEmpty())
            {
                sum += Mpower[i].checkRarity();
                size++;
            }
        }
        return sum * size;
    }
    void Hero::add_power(const Power *power)
    {
        int size = 0;
        for (int i = 0; i < Max_powerlenth; i++)
        {
            if (!Mpower[i].isEmpty())
            {
                size++;
            }
        }

        this->Mpower[size] = *power;
    }
    void Hero::create_hero(const char *name, Power *power, int size)
    {
        if (name && name[0] != '\0')
        {
            strncpy(this->Mname, name, MAX_NAME_LENGTH);
            for (int i = 0; i < Max_powerlenth; i++)
            {

                if (i < size)
                {
                    Mpower[i] = power[i];
                }
            }
            this->P_level = calculate_sum_of_rarity_of_power();
        }
    }
    Hero::Hero()
    {
        this->create_empty();
    }
    Hero::Hero(const char *name, Power *power, int power_level)
    {
        this->create_hero(name, power, power_level);
    }
    ostream &Hero::display() const
    {
        // Print a book summary
        cout.setf(ios::left);
        cout << "Name: ";
        cout << this->m_get_name() << endl;
        displayDetails((Power *)this->get_power(0), Max_powerlenth);
        cout << "Power Level: " << this->get_power_level();

        return cout;
    }
    const char *Hero::m_get_name() const
    {
        return (const char *)this->Mname;
    }
    ostream &operator<<(ostream &output, Hero hero)
    {
        // return output << hero.m_get_name();
        return hero.display();
    }
    const Power *Hero::get_power(int i) const
    {
        return &Mpower[i];
    }
    int Hero::get_power_level() const
    {
        return P_level;
    }
    void Hero::set_power_level(int power_level)
    {
        P_level = power_level;
    }

    Power Hero::operator+=(Power power)
    {
        add_power(&power);
        P_level = calculate_sum_of_rarity_of_power();
        return power;
    }

    int Hero::operator-=(int level)
    {
        P_level -= level;
        return level;
    }
    bool Hero::operator<(Hero hero)
    {
        return P_level < hero.get_power_level() ? true : false;
    }
    bool Hero::operator>(Hero hero)
    {
        return P_level > hero.get_power_level() ? true : false;
    }

    Power Hero::operator<<(Power power)
    {
        this->add_power(&power);
        this->set_power_level(calculate_sum_of_rarity_of_power());
        return power;
    }
    Power operator>>(Power &power, Hero &hero)
    {
        hero.add_power(&power);
        hero.set_power_level(hero.calculate_sum_of_rarity_of_power());
        return power;
    }
}