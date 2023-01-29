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
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds
{
    bool Date::validate()
    {
        errCode(Not_error);
        if (m_YEAR < YEAR_MIN || m_YEAR > m_CURRENT_YEAR + 1)
        {
            errCode(Error_Year);
        }
        else if (m_MONTH < 1 || m_MONTH > 12)
        {
            errCode(Error_Month);
        }
        else if (m_DAY < 1 || m_DAY > mdays())
        {
            errCode(Error_Day);
        }
        return !bad();
    }
    int Date::mdays() const
    {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
        int month = m_MONTH >= 1 && m_MONTH <= 12 ? m_MONTH : 13;
        month--;
        return days[month] + int((month == 1) * ((m_YEAR% 4 == 0) && (m_YEAR % 100 != 0)) || (m_YEAR % 400 == 0));
    }
    int Date::systemYear() const
    {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        return lt.tm_year + 1900;
    }
    void Date::setToToday()
    {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        m_DAY = lt.tm_mday;
        m_MONTH = lt.tm_mon + 1;
        m_YEAR = lt.tm_year + 1900;
        errCode(Not_error);
    }
    int Date::daysSince0001_1_1() const
    { 
        int tempYear = m_YEAR;
        int tempMonth= m_MONTH;
        if (tempMonth < 3)
        {
            tempYear--;
            tempMonth += 12;
        }
        return 365 * tempYear + tempYear / 4 - tempYear / 100 + tempYear / 400 + (153 * tempMonth- 457) / 5 + m_DAY - 306;
    }
    Date::Date() : m_CURRENT_YEAR(systemYear())
    {
        setToToday();
    }
    Date::Date(int year, int mon, int day) : m_CURRENT_YEAR(systemYear())
    {
       m_YEAR = year;
        m_MONTH = mon;
       m_DAY = day;
        validate();
    }
    const char *Date::dateStatus() const
    {
        return Error_Date[errCode()];
    }
    int Date::currentYear() const
    {
        return m_CURRENT_YEAR;
    }
    void Date::errCode(int readErrorCode)
    {
        m_ERRORCODE = readErrorCode;
    }
    int Date::errCode() const
    {
        return m_ERRORCODE;
    }
    bool Date::bad() const
    {
        return m_ERRORCODE != 0;
    }
    bool Date::operator==(const Date &dateObj) const
    {
        return daysSince0001_1_1() == dateObj.daysSince0001_1_1();
    }
    bool Date::operator!=(const Date &dateObj) const
    {
        return daysSince0001_1_1() != dateObj.daysSince0001_1_1();
    }
    bool Date::operator>=(const Date &dateObj) const
    {
        return daysSince0001_1_1() >= dateObj.daysSince0001_1_1();
    }
    bool Date::operator<=(const Date &dateObj) const
    {
        return daysSince0001_1_1() <= dateObj.daysSince0001_1_1();
    }
    bool Date::operator<(const Date &dateObj) const
    {
        return daysSince0001_1_1() < dateObj.daysSince0001_1_1();
    }
    bool Date::operator>(const Date &dateObj) const
    {
        return daysSince0001_1_1() > dateObj.daysSince0001_1_1();
    }
    int Date::operator-(const Date &dateObj) const
    {
        return daysSince0001_1_1() - dateObj.daysSince0001_1_1();
    }
    Date::operator bool() const
    {
        return !bad();
    }
    std::istream &Date::read(std::istream &is)
    {
        int Temp_Int;
        char Temp_Char;
        errCode(Not_error);
        is >> Temp_Int;
        m_YEAR = Temp_Int;
        is >> Temp_Char;
        is >> Temp_Int;
        m_MONTH = Temp_Int;
        is >> Temp_Char;
        is >> Temp_Int;
        m_DAY = Temp_Int;
        if (is.fail())
        {
            errCode(input_Failed);
            is.clear();
        }
        else
            validate();
        cin.ignore(1000, '\n');
        return is;
    }
    std::ostream &Date::write(std::ostream &os) const
    {
        if (bad())
            os << dateStatus();
        else
        {
            os.setf(ios::right);
            os << m_YEAR << "/";
            os.fill('0');
            os.width(2);
            os << m_MONTH << "/";
            os.width(2);
            os << m_DAY;
            os.fill(' ');
        }
        return os;
    }
    ostream &operator<<(ostream &os, const Date &D)
    {
        return D.write(os);
    }
    istream &operator>>(istream &is, Date &D)
    {
        return D.read(is);
    }
}
