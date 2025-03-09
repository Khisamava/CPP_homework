#include <iostream>
#include <deque>
#include <string>

using namespace std;

struct Task 
{
    string description;
    bool high_priority; ///true - высокий приоритет, false - низкий

    Task(string desc, bool priority) : description(desc), high_priority(priority) {}
};


class TaskQueue 
{
private:
    deque<Task> queue;

public:
    void addTask(const string& description, bool high_priority) 
    {
        if (high_priority) 
        {
            queue.emplace_front(description, high_priority);
        }
        else 
        {
            queue.emplace_back(description, high_priority);
        }
    }

    void processTask()
    {
        if (queue.empty()) 
        {
            cout << "Ты выполнил все задачи, молодец!" << endl;
            return;
        }
        
        Task task = queue.front();
        queue.pop_front();
        
        cout << "Выполняется задача: " << task.description << " (" << (task.high_priority ? "Высокий" : "Низкий") << " приоритет)\n";
    }

    void showQueueSize() const 
    {
        if (queue.empty()) 
        {
            cout << "Задач больше нет" << endl;
        } 
        else 
        {
            cout << "В очереди " << queue.size() << " задач(и)" << endl;
        }
    }
};

int main() 
{
    TaskQueue taskQueue;
    
    taskQueue.addTask("Сделать информатику", true);
    taskQueue.addTask("Поспать", false);
    taskQueue.addTask("Приготовить ужин", false);
    taskQueue.addTask("сделать дифуры", true);
    
    taskQueue.showQueueSize();
    
    taskQueue.processTask();
    taskQueue.processTask();
    taskQueue.processTask();
    taskQueue.processTask();
    taskQueue.processTask();
    
    taskQueue.showQueueSize();
    
    return 0;
}
