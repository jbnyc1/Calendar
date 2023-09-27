
//  myclass.cpp
//  CSC211 (Date Project)

#include "myclass.hpp"
#include <string>
#include <iostream>
using namespace std;


string Date::getDayName(int num) {
   
    if(num == 0)
        return "Sunday";
   else if(num == 1)
        return "Monday";

   else if(num == 2)
        return "Tuesday";

   else if(num == 3)
        return "Wednesday";

   else if(num == 4)
        return "Thursday";

   else if(num == 5)
        return "Friday";

   else if(num == 6)
        return "Saturday";
return "";
}

string Date::getMonthName(int num) {
   
    if (num == 1)
       return "January";

    else if(num == 2)
       return "February";

    else if(num == 3)
       return "March";

    else if(num == 4)
       return "April";

    else if(num == 5)
       return "May";

    else if(num == 6)
       return "June";

    else if(num == 7)
       return "July";

    else if(num == 8)
       return "August";

    else if(num == 9)
       return "September";

    else if(num == 10)
       return "October";

    else if(num == 11)
       return "November";

    else if(num == 12)
       return "December";
return "";
}

Date::Date() {
    
    month = 1;
    day = 1;
    year = 1753;
}
// member functions
int Date::getMonth() {
    return month;
}
 
int Date::getDay() {
    return day;
}
 
int Date::getYear() {
    return year;
}
void Date::setMonth(int m) {
    month = m;
}
 
void Date::setDay(int d) {
    day = d;
}
 
void Date::setYear(int y) {
    year = y;
}

//Set Date Function
void Date::setDate() {
int m, d, y;
cout << "Enter the month: ";
cin >> m;
cout << "Enter the day: ";
cin >> d;
cout << "Enter the year: ";
cin >> y;
if(isValidDate(m, d, y)) {
  setMonth(m);
  setDay(d);
  setYear(y);
  
  cout << endl;
  cout << " Date Updated!" << endl << endl;
}
 
else {
   cout << endl << " Date Not Updated!" << endl;
   cout << "Please enter a valid number for the month/day/year.";
}
}

// Check for leap Year
bool Date::isLeapYear(int year) {

  if(year % 4 == 0)
      return true;
  if(year % 100 == 0)
      return false;
  if(year % 400 == 0)
      return true;
  return false;
}

// Check if Date is Valid
bool Date::isValidDate(int m, int d, int y) {
 if(m <= 0 || m > 12 )
    return false;
 if(d <= 0 || d > 31 )
    return false;
 if(y < 0 )
    return false;
  
 if(m == 2) {
   if( d > 29)
      return false;
if(!isLeapYear(y) && d == 29) {
      return false;
}
 }
else if(m == 4 || m == 6 || m == 9 || m == 11) {
  if(d == 31)
     return false;
}
    return true;
}



void Date::printNumericDate() {
 cout << endl << "Date: " << getMonth() << "/" << getDay() << "/" << getYear() << endl << endl;
}


void Date::printDateWithWeekDayName() {
    
    int x = dayOfTheWeek(getDay(), getMonth(), getYear());
    string z = getMonthName(getMonth());
    cout << getDayName(x) << ", " << z << " " << getDay() << ", " << getYear() << endl;
}

int Date::dayOfTheWeek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (( y + int(y / 4) - int(y / 100) + int(y / 400) + t[m - 1] + d) % 7);
}


void Date::addNumOfDays() {
    int i = 1;
    int n, d, m, y;
    
    cout << endl << "Enter the number of days to add: ";
    cin >> n;
    
    d = getDay();
    m = getMonth();
    y = getYear();
    
    while(i <= n) {
        d++;
        if(d == 31 && m == 12) {
            y = y + 1;
            d = 0;
            m = 1;
        }
        else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
            d = 0;
            m++;
            
        }
        else if(d == 31) {
            d = 0;
            m++;
        }
        else if(m == 2) {
            if(isLeapYear(y)) {
                if( d == 29) {
                    d = 0;
                    m++;
                }
            }
            else if(d == 28) {
                d = 0;
                m++;
                }
            }
        i++;
        }
    int res = dayOfTheWeek(d, m, y);
    string mn = getMonthName(m);
    cout << "\n" << n << " days from now, the date will be ";
    cout <<getDayName(res) << ", " << mn << " " << d << ", " << y << "\n" << endl;
}
    





void Date::subNumOfDays() {
    int i = 1;
    int n, d, m, y;
    
    cout << endl << "Enter the number of days to substract: ";
    cin >> n;
    
    d = getDay();
    m = getMonth();
    y = getYear();
    
    while(i <= n) {
        d--;
        if(d == 1 && m == 1) {
            y = y - 1;
            d = 32;
            m = 12;
        }
        else if(d == 1 && (m == 5 || m == 7 || m == 10 || m == 12)) {
            d = 31;
            m--;
            
        }
        else if(d == 1 && m!= 3) {
            d = 32;
            m--;
        }
        else if(m == 3) {
            if(isLeapYear(y)) {
                if( d == 1) {
                    d = 30;
                    m--;
                }
            }
            else if(d == 1) {
                d = 29;
                m--;
                }
            }
        i++;
        }
    int res = dayOfTheWeek(d, m, y);
    string mName = getMonthName(m);
    cout << "\n" << n << " days past now, the date was ";
    cout <<getDayName(res) << ", " << mName << " " << d << ", " << y << "\n" << endl;
}



