#include<iostream>
#define DYNAMIC_MEMORY ///закомитить чтобы переключиться в режим статического массива 
#define arr_size 10

using namespace std;

void fill_print(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = i + 1; 
        std::cout << arr[i] << " "; 
    }
    cout << endl;
}

int main()
{
    #ifdef DYNAMIC_MEMORY
    
        int* array = new int[arr_size]; 
        fill_print(array, arr_size);
        delete[] array; 
        cout << "dinamic array" << endl;
        
    #else
    
        int array[arr_size]; 
        fill_print(array, arr_size);
        cout << "static array" << endl;
        
    #endif

    return 0;
}
