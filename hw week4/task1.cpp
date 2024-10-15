#include<iostream>
#include <vector>


using namespace std;

struct Veeectorrr
{
    vector <double> elements;
    
    Veeectorrr(const vector<double>& elems) : elements(elems) {}
    
    
    // Функция умножения вектора на число
    Veeectorrr operator*(double number) const 
    {
        Veeectorrr result(elements);
        for (double& elem : result.elements)
        {
            elem *= number;
        }
        return result;
    }
    
    // Функция сложения векторов
    Veeectorrr operator+(const Veeectorrr& other) const
    {
        if (elements.size() != other.elements.size()) 
        {
            throw std::invalid_argument("Vectors must have the same dimension for addition.");
        }
        Veeectorrr result(elements);
        for (size_t i = 0; i < result.elements.size(); ++i)
        {
            result.elements[i] += other.elements[i];
        }
        return result;
    }
    
    // Функция скалярного произведения векторов
    double multiply(const Veeectorrr& other) const
    {
        if (elements.size() != other.elements.size())
        {
            throw std::invalid_argument("Vectors must have the same dimension for dot product.");
        }
        double result = 0.0;
        for (size_t i = 0; i < elements.size(); ++i)
        {
            result += elements[i] * other.elements[i];
        }
        return result;
    }
    
    // Функция для вывода вектора
    void print() const
    {
        cout << "(";
        for (size_t i = 0; i < elements.size(); ++i)
        {
            cout << elements[i];
            if (i < elements.size() - 1) 
            {
                cout << ", ";
            }
        }
        cout << ")\n";
    }

};

int main()
{
    Veeectorrr v1({});
    Veeectorrr v2({});
    int n1, n2;
    double rate;
    cout << "Enter size of vector 1" << endl;
    cin >> n1;
    cout << "Enter size of vector 2" << endl;
    cin >> n2;
    cout <<  "Full vector 1" << endl;
    for(int i = 0; i < n1; i++) 
    {
        double x;
        cin >> x;
        v1[i] = x;
    }
    cout << "Full vector 2" << '\n';
    for(int j = 0; j < n2; j++) {
        double x;
        cin >> x;
        v2[j] = x;
    }
    
    // Умножение вектора на число
    cout << "Enter rate you want to multiply on" << endl;
    cin >> rate;
    Veeectorrr v3 = v1 * rate;
    v3.print();
    
    // Сложение векторов
    Veeectorrr v4 = v1 + v2;
    v4.print();
    
    // Скалярное произведение векторов
    double multiply_result = v1.multiply(v2);
    cout << "Multiply result " << multiply_result << endl; 

    return 0;
}
