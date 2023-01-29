/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 14 2022          
   Assignment: 1   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/


#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds
{
    class Menu;
    const unsigned int MAX_MENU_ITEMS = 20;
    class MenuItem
    {
        char *m_MenuItemContent;
        MenuItem(const char * = nullptr);
        MenuItem(const MenuItem &) = delete;
        MenuItem &operator=(const MenuItem &) = delete;
        ~MenuItem();
        operator bool() const;
        operator const char *() const;
        std::ostream &display(std::ostream &) const;
        friend class Menu;
    };
    class Menu
    {
    private:
        char *m_TitleOfMenu;
        MenuItem *m_menuItems[MAX_MENU_ITEMS]{nullptr};
        int m_MenuCounter;
        Menu(const Menu &) = delete;
        Menu &operator=(const Menu &) = delete;

    public:
        Menu(const char * = nullptr);
        ~Menu();
        char *title() const;
        void displayMenu() const;
        unsigned int run() const;
        unsigned int operator~() const;
        Menu &operator<<(const char *menuitemConent);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        const char *operator[](int) const;
    };
    std::ostream &operator<<(std::ostream &, const Menu &);
}
#endif // !SDDS_MENU_H__