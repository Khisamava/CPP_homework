#include<iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Student
{
    const string First_Name;
    const string Last_Name;
    string group;
    int age;
    int xp;
    double money;
    int student_time;
    int semester_grade;
    
public:
        
    Student(const string& First_Name, const string& Last_Name, const string& group, int grade = 10)
    : First_Name(First_Name), Last_Name(Last_Name), group(group), age(19), xp(0), money(100), student_time(0), semester_grade(grade) {}
    
    void eat(double cost)
    {
        if (cost > money)
        {
            throw runtime_error("You don't have enought money for food :(");
        }
        money -= cost;
        xp += 5;
    }
    
    void study(int hours)
    {
        xp -= (student_time > 24) ? hours * 3 : hours;
        student_time += hours;
    }
    
    void sleep(int hours)
    {
        xp += hours * 2;
        if (hours > 6)
        {
            student_time = 0;
        }
    }
    
    void work(int hours)
    {
        xp -= (student_time > 24) ? hours * 3 : hours;
        money += hours * 10;
        student_time += hours;
    }
    
    void carma(int random_num)
    {
        if (random_num == 3)
        {
            xp += 10;
        }
        
        if(random_num == 7)
        {
            xp -= 10;
        }
    }
    
    void entertain(int hours, double cost)
    {
        if (cost > money)
        {
            throw runtime_error("You don't have enought money for entertain :( ");
        }
        xp += (student_time > 24) ? hours /3 : hours;
        money -= cost;
        student_time += hours;
    }
    
    int life_value() 
    {
        return xp;
    }
    
    double get_money()
    {
        return money;
    }
    
    int remaining_time()
    {
        return (24-student_time);
        
    }
    
    string student_info() const {
        return "Name: " + First_Name + ", Surname: " + Last_Name + ", Group: " + group +
               ", XP: " + to_string(xp) + ", Money: " + to_string(money);
    }
    
    void check_alive()
    {
        if (life_value() <= 0)
        {
            throw runtime_error("left to akadem");
        }
    }
};

int main()
{
   ///example of use
   
    Student student("Amina", "Khisamava", "B04-304");
    cout << student.student_info() << endl;

    student.eat(20);
    cout << student.student_info() << endl;

    student.study(5);
    cout << student.student_info() << endl;

    student.sleep(7);
    cout << student.student_info() << endl;

    student.work(2);
    cout << student.student_info() << endl;

    student.entertain(3, 15);
    cout << student.student_info() << endl;
    
    int ramdom_num = rand() % 10 + 1;
    student.carma(ramdom_num);
    cout << student.student_info() << endl;

    student.check_alive();
    
    
    
    return 0;
}
