#include <iostream> 
#include <map> //  библиотека для использования словаря (ассоциативного массива)
#include <string> 
#include <sstream> // строковые потоков
#include <cctype> //  работа с символами (например, преобразование в нижний регистр)

using namespace std;

// Функция для приведения слова к нижнему регистру и удаления знаков препинания
string change_text(const string& word) 
{
    string result; 
    for (char c : word) 
    { 
        if (isalpha(c)) // Проверяем, является ли символ буквой
        { 
            result += tolower(c); // Преобразуем букву в нижний регистр
        }
    }

    return result;
}

int main() {
    map<string, int> word_count; // Создаём словарь для подсчёта количества вхождений 
    string line, word; 

    
    while (getline(cin, line))
    { 
        stringstream ss(line); //  поток для обработки строки

        while (ss >> word) 
        { 
            string good_word = change_text(word); 
            if (!good_word.empty()) 
            { 
                word_count[good_word]++; 
            }
        }
    }

    
    string max_word; 
    int max_count = 0; 

    for (const auto& entry : word_count) 
    { 
        if (entry.second > max_count || (entry.second == max_count && entry.first < max_word)) 
        {
            max_word = entry.first; 
            max_count = entry.second; 
        }
    }

    cout << max_word << endl; 
    return 0; 
}
