#include <iostream>
#include <string>
#include <iostream>
#include "myclass.hpp"
using namespace std;

void displayMenu();
//void sampleFunction(char);

int main() {
     
   // Date calender;//(1, 1, 1999);
    
 //  int yearh;
 //   cout << "Enter year to display holidays: ";
 //   cin >>yearh;

   //   for(int i = 1; i <= 10 /*num of holidays*/; i++){
   //    calender.printHolidays(yearh, i);
    //  }
    
    
     Date obj;

    char choice;      // Calendar selection
     system("clear");  // Clear Screen
     //Use system("cls") with Windows OS
     cout << "\n\n\n\n\n\n\n";
     
     do
     {
       // Display the menu and get a valid selection.
       displayMenu();
       cin >> choice;
       while (toupper(choice) < 'A' || toupper(choice) > 'M')
       {
         cout << "Please make a choice in the range of A through L: ";
         cin >> choice;
       }
       // Process the user's selection.
       switch(choice)
       {
         case 'a':
         case 'A': system("clear");
                   cout<<"\n\n";
                   obj.setDate();
                   break;
         case 'b':
         case 'B': system("clear");
                   cout<<"\n\n";
                   obj.printNumericDate();
                   break;
         case 'c':
         case 'C': system("clear");
                   cout<<"\n\n";
                   obj.printDateWithWeekDayName();
                   break;
         case 'd':
         case 'D': system("clear");
                   cout<<"\n\n";
                   obj.addNumOfDays();
                   break;
         case 'e':
         case 'E': system("clear");
                   cout<<"\n\n";
                   obj.subNumOfDays();
                   break;
         case 'f':
         case 'F': system("clear");
                   cout<<"\n\n";
                   obj.numberOfDaysPassed();
                   break;
         case 'g':
         case 'G': system("clear");
                   cout<<"\n\n";
                   obj.numberOfDaysRemaining();
                   break;
         case 'h':
         case 'H': system("clear");
                   cout<<"\n\n";
                   obj.compareDates();
                   break;
         case 'i':
         case 'I': system("clear");
                   cout<<"\n\n";
                   obj.increment();
                   break;
         case 'j':
         case 'J': system("clear");
                   cout<<"\n\n";
                   obj.decrement();
                   break;
         case 'k':
         case 'K': system("clear");
                   cout<<"\n\n";
                   obj.printCurrentMonthCalendar();
                   break;
        case 'l':
        case 'L': system("clear");
                  cout<<"\n\n";
                  obj.displayHolidaysToMain();
                  break;
        /*
        case 'l':
         case 'L': system("clear");
                   cout<<"\n\n";
                   sampleFunction(choice);
                   break;
         */
       }
     } while (toupper(choice) != 'M');
     cout << "Goodbye!\n";
     return 0;
    }
     
    void displayMenu()
    {
     cout << endl;
     cout << "----------------------------------------\n";
     cout << "              CALENDAR MENU\n";
     cout << "----------------------------------------\n";
     cout << "A) Set Date\n";
     cout << "B) Display date (mm/dd/yyyy)\n";
     cout << "C) Display date (Weekday, Month day, year)\n";
     cout << "D) Display future date\n";
     cout << "E) Display past date\n";
     cout << "F) Number of days passed in current year\n";
     cout << "G) Number of days remaining in current year\n";
     cout << "H) Compares dates\n";
     cout << "I) Increment current date\n";
     cout << "J) Decrement current date\n";
     cout << "K) Display current monthly calendar\n";
     cout << "L) Display holidays\n";
     cout << "M) Exit the program\n\n";
     cout << "Enter your choice: ";
    }
  
