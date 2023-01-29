/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jun 17 2022          
   Workshop: 5 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
namespace sdds
{
    const int MAX_CHAPTER_TITLE = 20;
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE + 1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();

    public:
        Chapter();
        Chapter(const char *title_);
        Chapter(const char *title_, int chapter_num, int n_pages, int n_words);
        std::ostream &display(std::ostream &) const;
        operator int() const;
        operator double() const;
        operator const char *() const;
        Chapter &operator=(const Chapter &chapter_right);
        Chapter &operator++();
        Chapter &operator--();
    };
    std::ostream &operator<<(std::ostream &ostr, const Chapter &chapter_right);

}
#endif