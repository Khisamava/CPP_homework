#include <iostream>
#include <vector>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time() и clock()

using namespace std;

// Слияние двух отсортированных подмассивов
void merge(vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создание временных массивов
    vector<int> L(n1), R(n2);

    // Копирование данных во временные массивы
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k++] = L[i++];
        } 
        else 
        {
            arr[k++] = R[j++];
        }
    }

    // Копирование оставшихся элементов
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Рекурсивная сортировка слиянием
void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // Сортировка левой и правой части
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Слияние отсортированных частей
        merge(arr, left, mid, right);
    }
}

int main() 
{
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Генерация случайного массива
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % 1000; // значения от 0 до 999
    }

    // Засекаем время
    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    clock_t end = clock();

    // Вывод отсортированного массива
    cout << "Отсортированный массив:\n";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Подсчёт времени
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Время сортировки: " << duration << " секунд" << endl;

    return 0;
}
