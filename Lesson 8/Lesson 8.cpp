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


bool is_same_cifers (int number)
{
    int number_length = to_string(abs(number)).length();
    string number_string = to_string(number);
    for (int i = 1; i <= number_length; i++)
    {
        if (number_string[i] != number_string[i - 1])
        {
            return false;
        }
    }
    return true;
    
}

void beautiful_number_finder()
{
    int beautiful_numbers_amount = 0;
    while (beautiful_numbers_amount < 5) {
        int number_from_user;
        cout << "Enter a beautiful number: ";
        cin >> number_from_user;
        if (number_from_user < 70 || number_from_user > 499) {
            cout << "Not beautiful enough. Try again.\n";
        }
        else if (number_from_user % 3 != 0)
        {
            cout << "Not beautiful enough. Try again.\n";
        }
        else if (number_from_user % 8 == 0)
        {
            cout << "Not beautiful enough. Try again.\n";
        }
        else if (!is_same_cifers(number_from_user))
        {
            cout << "Not beautiful enough. Try again.\n";
        }
        else
        {
            cout << "NICE ONE! Now one more please :)\n";
            beautiful_numbers_amount++;
        }
    }
    cout <<"Finally you are done!"<< endl;
}


int main()
{
    five_numbers();
    
    multiplication_table();
    
    beautiful_number_finder();
    
    return 0;
}

