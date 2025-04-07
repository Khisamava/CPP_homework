#include <iostream>
#include <vector>
#include <ctime> // Для измерения времени

using namespace std;

// Функция пузырьковой сортировки с оптимизацией
void bubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) 
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

int main() 
{
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }

    // Засекаем время начала сортировки
    clock_t start = clock();

    bubbleSort(arr);

    // Засекаем время окончания сортировки
    clock_t end = clock();

    // Вычисляем затраченное время в секундах
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Время сортировки: " << duration << " секунд\n";

    return 0;
}
