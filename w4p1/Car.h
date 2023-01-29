/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jun 10 2022         
   Workshop: 4 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/


#ifndef CAR_H
#define CAR_H

namespace sdds
{
    class Car
    {
        private:
        char * var1;
        char * mo;
        char * tggc;
        int p1;
        int p2;
        double mkbhd;
        public:
        Car();
        Car(const char *type, const char *brand, const char *model, int year = 2022, int code = 100, double price = 1);
        ~Car();
        void resetInfo();
        Car& setInfo(const char *type, const char *brand, const char *model,int yera,int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const Car& car) const;
    };
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);
}
#endif