void Date::numberOfDaysPassed()  {
    int i = -1;
    int d, m, y;
    
    
    d = getDay();
    m = getMonth();
    y = getYear();
    
    while(!(d == 31 && m == 12 && y == getYear() - 1)) {
        d--;
        if(d == 1 && m == 1) {
            y = y - 1;
            d = 32;
            m = 12;
        }
        else if(d == 1 && (m == 5 || m == 7 || m == 10 || m == 12)) {
            d = 31;
            m--;
            
        }
        else if(d == 1 && m!= 3) {
            d = 32;
            m--;
        }
        else if(m == 3) {
            if(isLeapYear(y)) {
                if(d == 1) {
                    d = 30;
                    m--;
                }
            }
            else if(d == 1) {
                d = 29;
                m--;
                }
            }
        i++;
        }
    cout << "\n" << i << " days have passed this year\n" << endl;
}



void Date::numberOfDaysRemaining()  {
    int i = -1;
    int d, m, y;
    
    
    d = getDay();
    m = getMonth();
    y = getYear();
    
    while(!(d == 1 && m == 1 && y == getYear() + 1)) {
        d++;
        if(d == 31 && m == 12) {
            y = y + 1;
            d = 0;
            m = 1;
        }
        else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
            d = 0;
            m++;
            
        }
        else if(d == 31) {
            d = 0;
            m++;
        }
        else if(m == 2) {
            if(isLeapYear(y)) {
                if(d == 29) {
                    d = 0;
                    m++;
                }
            }
            else if(d == 28) {
                d = 0;
                m++;
                }
            }
        i++;
        }
    cout << "\n" << i << " days left this year\n" << endl;
}








void Date::increment() {
    int i = -1;
    int d, m, y;
    
    
    d = getDay();
    m = getMonth();
    y = getYear();
    
    d++;
 
        if(d == 31 && m == 12) {
            y = y + 1;
            d = 0;
            m = 1;
        }
        else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
            d = 0;
            m++;
            
        }
        else if(d == 31) {
            d = 0;
            m++;
        }
        else if(m == 2) {
            if(isLeapYear(y)) {
                if(d == 29) {
                    d = 0;
                    m++;
                }
            }
            else if(d == 28) {
                d = 0;
                m++;
                }
            }
        i++;
        
    int dn = dayOfTheWeek(d, m, y);
    string mn = getMonthName(m);
    
    cout << "\nDate incremented!\n" << endl;
    cout << "\n" << getDayName(dn) << ", " << mn << " " << d << ", " << y << "\n" << endl;
    
    setDay(d);
    setMonth(m);
    setYear(y);
}





void Date::decrement() {
    int d, m, y;
    
    d = getDay();
    m = getMonth();
    y = getYear();
    
    d--;
 
        if(d == 1 && m == 1) {
            y = y - 1;
            d = 32;
            m = 12;
        }
        else if(d == 1 && (m == 5 || m == 7 || m == 10 || m == 12)) {
            d = 31;
            m--;
            
        }
        else if(d == 1 && m!= 3) {
            d = 32;
            m--;
        }
        else if(m == 3) {
            if(isLeapYear(y)) {
                if(d == 1) {
                    d = 30;
                    m--;
                }
            }
            else if(d == 1) {
                d = 29;
                m--;
                }
            }

    int dn = dayOfTheWeek(d, m, y);
    string mn = getMonthName(m);
    
    cout << "\nDate decremented!\n" << endl;
    cout << "\n" << getDayName(dn) << ", " << mn << " " << d << ", " << y << "\n" << endl;
    
    setDay(d);
    setMonth(m);
    setYear(y);
}

void Date::compareDates() {
    int i = 0;
    int d, m, y, dd, mm, yy;
    int status = 0;
    
    cout << "\nEnter the month: ";
    cin >> m;
    cout << "Enter the day: ";
    cin >> d;
    cout << "Enter the year: ";
    cin >> y;
    
    if(!isValidDate(m, d, y)) {
      
      cout << endl;
      cout << "Date is not valid!" << endl << endl;
        return;
    }
    
    if(y > getYear())
        status = 1;
    else if(y < getYear())
        status = -1;
    else if(m > getMonth())
        status = 1;
    else if(m < getMonth())
        status = -1;
    else if(d > getDay())
        status = 1;
    else if(d < getDay())
        status = -1;
    
    if(status == 1) {
        dd = d;
        mm = m;
        yy = y;
        
        d = getDay();
        m = getMonth();
        y = getYear();
    }
    else if(status == -1) {
        dd = getDay();
        mm = getMonth();
        yy = getYear();
        
    if(status == 0)
        cout << "\nThe date is today!\n" << endl;
    else {
        while(!(d == dd && m == mm && y == yy)) {
            d++;
            if(d == 31 && m == 12) {
                y = y + 1;
                d = 0;
                m = 1;
            }
            else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
                d = 0;
                m++;
                
            }
            else if(d == 31) {
                d = 0;
                m++;
            }
            else if(m == 2) {
                if(isLeapYear(y)) {
                    if(d == 29) {
                        d = 0;
                        m++;
                    }
                }
                else if(d == 28) {
                    d = 0;
                    m++;
        }
        
    }
            i++;
            if(status == 1)
                cout << "\nThe date entered will be reached in "<< i <<"days!" << endl << endl;
            else
                cout << "\nThe date entered has passed " << i << " days ago!" << endl << endl;
            
        }
    }
    }
}
    
