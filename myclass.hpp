//
//  myclass.hpp
//  CSC211 (Date Project)
//
//  Created by Jender Baldera on 12/2/21.
//

#ifndef myclass_hpp
#define myclass_hpp
#include <string>
using namespace std;

#include <stdio.h>

static string DAYS[7] = {"Sunday", "Monday","Tuesday","Wednesday", "Thursday", "Friday", "Saturday" };
static string MONTHS[12] = {"January", "February","March", "April", "May", "June", "July", "August", "September","October","November", "December"};
static int monthDays[12] =  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Date Class
class Date {
 
 // member variables
  private:
   int month, day, year;
   string weekDay;
 
  public:
   Date();
  // Date(int month, int day, int year); //////////????????
   int getMonth();
   int getDay();
   int getYear();
   string getWeekDay();
   void setMonth(int m);
   void setDay(int d);
   void setYear(int y);
   void setDate();        ///////////// NEWWWW
   bool isLeapYear(int);
   bool isValidDate(int, int, int); ///// NEWWWWWW
   void printNumericDate();
   void printDateWithWeekDayName();
   void addNumOfDays();
   void subNumOfDays();
   void numberOfDaysPassed();
   void numberOfDaysRemaining();
   int DayofMonthWeek(int day, int month, int year);
  // void printHolidays(int num, int holiday);
   string getMonthName(int); ////// Newwwwwww
   string getDayName(int); //////Newwwwwww
    void increment();
    void decrement();
    int dayOfTheWeek(int d, int m, int y);
    void compareDates();
    void printCurrentMonthCalendar();
    
    void printHolidays(int num, int holiday);
    int DayofMonth(int day, int month, int year);
    //newww notttt sure
    void printCurrentMonthB();
    
    void displayHolidaysToMain();
};


#endif /* myclass_hpp */
