/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 4 Part- 2    
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#include <bits/stdc++.h>
#include "CleanerBot.h"
using namespace std;
namespace sdds
{
    CleanerBot::CleanerBot()
    {
        mig1 = nullptr;
        ig = 0;
        var1 = 0;
        varbool = false;
    }

    CleanerBot::CleanerBot(const char *location, double battery, int brush, bool active)
    {
        mig1 = new char[strlen(location) + 1];
        strcpy(mig1, location);
        ig = battery;
        var1 = brush;
        varbool = active;
    }

    CleanerBot::~CleanerBot()
    {
        delete[] mig1;
        ig = 0;
        mig1 = nullptr;
    }

    void CleanerBot::set(const char *location, double battery, int brush, bool active)
    {   
        mig1 = new char[strlen(location) + 1];
        strcpy(mig1, location);
        ig = battery;
        var1 = brush;
        varbool = active;
    }

    void CleanerBot::setLocation(const char *location)
    {
        mig1 = new char[strlen(location) + 1];
        strcpy(mig1, location);
    }

    void CleanerBot::setActive(bool active)
    {
        varbool = active;
    }

    const char *CleanerBot::getLocation() const
    {
        return mig1;
    }

    double CleanerBot::getBattery() const
    {
        return ig;
    }

    int CleanerBot::getBrush() const
    {
        return var1;
    }

    bool CleanerBot::isActive() const
    {
        if (varbool == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool CleanerBot::isValid() const
    {
        return ig > 0 && var1 > 0;
    }

    int report(CleanerBot *bot, const short num_bots)
    {
        cout << "         ------ Cleaner Bots Report -----\n";
        cout << "     ---------------------------------------\n";
        printf("| Location   | Battery |  Number of Brushes | Active |\n");
        printf("|------------+---------+--------------------+--------|\n");
        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                printf("| %-10s | %7.1lf | %18d | %-6s |\n", bot[i].getLocation(), bot[i].getBattery(), bot[i].getBrush(), bot[i].isActive() ? "YES" : "NO");
            }
        }

        cout << "\n";
        cout << "|====================================================|\n";
        cout << "| LOW BATTERY WARNING:                               |\n";
        cout << "|====================================================|\n";
        int low_battery = 0;
        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid() && bot[i].getBattery() < 30)
            {
                low_battery++;
            }
        }
        cout << "| Number of robots to be charged: " << low_battery<<"                  |\n";
        cout << "| Sorting robots based on their available power:     |\n";
        cout << "| Location   | Battery |  Number of Brushes | Active |\n";
        cout << "|------------+---------+--------------------+--------|\n";
       
       
        CleanerBot np;
        for(int i=0;i<num_bots - 1;i++){
            for(int j = i+1;j<num_bots;j++){
                if(bot[i].isValid() && bot[j].isValid()){
                    if(bot[i].getBattery() < bot[j].getBattery()){
                        np = bot[i];
                        bot[i] = bot[j];
                        bot[j] = np;
                    }
                }
            }
        }
       
       for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                printf("| %-10s | %7.1lf | %18d | %-6s |\n", bot[i].getLocation(), bot[i].getBattery(), bot[i].getBrush(), bot[i].isActive() ? "YES" : "NO");
            }
        }
        cout << "|====================================================|\n";

        return 1;
    }
}
