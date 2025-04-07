#include <iostream>
#include <vector>
#include <ctime> // Для измерения времени
#include <cstdlib> // Для генерации случайных чисел

using namespace std;

// Функция сортировки вставками
void insertionSort(vector<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Функция быстрой сортировки
int partition(vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) 
    {
        if (arr[j] <= pivot) 
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Гибридная сортировка (быстрая + сортировка вставками)
void hybridSort(vector<int>& arr, int low, int high) 
{
    if (high - low <= 10) 
    { 
        insertionSort(arr, low, high);
    } else { // Иначе используем быструю сортировку
        quickSort(arr, low, high);
    }
}

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n);

    // Генерация случайных чисел для массива
    srand(time(0));
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = rand() % 1000; // Генерация случайных чисел от 0 до 999
    }

    // Засекаем время начала сортировки
    clock_t start = clock();

    // Сортировка с использованием гибридного подхода
    hybridSort(arr, 0, n - 1);

    // Засекаем время окончания сортировки
    clock_t end = clock();

    // Вычисляем затраченное время в секундах
    double duration = double(end - start) / CLOCKS_PER_SEC;

    // Вывод отсортированного массива
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Вывод времени сортировки
    cout << "Время сортировки: " << duration << " секунд\n";

    return 0;
}
