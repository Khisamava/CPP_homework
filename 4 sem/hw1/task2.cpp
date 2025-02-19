#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void split_sort(const vector<int>& numbers, vector<int>& positive, vector<int>& negative) {
    for (int num : numbers)
     {
        if (num > 0) 
        {
            positive.push_back(num);
        } 

        else if (num < 0) 
        {
            negative.push_back(num);
        }
    }
    
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
}

int main() 
{
    vector<int> positive, negative;

    vector<int> numbers;
    int n, num;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " int numbers: ";

    for (int i = 0; i < n; ++i)
     {
        cin >> num;
        numbers.push_back(num);
    }
    
    split_sort(numbers, positive, negative);
    
    cout << "Positive numbers: ";
    for (int num : positive)
    {
        cout << num << " ";
    }

    cout << endl;
    
    cout << "Negative numbers: ";
    for (int num : negative) 
    {
        cout << num << " ";
    }

    cout << endl;
    
    return 0;
}
