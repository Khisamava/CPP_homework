#include<iostream>
#include<string>

using namespace std;

int main()
{
    string main_string, sub_string;
    int main_len, sub_len, index;
    int count = 0;
    
    cout << "enter strings" << endl;
    cin >> main_string;
    cin >> sub_string;
    
    main_len = main_string.length();
    sub_len = sub_string.length();
    
    int i = 0;
    while(i <(main_len - sub_len))
    {
        index = main_string.find(sub_string, i);
        
        if(index == string::npos)
        {
            break;
        }
        count ++;
        i = index + sub_len - 1;
    }
    
    cout << count << endl;
    
    return 0;
}
