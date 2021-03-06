
/*************************************************************************
Title:          linkedList.h
Author:         Erin Williams
Date Created:   3/12/17
Class:          Spring 2017, CSCI 235-04, Mon & Wed 7:00pm-8:15pm
Professor:      Aarsh Vora
Purpose:        Assignment #2
Description:    Header File for Date Class
************************************************************************/
#ifndef __CS235_DATE_H_
#define __CS235_DATE_H_

#include<iostream>
#include<ostream>
#include<iomanip>

namespace datewilliams {
    class Date {
    public:

        Date(int month = 0, int day = 0, int year = 0) : month_(month), day_(day), year_(year) {}

        //Getters and setters
        inline int getMonth() const { return month_; }
        inline int getDay() const { return day_; }
        inline int getYear() const { return year_; }
        inline void setMonth(int month) { month_ = month; }
        inline void setDay(int day) { day_ = day; }
        inline void setYear(int year) { year_ = year; }

        //Overloaded to give output as MM/DD/YYYY format
        friend std::ostream& operator <<(std::ostream& out, const Date& date);

        Date& operator =(const Date& rhs);
        bool operator ==(const Date& rhs) { return rhs.month_ == month_ && rhs.day_ == day_ && rhs.year_ == year_; }
        bool operator !=(const Date& rhs) { return rhs.month_ != month_ || rhs.day_ != day_ || rhs.year_ != year_; }
        //Overloaded to compare year, then month, then day
        bool operator < (const Date& rhs);

        //Gives output in MM/DD/YYYY format
        void printMMDDYYYY(std::ostream& out);

    private:
        int month_;
        int day_;
        int year_;
    };

} //datewilliams

#endif //__CS235_DATE_H_
