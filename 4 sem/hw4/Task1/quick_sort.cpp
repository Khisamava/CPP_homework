#include <iostream>
#include <vector>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time(), clock()

using namespace std;

// Функция для обмена элементов
void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

// Разделение массива и возврат индекса опорного элемента
int partition(vector<int>& arr, int low, int high) 
{
    int current = arr[high]; // выбираем последний элемент как опорный
    int i = low - 1;

    for (int j = low; j < high; ++j) 
    {
        if (arr[j] < current) 
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Быстрая сортировка (рекурсивная)
void quickSort(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int currentIndex = partition(arr, low, high);
        quickSort(arr, low, currentIndex - 1);
        quickSort(arr, currentIndex + 1, high);
    }
}

int main() 
{
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Генерация случайных чисел
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % 1000; // числа от 0 до 999
    }

    // Засекаем время сортировки
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();

    // Вывод отсортированного массива
    cout << "Отсортированный массив:\n";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Подсчёт времени сортировки
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Время сортировки: " << duration << " секунд" << endl;

    return 0;
}
