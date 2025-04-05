// #include <cstdio>
// #include <iostream>
// #include <ostream>
// using namespace std;
//
// /*Напишіть процедуру (без параметрів, назву придумайте самі),
// яка виводить на екран віршик:*/
//
//
// void ghost_writer()
// {
//     cout<<"Hickory, dickory, dock,\n"
//           "The mouse ran up the clock;\n"
//           "The clock struck one,\n"
//           "And down he run,\n"
//           "Hickory, dickory, dock.\n";
// }
//
// /*Реалізуйте задачу 3 з попередньої ДЗ за допомогою процедури*/
//
// void set_alarm(int day_of_week, int month)
// {
//     // Validation
//     if (day_of_week > 7 || day_of_week < 1 || month > 12 || month < 1){
//         cout << "Invalid date\n";
//         return;
//     }
//     
//     if (month == 7 || month == 10)
//     {
//         if (day_of_week <= 5)
//         {
//             cout << "Alarm is at 10\n";
//         }
//         else
//         {
//             cout << "Alarm is off\n";
//         }
//     }
//     else
//     {
//         if (day_of_week <= 5)
//         {
//             cout << "Alarm is at 7\n";
//         }
//         else
//         {
//             cout << "Alarm is at 10\n";
//         }
//     }
// }
//
//
// /*Ви влаштовуєте чайно-кондитерську вечірку.
// Програма має дати відповідь, як пройде вечірка (“чудово”, “добре” чи “нудно”)
// Вечірка вважається доброю, якщо на ній було 5 чи більше тістечок та чашок чаю..
// Якщо при цьому чашок чаю було вдвічі більше ніж тістечок (або тістечок вдвічі більше ніж чаю), вечірка вважається чудовою.
// В будь-якому випадку, якщо чашок чаю чи тістечок було менш ніж 5, вечірка вважається нудною.
// Напишіть процедуру, яка приймає два параметри: кількість тістечок та кількість чашок чаю.
// Вона має вивести на екран результат вечірки (“чудово”, “добре” чи “нудно”).
// Для перевірки викличте її декілька разів з різними параметрами.
// Опціонально: реалізуйте її як функція, що повертає string.*/
//
//
// string party_fun_meter(int cakes_amount, int tea_cups_amount)
// {
//     // Validation
//     if (tea_cups_amount <= 0 || cakes_amount <= 0)
//     {
//         return "Invalid input\n";
//     }
//     
//     if (tea_cups_amount < 5 || cakes_amount < 5)
//     {
//         return "The party is boring.\n";
//     }
//     else if ((cakes_amount / tea_cups_amount >= 2 ) || (tea_cups_amount / cakes_amount >= 2))
//     {
//         return "The party is perfect.\n";
//     }
//     else
//     {
//         return "The party is good.\n";
//     }
//
// }
//
// /*Попросіть користувача ввести 2 числа і скажіть пощастить йому чи ні.
// 7 - щасливе число, отже якщо будь-яке з двох чисел 7, або їх сума 7, або їх різниця 7, значить людині пощастить.
// Наприклад:
// Enter two numbers: 22 15
// You are lucky!
// Треба написати функцію, яка приймає два параметри й повертає bool: пощастить чи ні.*/
//
//
// bool is_lucky(int num1, int num2)
// {
//     return (num1 == 7 ||
//         num2 == 7 ||
//         abs(num1 - num2) == 7 ||
//         num1 + num2 == 7);
//     
// }
//
//
// int main()
// {
//     ghost_writer();
//     ghost_writer();
//     ghost_writer();
//     ghost_writer();
//     
//     set_alarm(1,2);
//     set_alarm(7,5);
//     set_alarm(8,6);
//     
//     cout << party_fun_meter(2, 2);
//     cout << party_fun_meter(30, 3);
//     cout << party_fun_meter(14, 7);
//     cout << party_fun_meter(15, 8);
//     
//     int num1, num2;
//     cout << "Enter two numbers: ";
//     cin >> num1 >> num2;
//     if (is_lucky(num1, num2)) {
//         cout << "You are lucky!" << endl;
//     } else {
//         cout << "Better luck next time!" << endl;
//     }    return 0;
// }