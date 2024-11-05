#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
    protected:
        string name;
        int age;
        int health;
    
    public:
        Animal(string name, int age, int health) : name(name), age(age), health(health) {}
        
        virtual void makeSound() = 0;
        
        void Info()
        {
            cout << "name - " << name << ", age - " << age << ", health - " << health << endl;
        }
        
        void Health(int new_health)
        {
            health = new_health;
        }
        
        int get_health()
        {
            return health;
        }
        
        string get_name()
        {
            return name;
        }
        
        int get_age()
        {
            return age;
        }
};

class Cat : public Animal
{
    public :
        Cat(string name, int age, int health) : Animal(name, age, health) {}
        
        void makeSound()
        {
            cout << "Meow" << endl;
        }
};

class Dog : public Animal
{
    public:
        Dog(string name, int age, int health) : Animal(name, age, health) {}
        
        void makeSound()
        {
            cout << "Raw" << endl;
        }
};

class Owner
{
    private:
        string name;
        int age;
        int pet_number;
        
    public:
        vector <Animal*> pets;
        
        Owner(string name, int age) : name(name), age(age), pet_number(0) {}
        
        void addPet(Animal* pet)
        {
            pets.push_back(pet);
            pet_number ++;
        }
        
        void owner_Info()
        {
            cout << "Owner - " << name << ", age - " << age << ", Amount of pets - " << pet_number << endl;
        }
        
        void pets_Info()
        {
            cout << "Pets - " << endl;
            
            for (auto pet : pets)
            {
                pet->Info();
            }
            
        }
        
};

class Veterinarian
{
    public:
    
        void check_up(Animal& animal)
        {
            cout << "check up is done for " << animal.get_name() << "." << endl;
        }
        
        void treat(Animal& animal, int health)
        {
            int current_health = animal.get_health();
            int new_health = current_health + health;
            
            if (new_health > 100)
            {
                new_health = 100;
            }
            
            if (new_health < 0)
            {
                new_health = 0;
            }
            
            animal.Health(new_health);
            cout << animal.get_name() << "current health - " << new_health << endl;
        }
        
};

int main()
{
    Cat* cat1 = new Cat("Matroskin", 5, 80);
    Dog* dog1 = new Dog("Sharik", 3, 90);
    
    Owner owner("Amina", 19);
    owner.addPet(cat1);
    owner.addPet(dog1);
    
    Veterinarian vet;
    
    owner.owner_Info();
    owner.pets_Info();
    
    vet.check_up(*cat1);
    vet.treat(*cat1, 10);
    vet.check_up(*dog1);
    vet.treat(*dog1, -20);
    
    cat1->makeSound();
    dog1->makeSound();
    
    delete cat1;
    delete dog1;
    
    return 0;
}

