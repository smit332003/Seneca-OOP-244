/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 3 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#ifndef NETFLIX_ARMY_H
#define NETFLIX_ARMY_H
using namespace std;
namespace sdds
{
    
    class Army
    {
        public:
        static const int MAX_NAME_LEN = 50;
        private:
        char nation[MAX_NAME_LEN];
        int units;
        double power;
        public:
        void setEmpty();
        void createArmy(const char* country, double pow,int troops);        
        void updateUnits(int troops);
        const char* checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;
        bool isEmpty() const;
        bool isStrongerThan(const Army& army)const;       
  };

    void battle(Army& arm1, Army& arm2);
    void displayDetails(const Army* armies, int size);
}
#endif