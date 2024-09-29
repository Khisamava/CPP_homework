#include <iostream>


using namespace std;

int main() 
{
    int n;
    int tmp;
    cout << "enter the size of the array" << endl;
    cin >> n;
    int *array {new int[n]};         //создаем динамический массив на n символов
    array[0] = 0;
    
    for(int i = 1; i < n+1; i++)
    {
        cin >> tmp;
        if (tmp > 0)
        {
            array[i] = array[i-1] + tmp;
            cout << array[i] << endl;
        }
        if (tmp < 0)
        {
            array[i] = array[i-1];
            cout << array[i] << endl;
        }
        if (tmp == 0)
        {
            cout << "end of programm because of 0" << endl;
            break;
        }
    }
    
    
    
    return 0;
}