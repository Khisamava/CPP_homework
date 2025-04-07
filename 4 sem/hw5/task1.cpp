#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void printHelloWorld(int thread_id, int total_threads) 
{
    cout << "Поток " << thread_id << " из " << total_threads << " потоков: HelloWorld\n";
}

int main() 
{
    int num_threads;
    
    cout << "Введите количество потоков: ";
    cin >> num_threads;

    vector<thread> threads;

    for (int i = 0; i < num_threads; ++i) 
    {
        threads.push_back(thread(printHelloWorld, i + 1, num_threads));
    }

    // Ожидание завершения всех потоков
    for (auto& t : threads) 
    {
        t.join();
    }

    return 0;
}
///можно заметить что вывод разный, это связанно с тем, 
///что потоки могут получать одновременный доступ в консоль
///поэтому из раза в раз порядок записи строк будет разный и рандомный