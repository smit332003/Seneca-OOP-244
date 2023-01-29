/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: MAY 27 2022          
   Workshop: 3 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/


namespace sdds
{
    class Bar
    {
        char *car1;
        Bar *bike1;
        char car2;
        int  bike2;
        int bike3;
        bool running;

    public:
        Bar();
        Bar(const char *title, char symbol, int value);
        ~Bar();
        void set(const char *title, char symbol, int value);
        bool isBarValid() const;
        void draw() const;
    };
}