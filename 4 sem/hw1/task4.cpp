#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool BracketLine(const string& s) 
{
    stack<char> stk;  // Стек для хранения открывающих скобок

    for (char ch : s) 
    {
        if (ch == '(' || ch == '[' || ch == '{') 
        {
            stk.push(ch);  // Добавляем в стек
        } 
        else 
        {
            // Если стек пуст, а пришла закрывающая скобка — ошибка
            if (stk.empty()) return false;

            char top = stk.top();
            stk.pop(); // Убираем верхний элемент

            // Проверяем соответствие пар скобок
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) 
            {
                return false;
            }
        }
    }
    return stk.empty(); // Если стек пуст — последовательность правильная
}

int main() 
{
    string input;
    cout << "Введите скобочную последовательность: ";
    cin >> input;

    if (BracketLine(input)) 
    {
        cout << "Правильная скобочная последовательность\n";
    } 
    else 
    {
        cout << "Неправильная скобочная последовательность\n";
    }

    return 0;
}

