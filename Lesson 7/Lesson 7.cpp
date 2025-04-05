#include <iostream>
using namespace std;


// Вивести на екран таблицю множення на 4
void multiplication_table() {
    int number = 4;
    for (int i = 1; i <= 10; i++) {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}


// Напишіть функцію яка за номером місяця (1..12) повертає кількість днів у ньому (28..31).
int days_in_month(int month) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return 28;
    default:
        return -1; // Некоректний номер місяця
    }
}


// Джей та Боб у вільний час ловлять покемонів у передмісті сонячної Філадельфії.
// Щодня кожен з них ловить від 3 до 6 покемонів (як пощастить).
// Вони уклали парі: хто збере більше покемонів за тиждень.
// Треба симулювати їхнє змагання.
// Програма має виводити результат кожного дня, а також результат парі (Джей, Боб чи нічия)

void competition()
{
    int bobs_pokemons = 0;
    int jays_pokemons = 0;
    for (int i = 1; i < 8; i++)
    {
        cout << "DAY "<< i << endl;
        int bob_today_caught = 3 + rand() % (6 - 3 + 1);
        int jay_today_caught = 3 + rand() % (6 - 3 + 1);
        bobs_pokemons = bobs_pokemons + bob_today_caught;
        jays_pokemons = jays_pokemons +  jay_today_caught;
        cout << "Bob caught "<< bob_today_caught << " (now he has " << bobs_pokemons << ")"<< endl;
        cout << "Jay caught "<< jay_today_caught << " (now he has " << jays_pokemons << ")"<< endl;
    }

    cout << "Results:" << endl;
    cout << "Bob got " << bobs_pokemons << " pokemons"<< endl;
    cout << "Jay got " << jays_pokemons << " pokemons"<< endl;
    if (bobs_pokemons > jays_pokemons) {
        cout << "Bob wins!"<< endl;
    }
    else if (jays_pokemons > bobs_pokemons) {
        cout << "Jay wins!" << endl;
    }
    else {
        cout << "It is a tie!" << endl;
    }
}


// Джей та Боб знову уклали парі з покемонами, але тепер на швидкість:
// Хто перший збере 90 покемонів.
// В день коли хтось збере 90 чи більше покемонів парі зупиняється.
// Якщо обидва набрали 90 або більше - це нічия.
// Наприклад:
// Enter your bet:
// 1
// You choose Jay.
// ...
// Bob got 29 pokemons
// Jay got 27 pokemons
// Bob wins!
// Бонусне завдання:
// Ви теж берете участь у їхньому парі, але як спостерігач: перед початком змагання,
// ви робите ставку на того хто переможе (наприклад 1-Джей чи 2-Боб). 
// Наприклад:
// Enter your bet:
// You have chosen Jay.
// Програма має показати результат вашої ставки (виграли/програли). У випадки нічиєї - ви програли:


void competition_with_bet()
{
    int bobs_pokemons = 0;
    int jays_pokemons = 0;
    int users_bet = 0;
    bool is_bob_won = false;
    bool is_jay_won = false;
    
    cout << "Enter your bet (1 is for Bob, 2 is for Jay): ";
    cin >> users_bet;
    
    if (users_bet != 1 && users_bet != 2) {
        cout << "Invalid bet! Please choose 1 for Bob or 2 for Jay." << endl;
        return;
    }
    
    for (int i = 1; ; i++)
    {
        cout << "DAY "<< i << endl;
        int bob_today_caught = 3 + rand() % (6 - 3 + 1);
        int jay_today_caught = 3 + rand() % (6 - 3 + 1);
        
        bobs_pokemons += bob_today_caught;
        jays_pokemons += jay_today_caught;
        
        cout << "Bob caught " << bob_today_caught << " (now he has " << bobs_pokemons << ")" << endl;
        cout << "Jay caught " << jay_today_caught << " (now he has " << jays_pokemons << ")" << endl;
        
        // Перевірка умов завершення парі
        if (bobs_pokemons >= 90 && jays_pokemons >= 90) {
            cout << "It is a tie!" << endl;
            cout << "Your bet was not successful!" << endl;
            return;
        }
        else if (bobs_pokemons >= 90) {
            cout << "Bob wins!" << endl;
            if (users_bet == 1) {
                cout << "Your bet paid off!" << endl;
            } else {
                cout << "Your bet was not successful!" << endl;
            }
            return;
        }
        else if (jays_pokemons >= 90) {
            cout << "Jay wins!" << endl;
            if (users_bet == 2) {
                cout << "Your bet paid off!" << endl;
            } else {
                cout << "Your bet was not successful!" << endl;
            }
            return;
        }
    }
}


// //Використовуючи функцію з завдання 2, напишіть функцію перевірки валідності дати. Коли вводиться число і місяць, а повертається, чи така дата існує.
// Додаткове завдання для фанатів: додайте для перевірки ще й рік ;)
// Тепер завдання: запитайте у користувача дату і кількість днів. Виведіть стільки дат підряд від заданої.


int days_in_month(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        // Перевірка на високосний рік
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return 29;
            else
                return 28;
    default:
        return -1; // Некоректний номер місяця
    }
}

bool is_valid_date(int day, int month, int year) {
    int days = days_in_month(month, year);
    if (days == -1) return false; // Некоректний номер місяця
    return day > 0 && day <= days;
}

void print_next_dates(int day, int month, int year, int count) {
    for (int i = 0; i < count; i++) {
        cout << day << "/" << month << "/" << year << endl;

        day++;
        
        int days_in_current_month = days_in_month(month, year);
        
        if (day > days_in_current_month) {
            day = 1;
            month++;
            
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
}


int main() {
    //
    multiplication_table();

    int month_number;
    cout << "Enter month number (1-12): ";
    cin >> month_number;

    int days = days_in_month(month_number);

    if (days <1)
        cout << "Invalid month number!" << endl;
    else
        cout << "Number of days: " << days << endl;
    //
    srand(time(0));
    competition();
    //
    competition_with_bet();
    //
    int day, month, year, count;

    cout << "Enter a day: ";
    cin >> day;

    cout << "Enter a month: ";
    cin >> month;

    cout << "Enter a year: ";
    cin >> year;

    if (!is_valid_date(day, month, year)) {
        cout << "Invalid date!" << endl;
        return 1;
    }

    cout << "Enter the number of consecutive days to print: ";
    cin >> count;

    print_next_dates(day, month, year, count);
    
    return 0;
}