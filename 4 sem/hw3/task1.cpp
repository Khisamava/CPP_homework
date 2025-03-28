#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

void Height(const string& person, map<string, int>& heights, map<string, string>& parentMap) 
{
    if (heights.find(person) != heights.end()) 
    {
        return;
    }
    if (parentMap.find(person) == parentMap.end()) 
    {
        heights[person] = 0;
        return;
    }
    
    string parent = parentMap[person];
    if (heights.find(parent) == heights.end()) 
    {
        Height(parent, heights, parentMap); ///рекурсивный вызов для расчета высоты родителя
    }
    heights[person] = heights[parent] + 1;
}

int main() {
    ifstream input("input.txt");
    if (!input) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    int N;
    input >> N;
    map<string, string> parentMap;
    set<string> people;
    
    for (int i = 0; i < N - 1; ++i) {
        string child, parent;
        input >> child >> parent;
        parentMap[child] = parent;
        people.insert(child);
        people.insert(parent);
    }
    
    map<string, int> heights;
    for (const auto& person : people) {
        Height(person, heights, parentMap);
    }
    
    for (const auto& entry : people) {
        cout << entry << " " << heights[entry] << endl;
    }
    
    return 0;
}
