#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>  // Для rand и srand
#include <ctime>    // Для time (сета генератора случайных чисел)

using namespace std;

void fillArray(vector<int>& arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        arr[i] = rand() % 1000 + 1;  // Генерация случайных чисел от 1 до 1000
    }
}

int main() {
    const int SIZE = 10000;  // Размер массива
    int num_threads;

    // Вводим количество потоков
    cout << "Введите количество потоков: ";
    cin >> num_threads;

    vector<int> arr(SIZE);
    vector<thread> threads;

    // Инициализация генератора случайных чисел(чтобы с каждым запуском программы генерировались разные числа)
    srand(static_cast<unsigned int>(time(0)));

    // Разбиваем работу между потоками
    int chunk_size = SIZE / num_threads;
    
    for (int i = 0; i < num_threads; ++i) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? SIZE : (i + 1) * chunk_size;
        threads.push_back(thread(fillArray, ref(arr), start, end));
    }

    // Ожидаем завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    // Печатаем часть массива для проверки (что значения случайные)
    cout << "Часть массива: ";
    for (int i = 0; i < 20; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
