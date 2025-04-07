#include <iostream>
#include <vector>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time(), clock()

using namespace std;

// Функция сортировки пузырьком
void bubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) 
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение массива случайными числами
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % 1000; // Числа от 0 до 999
    }

    // Засекаем время с помощью clock()
    clock_t start = clock();
    bubbleSort(arr);
    clock_t end = clock();

    // Вывод отсортированного массива
    cout << "Отсортированный массив:\n";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Подсчёт и вывод времени
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Время сортировки: " << duration << " секунд" << endl;

    return 0;
}