void Date::printCurrentMonthCalendar() {
    int i;
    int nodays;
    int index;
 
    index = dayOfTheWeek(1, getMonth(), getYear());
    
    if(month == 2) {
        if(isLeapYear(getYear()))
           nodays = 29;
        else
            nodays = 28;
    }
        else if(getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)
           nodays = 30;
        else
           nodays = 31;
           
           cout << "\n\t\t" << getMonthName(getMonth()) << " " << getYear() << endl;
           cout << "\nSu\tMo\tTu\tWe\tTh\tFr\tSA" << endl;
           for (i = 1; i <= nodays + index; i++) {
            if(i <= index)
                cout << "  \t";
            else
                cout << i - index << "\t";
            if( i % 7 == 0)
                cout << endl;
        }
       
    }


int Date::DayofMonth(int day, int month, int year)
{ //tells us what the first day of any given month will be
 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month] + day) % 7;
}




void Date::printHolidays(int num, int holiday){
  //create a switch statement; depending on the holiday, change the month and the # of weeks.
  //insert that information into algorithm.
    int sMonth = 0, sDay = 1, addedWeeks = 0;
  string name;
  string DayToLookFor = "Monday";

  switch(holiday){
    case 1:
      sMonth = 0;
      cout << "New Year's Day is on " << DAYS[DayofMonth(sDay, sMonth, num)] << ", January 1" << endl;
      return;
    case 2:
      name = "Martin Luther King Jr.'s Day";
      sMonth = 0; //jan
      addedWeeks = 2; //third monday, 2 weeks added
      break;
    case 3:
      name = "Presidents Day";
      sMonth = 1; //feb
      addedWeeks = 2; //third monday, 2 weeks added
      break;
    case 4:
      name = "Memorial Day";
      sMonth = 4;
      addedWeeks = 4;
      break;
    case 5:
    sMonth = 6;
      cout << "Independence Day is on " << DAYS[DayofMonth(sDay, sMonth, num)] << ", July 4" << endl;
      return;
    case 6:
      name = "Labor Day";
      sMonth = 8;
      addedWeeks = 0;
      break;
    case 7:
      name = "Columbus Day";
      sMonth = 9;
      addedWeeks = 1;
      break;
    case 8:
      sMonth = 10;
      cout << "Veterans Day is on " << DAYS[DayofMonth(sDay, sMonth, num)] << ", November 11" << endl;
      return;
    case 9:
      name = "Thanksgiving Day";
      sMonth = 10;
      addedWeeks = 3;
      DayToLookFor = "Thursday";
      break;
    case 10:
      sMonth = 11;
      cout << "Christmas Day is on " << DAYS[DayofMonth(sDay, sMonth, num)] << ", December 25" << endl;
      return;
  }

  int pos = DayofMonth(sDay,sMonth, num);
  if(DAYS[pos] != DayToLookFor){  //if not, we know what position we're in in the week.
    while(DAYS[pos] != DayToLookFor){
      pos++; //iterate until we're at the needed position. i.e. if we got monday (1) and we need to be at thursday (4), add 3 to day.
      if(pos > 6){
        pos = 0;
      }
      sDay++;
    }
  }
    sDay += (addedWeeks * 7);

  cout << name << " is on " << DAYS[DayofMonth(sDay, sMonth, num)] << ", " << MONTHS[sMonth] << " " << sDay << endl;
}
     
   

void Date::printCurrentMonthB(){
  //find the first day of the month
  int DayPosition = DayofMonth(1,month, year);

  //print out the month's name
  cout << MONTHS[month] << endl;

  //print the columns for the days to fall under (Sun, Mon, etc.)
  cout << "SUN MON TUE WED THU FRI SAT"<<endl;

  //print blank spaces before date
  int spaces;
  for(spaces = 0; spaces < DayPosition; spaces++){
    cout << "    ";
  }

  //print dates from thereon out
  for(int i = 1; i <= monthDays[month]; i++){
    if(i <10)
      cout << "0" + to_string(i) << "  ";
    else
      cout << i << "  ";
      spaces++;

    if(spaces == 7){
      cout << endl;
      spaces = 0;
    }
  }
  
  cout << endl;
}

void Date::displayHolidaysToMain() {
    int yearh;
    cout << "Enter the year: ";
    cin >> yearh;
    cout << endl;
    
  for(int i = 1; i <= 10 /*num of holidays*/; i++){
    printHolidays(yearh, i);
  }
}





