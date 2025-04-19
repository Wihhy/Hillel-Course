#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


void arr_random_filler(int arr[], int len, int min = -10, int max = 10)
{
    for (int i = 0; i < len; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void print_array(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}


/*Напишіть процедуру яка знаходить мінімальний елемент не по всьому масиві,
а лише у його “хвості” (наприклад від 5 до останнього) і повертає індекс знайденого.*/


int find_min_in_tail(int* arr, int size, int start_index)
{
    if (!arr || size <= 1 || start_index >= size) return -1;
    

    int min_index = 0;

    for (int i = start_index; i < size; ++i)
    {
        if (arr[i] < arr[min_index])
            min_index = i;
    }
    
    return min_index;

}


/*Напишіть процедуру яка додає обмін місцями елементу з “початку хвоста”
 *на знайдений мінімальний (схоже як в попередньому ДЗ).*/


void find_min_in_tail_and_swap(int* arr, int size, int start_index)
{
    if (!arr || size <= 1 || start_index >= size) return;
    

    int min_index = 0;

    for (int i = start_index; i < size; ++i)
    {
        if (arr[i] < arr[min_index])
            min_index = i;
    }
    
    if (min_index != 0)
    {
        int temp = arr[start_index];
        arr[start_index] = arr[min_index];
        arr[min_index] = temp;
    }

}







int main()
{
    srand(time(0));
    
    cout << endl << "Task 0" << endl; //SPLITTER
    
    int arr_size_TASK1 = 12;
    int* arr_TASK1 = new int[arr_size_TASK1];
    int start_index_TASK1 = 10;
    
    arr_random_filler(arr_TASK1, 12, -10, 10);
    
    print_array(arr_TASK1, arr_size_TASK1);
    cout << "Starting from index: " << start_index_TASK1 <<". The index of minimal value is: "
    << find_min_in_tail(arr_TASK1,arr_size_TASK1, start_index_TASK1) << endl;

    delete[] arr_TASK1;
    
    cout << endl << "Task 1" << endl; //SPLITTER

    int arr_size_2 = 12;
    int* arr_2 = new int[arr_size_TASK1];
    int start_index_2 = 10;
    
    arr_random_filler(arr_2, 12, -10, 10);
    
    print_array(arr_2, arr_size_2);
    find_min_in_tail_and_swap(arr_2, arr_size_2, start_index_2);
    print_array(arr_2, arr_size_2);
    delete[] arr_2;
    
    
    return 0;
}
