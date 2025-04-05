#include <iostream>
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

int main()
{
    five_numbers();
    multiplication_table();
    return 0;
}

