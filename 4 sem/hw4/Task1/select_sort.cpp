#include <iostream>
#include <vector>
#include <cstdlib>  // Для rand(), srand()
#include <ctime>    // Для time(), clock()

using namespace std;

// Сортировка выбором
void selectionSort(vector<int>& arr) 
{
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) 
    {
        int minIndex = i;

        // Поиск минимального элемента в неотсортированной части
        for (int j = i + 1; j < n; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        // Обмен текущего элемента с найденным минимумом
        if (minIndex != i) 
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() 
{
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Создание и заполнение массива случайными числами
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % 1000; // числа от 0 до 999
    }

    // Засекаем время начала сортировки
    clock_t start = clock();
    selectionSort(arr);
    clock_t end = clock();

    // Вывод отсортированного массива
    cout << "Отсортированный массив:\n";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Подсчёт и вывод времени сортировки
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Время сортировки: " << duration << " секунд" << endl;

    return 0;
}
