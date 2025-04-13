#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Завести масив A, заповнити його випадковими числами, а потім тричі вивести його на екран.
// Виділити великий (10000+) масив на купі, заповнити його випадковими числами,
// показати й вивести суму елементів з індексами 1000 і 2000.

void Task1() {
    srand(time(0));

    const int SIZE = 10;
    int A[SIZE];
    
    for (int i = 0; i < SIZE; ++i)
        A[i] = rand() % 100;
    
    cout << "Array A (x3):" << endl;
    for (int t = 0; t < 3; ++t) {
        for (int i = 0; i < SIZE; ++i)
            cout << A[i] << " ";
        cout << endl;
    }
    
    const int BIG_SIZE = 10000;
    int* bigArray = new int[BIG_SIZE];

    for (int i = 0; i < BIG_SIZE; ++i)
        bigArray[i] = rand() % 1000;

    cout << "\nElements at 1000 and 2000: " 
         << bigArray[1000] << ", " << bigArray[2000] << endl;
    cout << "Sum = " << (bigArray[1000] + bigArray[2000]) << endl;

    delete[] bigArray;
}

void print_even_values(const int arr[], int size) {
    cout << "Even values: ";
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";
    }
    cout << endl;
}

/*Завести масив. Заповнити його випадковими числами, вивести його на екран.
Написати процедуру яка виводить лише елементи з парними значеннями, наприклад (так, 0 - це теж парне):*/

void Task2() {
    const int SIZE = 13;
    int A[SIZE];

    for (int i = 0; i < SIZE; ++i)
        A[i] = rand() % 21 - 10;

    cout << "Full array: ";
    for (int i = 0; i < SIZE; ++i)
        cout << A[i] << " ";
    cout << endl;

    print_even_values(A, SIZE);
}
void print_even_indices(const int arr[], int size) {
    cout << "Values at even indices: ";
    for (int i = 0; i < size; i += 2)
        cout << arr[i] << " ";
    cout << endl;
}

/*Завести масив. Заповнити його випадковими числами, вивести його на екран.
Написати процедуру яка виводить лише елементи з парними індексами, наприклад:*/

void Task3() {
    const int SIZE = 13;
    int A[SIZE];

    for (int i = 0; i < SIZE; ++i)
        A[i] = rand() % 21 - 10;

    cout << "Full array: ";
    for (int i = 0; i < SIZE; ++i)
        cout << A[i] << " ";
    cout << endl;

    print_even_indices(A, SIZE);
}
double get_average(const int arr[], int size) {
    long long sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return static_cast<double>(sum) / size;
}

int get_max_value(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

/*Завести масив. Заповнити його випадковими числами, вивести його на екран.
3.1 Порахувати середнє арифметичне елементів масиву.
3.2 Порахувати максимальне значення серед елементів масиву.
3.3 Зробити те ж саме, але виділити масив на купі розміром 500 000 елементів (можна не виводити).*/

void Task4() {
    const int SIZE = 20;
    int A[SIZE];

    for (int i = 0; i < SIZE; ++i)
        A[i] = rand() % 100;

    cout << "Full array: ";
    for (int i = 0; i < SIZE; ++i)
        cout << A[i] << " ";
    cout << endl;

    cout << "Average: " << get_average(A, SIZE) << endl;
    cout << "Max value: " << get_max_value(A, SIZE) << endl;


    const int BIG_SIZE = 500000;
    int* bigArray = new int[BIG_SIZE];

    for (int i = 0; i < BIG_SIZE; ++i)
        bigArray[i] = rand() % 1000000;

    cout << "\nBig array (500k):" << endl;
    cout << "Average: " << get_average(bigArray, BIG_SIZE) << endl;
    cout << "Max value: " << get_max_value(bigArray, BIG_SIZE) << endl;

    delete[] bigArray;
}
int main() {
    Task1();
    cout << "\n============================\n";
    Task2();
    cout << "\n============================\n";
    Task3();
    cout << "\n============================\n";
    Task4();
    return 0;
}
