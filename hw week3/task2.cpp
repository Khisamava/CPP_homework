#include<iostream>
#include <string>


using namespace std;

template <typename T>

int find_element(T* arr, int size, T element) 
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == element) 
        {
            return i; // возвращаем индекс найденного элемента
        }
    }
    return -1; //  возвращаем -1, тк элемент не найден 
}

int main()
{
    string type;
    int size;
    
    cout<<"Enter type of array?"<< endl;
    cin >> type;
    cout<<"Enter number of elements?"<< endl;
    cin >> size;
    cout<<"Enter elements"<< endl;
    
    if (type == "int")
    {
        int array[size];
        for (int i = 0; i < size ; i++) {
            cin >> array[i];
        }
        
        int elem;
        cout << "Enter sought element" << endl;
        cin >> elem;
        find_element(array, size, elem);
    }
    
    if (type == "float")
    {
        float array[size];
        for (int i = 0; i < size ; i++) {
            cin >> array[i];
        }
        
        float elem;
        cout << "Enter sought element" << endl;
        cin >> elem;
        find_element(array, size, elem);
    }
    
    if (type == "char")
    {
        char array[size];
        for (int i = 0; i < size ; i++) {
            cin >> array[i];
        }
        
        char elem;
        cout << "Enter sought element" << endl;
        cin >> elem;
        find_element(array, size, elem);
    }

    return 0;
}
