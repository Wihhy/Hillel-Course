#include <iostream>
#include <cstdlib>
#include <ctime> 
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

// Bonus task 0
void swaper (const int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = len-1; i >= 0; i--)
    {
        cout << arr[i] << ' '; 
    }
    cout << endl;

}

/*Написати процедуру (з сигнатурою void (const int [], int))
 *яка виводить елементи масиву в порядку: перший, останній, другий, передостанній, третій... і т.д. без повторів.*/

void shifter (const int arr[], int len)

{
    print_array(arr, len);
    
    for (int i = 0, j = len-1; i < j; ++i, j--)
    {
        cout << arr[i] << " " << arr[j] << " ";
    }
    if (len % 2 != 0) {
        cout << arr[len / 2];
    }
    cout << endl;
}

/*В масив закралися погані числа! Треба їх обнулити!
Напишіть процедуру void ClearValue(int arr[], int size, int badValue)
яка міняє на 0 всі значення що дорівнюють заданому (badValue).*/

void clear_value(int arr[], int size, int bad_value)
{
    print_array(arr, size);
    
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == bad_value)
        {
            arr[i] = 0;
        }
    }
    
    print_array(arr, size);
}

/*Написати функцію (з сигнатурою int (const char *) ), яка в заданій стрічці рахує кількість слів.*/

int words_counter (const char *str)
{
    if (!str || str[0] == '\0')
        return 0;
    int count = 0;
    bool in_word = false;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (std::isspace(str[i]))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            ++count;
            in_word = true;
        }
    }

    return count;
}

/*Написати процедуру (з сигнатурою void (const char *)),
 *яка в заданій стрічці рахує і виводить на екран кількість голосних і приголосних літер.*/

void count_vowels_consonants(const char* str)
{
    if (!str)
        return;

    int vowels = 0;
    int consonants = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        char ch = tolower(str[i]);

        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
                ++vowels;
            else
                ++consonants;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}

/*Написати процедуру (з сигнатурою void (int *, int)),
 *яка в масиві знаходить мінімальне значення і міняє його місцями з першим елементом масиву.*/

void swap_min_to_front(int* arr, int size)
{
    if (!arr || size <= 1) return;
    
    print_array(arr, size);

    int min_index = 0;

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[min_index])
            min_index = i;
    }
    
    if (min_index != 0)
    {
        int temp = arr[0];
        arr[0] = arr[min_index];
        arr[min_index] = temp;
    }
    print_array(arr, size);
}


int main()
{
    srand(time(0));
    
    cout << endl << "Task 0" << endl; //SPLITTER
    
    int* arr = new int[12];
    arr_random_filler(arr, 12, -10000, 10000);
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    swaper(arr,12);
    
    cout << endl << "Task 1" << endl; //SPLITTER
    
    int* arr_shft = new int[12];
    arr_random_filler(arr_shft, 12, -100, 100);
    // int arr_shft[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    shifter(arr_shft, 12);

    cout << endl << "Task 1 Alternative" << endl; //SPLITTER
    
    int* arr_shft_alt = new int[13];
    arr_random_filler(arr_shft_alt, 13, -100, 100);
    // int arr_shft_alt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    shifter(arr_shft_alt, 13);

    cout << endl << "Task 2" << endl; //SPLITTER

    int* arr_clear = new int[13];
    arr_random_filler(arr_clear, 13, 0, 10);
    clear_value(arr_clear, 13, 7);

    cout << endl << "Task 3" << endl; //SPLITTER

    cout << words_counter("The quick brown fox jumps over the lazy dog") << endl;

    cout << endl << "Task 4" << endl; //SPLITTER
    
    count_vowels_consonants("The quick brown fox jumps over the lazy dog");

    cout << endl << "Task 5" << endl; //SPLITTER

    int* arr_swap_min = new int[13];
    arr_random_filler(arr_swap_min, 13, 0, 20);
    swap_min_to_front(arr_swap_min,13);

    
    return 0;
}
