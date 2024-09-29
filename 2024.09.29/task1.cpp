#include <iostream>
#include <cmath>

using namespace std;

bool simple_num(int number)
{
   if (number <= 0 || number == 1)
   {
        return false;
    } 
    else if (number == 2) 
    {
        return true;
    } 
    else if (number % 2 == 0 && number != 2) {
        return false; 
    }
    
    int max_del = sqrt(number);
    for (int i = 3; i <= max_del; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
 
}

int main() 
{
    int num;
    cout << "enter integer >0" << endl;
    cin >> num;
    
    if (simple_num(num))
    {
        cout << "number is simple" << endl;
    }
    else
    {
        for(int k = num -1; k >= 1; k --)
        {
            if (num%k == 0)
            {
                cout << k << endl;
                break;
            }
        }
    }
    return 0;
    
}