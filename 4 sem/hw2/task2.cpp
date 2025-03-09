#include <iostream>
#include <map>
#include <string>

using namespace std;

class PhoneBook 
{
private:
    map<string, string> contacts;

public:
    // Добавление контакта
    void addContact(const string& name, const string& phoneNumber) 
    {
        contacts[name] = phoneNumber;
        cout << "Контакт добавлен: " << name << " - " << phoneNumber << endl;
    }

    // Удаление контакта
    void removeContact(const string& name) 
    {
        if (contacts.erase(name)) 
        {
            cout << "Контакт удален: " << name << endl;
        } 
        else 
        {
            cout << "Контакт не найден: " << name << endl;
        }
    }

    // Поиск контакта
    void searchContact(const string& name) const
    {
        auto it = contacts.find(name);
        if (it != contacts.end()) 
        {
            cout << "Найден контакт: " << it->first << " - " << it->second << endl;
        } 
        else 
        {
            cout << "Контакт не найден: " << name << endl;
        }
    }

    // Вывод всех контактов
    void ifContacts() const 
    {
        if (contacts.empty()) 
        {
            cout << "Телефонная книга пуста." << endl;
        } 
        else 
        {
            cout << "Список контактов:" << endl;
            for (const auto& [name, phone] : contacts) 
            {
                cout << name << " - " << phone << endl;
            }
        }
    }
};

int main() 
{
    PhoneBook phoneBook;
    int choice;
    string name, phone;

    do 
    {
        cout << "\nМеню:\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Удалить контакт\n";
        cout << "3. Найти контакт\n";
        cout << "4. Показать все контакты\n";
        cout << "5. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера ввода

        switch (choice) 
        {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                cout << "Введите номер телефона: ";
                getline(cin, phone);
                phoneBook.addContact(name, phone);
                break;
            case 2:
                cout << "Введите имя для удаления: ";
                getline(cin, name);
                phoneBook.removeContact(name);
                break;
            case 3:
                cout << "Введите имя для поиска: ";
                getline(cin, name);
                phoneBook.searchContact(name);
                break;
            case 4:
                break;
            case 5:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } 

    while (choice != 5);

    return 0;
}
