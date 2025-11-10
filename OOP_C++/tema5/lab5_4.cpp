#include <stdio.h>
#include <iostream>
using namespace std;

class Animal {
    public:
    void sound() {
        cout<<"Every animal has a specific sound\n";
    }
};

class Cat : public Animal {
    public:
    void sund() override{
        cout<<"Meow\n";
    }
};

class Dog : public Animal {
    public:
    void sound(){
        cout<<"Woof\n";
    }
};

int main() {
    Animal necunoscut;
    Cat pisica;
    Dog caine;

    necunoscut.sound();
    pisica.sound();
    caine.sound();

    pisica.Animal::sound();
    caine.Animal::sound();

    return 0;

}