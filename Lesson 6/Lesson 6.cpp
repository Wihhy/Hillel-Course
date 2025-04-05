// #include <iostream>
// #include <cstdlib>
// #include <ctime>
//
// using namespace std;
//
// // Функція для генерації випадкових чисел у заданому діапазоні
// int random_in_range(int min, int max) {
//     if (min > max) swap(min, max); // Міняємо місцями, якщо min > max
//     return min + rand() % (max - min + 1);
// }
//
// // Вивести на екран 10 випадкових чисел (від 0 до 20)
// void random_ten_numbers() {
//     for (int i = 0; i < 10; i++) {
//         cout << random_in_range(0, 20) << endl;
//     }
// }
//
// // Вивести всі числа підряд від 100 до 1
// void all_numbers_in_range() {
//     for (int i = 100; i >= 1; i--) {
//         cout << i << endl;
//     }
// }
//
// // Вивести всі числа підряд від переданого значення до 1
// void all_numbers_in_set_range(int start) {
//     for (int i = start; i >= 1; i--) {
//         cout << i << endl;
//     }
// }
//
// // Множити число на 2, доки воно не стане більше 10 000
// void multiplicator_till_10000(int number) {
//     int iterations = 0;
//     while (number < 10000) {
//         cout << number << endl;
//         number *= 2;
//         iterations++;
//     }
//     cout << "Final number: " << number << endl;
//     cout << "It took " << iterations << " iterations." << endl;
// }
//
// int main() {
//     srand(time(0)); // Ініціалізуємо генератор випадкових чисел
//
//     // Виклик функцій
//     random_ten_numbers();
//     all_numbers_in_range();
//
//     int start;
//     cout << "Enter a number to count down from: ";
//     cin >> start;
//     all_numbers_in_set_range(start);
//
//     int num;
//     cout << "Enter a number to multiply: ";
//     cin >> num;
//     multiplicator_till_10000(num);
//
//     return 0;
// }
