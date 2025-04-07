#include <iostream>
#include <vector>
#include <thread>
#include <algorithm> // Для binary_search
#include <functional> // Для ref

using namespace std;

// Функция для слияния двух отсортированных частей массива
void merge(vector<int>& arr, int left, int mid, int right) 
{
    vector<int> left_part(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> right_part(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < left_part.size() && j < right_part.size()) 
    {
        if (left_part[i] <= right_part[j]) 
        {
            arr[k++] = left_part[i++];
        } 
        else 
        {
            arr[k++] = right_part[j++];
        }
    }

    while (i < left_part.size()) 
    {
        arr[k++] = left_part[i++];
    }

    while (j < right_part.size()) 
    {
        arr[k++] = right_part[j++];
    }
}

// Функция сортировки слиянием, с использованием потоков для параллельного выполнения
void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        
        // Разделение задачи на два потока
        thread left_thread([&arr, left, mid]() 
        {
            mergeSort(arr, left, mid);
        });
        
        thread right_thread([&arr, mid, right]() 
        {
            mergeSort(arr, mid + 1, right);
        });

        // Ожидание завершения обоих потоков
        left_thread.join();
        right_thread.join();

        // Слияние двух отсортированных частей
        merge(arr, left, mid, right);
    }
}

// Функция для поиска значения с использованием бинарного поиска
bool binarySearch(const vector<int>& arr, int target) 
{
    int left = 0, right = arr.size() - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) 
        {
            return true;
        } 
        else if (arr[mid] < target) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return false;
}

int main() 
{
    int n, target;
    
    // Ввод размера массива
    cout << "Введите размер массива: ";
    cin >> n;
    
    vector<int> arr(n);
    
    // Ввод массива
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }

    // Ввод значения для поиска
    cout << "Введите значение для поиска: ";
    cin >> target;

    // Сортировка массива с использованием потоков
    mergeSort(arr, 0, n - 1);

    // Печать отсортированного массива
    cout << "Отсортированный массив:\n";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Поиск значения в отсортированном массиве
    bool found = binarySearch(arr, target);

    if (found) 
    {
        cout << "Значение " << target << " найдено в массиве.\n";
    } 
    else 
    {
        cout << "Значение " << target << " не найдено в массиве.\n";
    }

    return 0;
}
