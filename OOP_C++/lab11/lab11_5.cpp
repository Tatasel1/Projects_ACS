#include <iostream>
#include <string>
#include <vector>

class Motor {
public:
    void reving() {
        std::cout << "Motor revving up!" << std::endl;
    }
};

class Gearbox {
public:
    void changeGear(int gear) {
        std::cout << "Changing to gear " << gear << std::endl;
    }
};

class Drift {
public:
    void drift() {
        std::cout << "Drifting!" << std::endl;
    }

};

class CarFacade {
    Motor* motor;
    Gearbox* gearbox;
    Drift* drift;
public:
    CarFacade() {
        motor = new Motor();
        gearbox = new Gearbox();
        drift = new Drift();
    }

    void enjoyCar() {
        std::cout << "Enjoying Car!" << std::endl;
        motor->reving();
        gearbox->changeGear(1);
        drift->drift();
    }
};


int main() {
    CarFacade* car = new CarFacade();
    car->enjoyCar();

    delete car;
    return 0;
}

/*
 * Facade este un Structural Pattern care ofera o interfata simplificata pentru un set complex de clase, oferind simplitate user-ului final.
 *
 * Avantajele acestui pattern pot fi reducerea complexitatii prin ascunderea detaliilor interne si oferirea unei interfete usor de utilizat.
 *
 * Dezavantajele pot fi faptul ca facade-ul poate deveni un "god object" daca incearca sa acopere prea multe functionalitati.
 * Un "god object" este un obiect care cunoaste prea multe sau face prea multe lucruri, ceea ce poate duce la o incalcare a principiului Single Responsibility si la dificultati in mentenanta codului.
*/