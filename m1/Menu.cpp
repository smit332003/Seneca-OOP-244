/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 14 2022          
   Assignment: 1   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/




#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    MenuItem::MenuItem(const char *content)
    {
        if (content && content[0] != '\0')
        {
            m_MenuItemContent = new char[strlen(content) + 1];
            strcpy(m_MenuItemContent, content);
        }
        else
        {
            m_MenuItemContent = nullptr;
        }
    }
    MenuItem::~MenuItem()
    {
        delete[] m_MenuItemContent;
    }
    MenuItem::operator bool() const
    {
        return m_MenuItemContent != nullptr;
    }
    MenuItem::operator const char *() const
    {
        return m_MenuItemContent;
    }
    ostream &MenuItem::display(ostream &os) const
    {
        if (!(m_MenuItemContent || m_MenuItemContent[0] == '\0'))
            os << m_MenuItemContent;
        return os;
    }
    Menu::Menu(const char *title)
    {
        if (title && title[0] != '\0')
        {
            m_TitleOfMenu = new char[strlen(title) + 1];
            strcpy(m_TitleOfMenu, title);
            m_MenuCounter = 0;
        }
        else
        {
            m_TitleOfMenu = nullptr;
            m_MenuCounter = 0;
        }
    }
    Menu::~Menu()
    {
        delete[] m_TitleOfMenu;
        m_TitleOfMenu = nullptr;
        for (int i = 0; i < m_MenuCounter; i++)
        {
            delete m_menuItems[i];
            m_menuItems[i] = nullptr;
        }
    }
    char *Menu::title() const
    {
        char *res = nullptr;
        if (m_TitleOfMenu && m_TitleOfMenu[0] != '\0')
            res = m_TitleOfMenu;
        return res;
    }
    void Menu::displayMenu() const
    {
        if (title())
        {
            cout << title();
            cout << ":\n";
        }

        for (int i = 0; i < m_MenuCounter; i++)
        {
            cout.setf(ios::right);
            cout.width(2);
            cout << (i + 1) << "- " << m_menuItems[i]->m_MenuItemContent << endl;
        }
        cout << " 0- Exit" << endl;
        cout << "> ";
    }
    unsigned int Menu::run() const
    {
        displayMenu();
        return getIntegerRange(0, m_MenuCounter);
    }
    unsigned int Menu::operator~() const
    {
        return run();
    }
    Menu &Menu::operator<<(const char *menuitemConent)
    {
        if (m_MenuCounter < int(MAX_MENU_ITEMS))
        {
            m_menuItems[m_MenuCounter] = new MenuItem(menuitemConent);
            m_MenuCounter++;
        }
        return *this;
    }
    Menu::operator int() const
    {
        return m_MenuCounter;
    }
    Menu::operator unsigned int() const
    {
        return m_MenuCounter;
    }
    Menu::operator bool() const
    {
        return m_MenuCounter > 0;
    }
    ostream &operator<<(ostream &os, const Menu &M)
    {
        if (M.title())
            os << M.title();
        return os;
    }
    const char *Menu::operator[](int idx) const
    {
        const char *res = nullptr;
        idx = idx % m_MenuCounter;
        if (idx > -1)
            res = m_menuItems[idx]->m_MenuItemContent;
        return res;
    }
}