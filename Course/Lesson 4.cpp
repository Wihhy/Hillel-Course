// #include <iostream>
// #include <iomanip>
// using namespace std;
//
// int main()
// {
//     /*
//     Доробити класну задачу про наступну хвилину, щоб рахувалися також і години.
//     Попросіть користувача ввести час (години + хвилини).
//     */
//     int minutes;
//     int hours;
//     cout<<"Enter Hours:";
//     cin>>hours;
//     cout<<"Enter Minutes:";
//     cin>>minutes;
//     
//     if (minutes > 59 || minutes < 0 || hours > 23 || hours < 0)
//     {
//         cout<<"Don`t play with me, enter a real time.";
//         return 0;
//     }
//     minutes++;
//     if (minutes == 60)
//     {
//         minutes = 0;
//         hours++;
//     }
//     if (hours == 24)
//     {
//         hours = 0;
//     }
//     
//     cout << setw(2) << setfill('0') << hours << ":"
//      << setw(2) << setfill('0') << minutes << "\n";
//     
//
//     /*Попросити користувача ввести день тижня (1..7) та місяць (1..12).
//     Вам треба вирішити на котру годину заводити будильник.
//     В робочі дні - це 7 ранку, на вихідних - 10 ранку.
//     В липні та жовтні відпустка, тому в робочі це 10 ранку, а у вихідні - вимкнено.
//     наприклад:
//     Enter day of week and month:
//     5 4
//     07:00
//     Enter day of week and month:
//     6 7
//     off*/
//     
//     int day;
//     int month;
//     cout << "Enter a day (1-7): ";
//     cin >> day;
//     cout << "Enter a month (1-12): ";
//     cin >> month;
//     if (day > 7 || day < 1 || month > 12 || month < 1)
//     {
//         cout << "Invalid date";
//         return 0;
//     }
//     if (month == 7 || month == 10)
//     {
//         if (day <= 5)
//         {
//             cout << "Alarm is at 10";
//         }
//         else
//         {
//             cout << "Alarm is off";
//         }
//     }
//     else
//     {
//         if (day <= 5)
//         {
//             cout << "Alarm is at 7";
//         }
//         else
//         {
//             cout << "Alarm is at 10";
//         }
//     }
//     return 0;
//
//
//     /*Попросити користувача ввести день (1..31) та місяць (1..12).
// У весняні та осінні місяці, вихідними вважаються перші три дні місяця.
// У літні, вихідним вважаються дні після 20.
// Дати відповідь, це вихідний чи ні?
// Enter date:
// 2 4
// This is a holiday
// Enter date:
// 11 12
// This is not a holiday*/
//
//
//     int day;
//     int month;
//     cout << "Enter a day of the month(1-31): ";
//     cin >> day;
//     cout << "Enter a month (1-12): ";
//     cin >> month;
//     // Validating
//     if (month < 1 || month > 12 || day < 1 || 
//     (month == 2 && day > 29) || 
//     ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || 
//     day > 31)
//     {
//         cout << "Invalid date";
//         return 0;
//     }
//     // Spring and Autumn
//     if ((month >= 3 && month <= 5) || (month >= 9 && month <= 11))
//     {
//         if (day > 3)
//         {
//             cout << "This is not a holiday.";
//         }
//         else
//         {
//             cout << "This is a holiday.";
//         }
//     }
//     // Summer
//     else if (month >= 6 && month <= 8)
//     {
//         if (day > 20)
//         {
//             cout << "This is a holiday.";
//         }
//         else
//         {
//             cout << "This is not a holiday.";
//         }
//     }
//     
//     else
//     {
//         cout << "This is not a holiday.";
//     }
//     return 0;
//     
// }
//
//
//
//
