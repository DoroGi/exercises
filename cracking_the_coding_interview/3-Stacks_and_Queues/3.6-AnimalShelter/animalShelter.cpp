#include <chrono>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Animal
{
public:
    string name;
    int arrivalTime;
    Animal(string n, int t)
    {
        name = n;
        arrivalTime = t;
    };
};

class Dog :public Animal
{
public:
    Dog(string n, int t) :Animal(n, t){};
};
class Cat :public Animal
{
public:
    Cat(string n, int t) :Animal(n,t){};
};

enum kind { dog, cat };

class AnimalShelter
{
private:
    int order;
    list<Dog*>* dogs;
    list<Cat*>* cats;
public:    
    AnimalShelter()
    {
        order=0;
        dogs = new list<Dog*>;
        cats = new list<Cat*>;
    }
    ~AnimalShelter()
    {
        delete dogs;
        delete cats;
    }
    void enqueue(kind race, string name)
    {
        if (race == kind::dog)
        {
            dogs->push_back(new Dog(name, order++));
            int diocane = dogs->size();
        }
        else if (race == kind::cat)
        {
            cats->push_back(new Cat(name, order++));
        }
    }
    Animal* dequeueAny()
    {
        bool catIsOlder = dogs->front()->arrivalTime > cats->front()->arrivalTime;
        if (catIsOlder) return (Animal*)dequeueCat();
        else return (Animal*)dequeueDog();
    };
    Dog* dequeueDog()
    {
        Dog* result = dogs->front();
        dogs->pop_front();
        return result;
    };
    Cat* dequeueCat()
    {
        Cat* result = cats->front();
        cats->pop_front();
        return result;
    };
};

int main()
{
    AnimalShelter* shelter = new AnimalShelter;
    shelter->enqueue(dog, "Fuffi");
    shelter->enqueue(dog, "Cane");
    shelter->enqueue(cat, "Sr. Truffles");
    shelter->enqueue(dog, "Pallina");
    shelter->enqueue(cat, "Snack");
    shelter->enqueue(cat, "Gatto");
    shelter->enqueue(cat, "Sfigatto");
    shelter->enqueue(dog, "Charlie");
    cout << shelter->dequeueAny()->name << endl;
    cout << shelter->dequeueDog()->name << endl;
    cout << shelter->dequeueAny()->name << endl;
    cout << shelter->dequeueDog()->name << endl;
    cout << shelter->dequeueCat()->name << endl;
    return 0;
}