#include <iostream>
#include <iso646.h>
#include <string>
using namespace std;

/*Попросіть користувача ввести 5 чисел, а потім покажіть їх користувачеві заново в один рядок, а потім у зворотному порядку.*/

void five_numbers()
{
    int n1, n2, n3, n4, n5;

    // Ввід чисел
    cout << "Enter 5 numbers: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    // Виведення чисел у порядку введення
    cout << "Numbers in entered order: " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;

    // Виведення чисел у зворотному порядку
    cout << "Numbers in reverse order: " << n5 << " " << n4 << " " << n3 << " " << n2 << " " << n1 << endl;
}


// Візьміть задачу з попереднього ДЗ і розширте її: Виведіть на екран всю таблицю множення від 1 до 10


void multiplication_table()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
}


/*Що таке "красиве" число? Це число не менше 70, але не більше 500. Це число ділиться на 3, але не ділиться на 8.
 *Або у нього всі цифри однакові*.
Попросіть користувача ввести "красиве число" і не відчепіться від нього поки він його не введе.
Таких чисел нам треба від користувача 4. Виведіть середнє з них.*/


bool is_same_digits(int number) {
    string s = to_string(abs(number));
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

bool is_beautiful(int n) {
    return (n >= 70 && n <= 500 && n % 3 == 0 && n % 8 != 0) || is_same_digits(n);
}

void beautiful_number_finder()
{
    int beautiful_numbers_amount = 0;
    int sum = 0;

    while (beautiful_numbers_amount < 4) {
        int number_from_user;
        cout << "Enter a beautiful number: ";
        cin >> number_from_user;

        if (is_beautiful(number_from_user)) {
            cout << "NICE ONE! Now one more please :)\n";
            sum += number_from_user;
            beautiful_numbers_amount++;
        } else {
            cout << "Not beautiful enough. Try again.\n";
        }
    }

    double average = static_cast<double>(sum) / 4;
    cout << "Finally you are done!" << endl;
    cout << "The average of your beautiful numbers is: " << average << endl;
}


// Намалюйте ялиночку. Напишіть функцію, яка отримує кількість рівнів ялинки й потім відповідно її малює.


void draw_tree(int levels) {
    for (int i = 1; i <= levels; i++) {

        for (int star = 1; star <= i; star++) {
            cout << "*";
        }

        for (int plus = 1; plus <= i; plus++) {
            cout << "+";
        }
        cout << endl;
    }
}

int random_pokemons() {
    return 3 + rand() % 4;
}

void competition() {
    int goal;
    cout << "Enter initial goal for the competition: ";
    cin >> goal;

    int bob_wins = 0;
    int jay_wins = 0;

    while (bob_wins < 3 && jay_wins < 3) {
        int bob_total = 0;
        int jay_total = 0;
        int day = 1;

        cout << "\nCompetition started with goal " << goal << endl;

        while (bob_total < goal && jay_total < goal) {
            int bob_today = random_pokemons();
            int jay_today = random_pokemons();

            bob_total += bob_today;
            jay_total += jay_today;

            cout << "DAY " << day << endl;
            cout << "Bob caught " << bob_today << " (total: " << bob_total << ")" << endl;
            cout << "Jay caught " << jay_today << " (total: " << jay_total << ")" << endl;
            day++;
        }
        
        if (bob_total >= goal && jay_total >= goal) {
            cout << "It's a tie. They decided to rematch. Competition goal is " << goal << "." << endl;
        } else if (bob_total >= goal) {
            bob_wins++;
            cout << "Bob wins!" << endl;
            if (bob_wins < 3) {
                cout << "Jay demands rematch! ";
                goal += goal / 2;
                cout << "Competition goal is now " << goal << "." << endl;
            }
        } else if (jay_total >= goal) {
            jay_wins++;
            cout << "Jay wins!" << endl;
            if (jay_wins < 3) {
                cout << "Bob demands rematch! ";
                goal += goal / 2;
                cout << "Competition goal is now " << goal << "." << endl;
            }
        }
    }

    cout << "\n=== FINAL RESULT ===" << endl;
    if (bob_wins == 3) {
        cout << "Bob wins 3 times! He is the final winner!" << endl;
    } else {
        cout << "Jay wins 3 times! He is the final winner!" << endl;
    }
}


int main()
{
    five_numbers();
    
    multiplication_table();
    
    beautiful_number_finder();

    int levels;
    cout << "Enter number of levels: ";
    cin >> levels;

    draw_tree(levels);

    srand(time(0));
    competition();
    
    return 0;
}

