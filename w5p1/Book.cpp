/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jun 17 2022          
   Workshop: 5 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"
using namespace std;
namespace sdds
{
    void Book::init_book()
    {
        m_title[0] = '\0';
        m_author[0] = '\0';
        m_num_chapters = 0;
        m_num_pages = 0;
    }

    Book::Book()
    {
        init_book();
    }

    Book::Book(const char *title_)
    {
        init_book();
        strcpy(m_title, title_);
    }

    Book::Book(const char *title_, const char *author_, double price_)
    {
        init_book();
        strcpy(m_title, title_);
        strcpy(m_author, author_);
        m_price = price_;
    }

    // Print a book summary
    void Book::summary()
    {
        cout.setf(ios::left);
        cout << "| ";
        cout.width(MAX_BOOK_TITEL);
        cout << m_title << " | ";
        cout.width(MAX_AUTHOR_NAME);
        cout << m_author << " | ";
        cout.width(3);
        cout << m_num_chapters << "  ";
        cout.width(4);
        cout << m_num_pages << " | ";
        cout.width(6);
        cout << m_price << " |" << endl;
    }

    int Book::add_chapter(Chapter *chapter_right)
    {
        m_chapters[m_num_chapters] = *chapter_right;
        m_num_pages +=int(*chapter_right);
       (*this)++;
        return m_num_chapters;
    }
    std::ostream &Book::display(std::ostream &os) const
    {
        os << "Title:'" << m_title << "'" << endl;
        os << "Author: '" << m_author << "'" << endl;

        for (int i = 0; i < m_num_chapters; i++)
        {
            os << m_chapters[i];
        }
        return os;
    }
    Book::operator int() const
    {
        return m_num_chapters;
    }
    Book::operator bool() const
    {
        bool value = false;
        for (int i = 0; i < m_num_chapters && !value; i++)
        {
            if (int(m_chapters[i]) > 0)
            {
                value = true;
            }
        }
        value=value&&m_title[0]&&m_author[0];
        return value;
       
    }
    Book::operator double() const
    {
        return m_price;
    }
    Book::operator const char *() const
    {
        return m_title;
    }
    bool Book::operator!() const
    {
        return !this->operator bool();
    }
    Book &Book::operator+=(Chapter chapter_right)
    {
        add_chapter(&chapter_right);
        return *this;
    }
    Book &Book::operator-=(double value)
    {
        m_price -= value;
        return *this;
    }
    Book Book::operator++(int)
    {
        Book temp = *this;
        m_num_chapters++;
        return temp;
    }
    std::ostream &operator<<(std::ostream &ostr, const Book &book_right)
    {
        return book_right.display(ostr);
    }
}
