/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 4 Part- 2     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/

#ifndef CLEANERBOT
#define CLEANERBOT
namespace sdds{
    class CleanerBot{
        char *mig1;
        double ig;
        int var1;
        bool varbool;
        public:
        CleanerBot();
        CleanerBot(const char *location, double battery, int brush, bool active);
        ~CleanerBot();
        void set(const char *location, double battery, int brush, bool active);
        void setLocation(const char *location);
        void setActive(bool active);
        const char *getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;
        bool isValid() const;
        void display() const;
    };
    int report(CleanerBot* bot, const short num_bots);
    void sort(CleanerBot* bot, int num_bots);
}
#endif 