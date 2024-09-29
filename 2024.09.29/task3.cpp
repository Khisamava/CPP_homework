#include <iostream>


using namespace std;

int main() 
{
    int n;
    int sum = 0;
    cout << "enter the size of array" << endl;
    cin >> n;
    int array[n];
    
    for (int i = 0; i < n; i++)
    {
        *(array + i) = i * i;
        sum = sum + *(array+i);
    }
    
    cout << "sum = " << sum << endl;
    return 0;
}