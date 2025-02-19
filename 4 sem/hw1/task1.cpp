#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Container>

void Print(const Container& container, const string& devider) {
    bool first = true;
    for (const auto& element : container) 
    {
        if (!first)
        {
            cout << devider;
        }
        cout << element;
        first = false;
    }

    cout << '\n';
}

int main() 
{
    vector<int> data = {1, 2, 3};
    Print(data, ", "); // Вывод: 1, 2, 3
    return 0;
}




