#include <iostream>
#include <string>
#include <vector>

class IRobot {
public:
    virtual void walk() = 0;
    virtual ~IRobot() {}
};

class Human {
public:
    void run() {
        std::cout << "Human is running" << std::endl;
    }
};

class HumanAdapter : public IRobot {
    Human* human;
public:
    HumanAdapter(Human* human) : human(human) {}
    void walk() override {
        human->run();
    }
};

int main() {
    Human* human = new Human();
    IRobot* robotAdapter = new HumanAdapter(human);

    robotAdapter->walk();

    delete robotAdapter;
    delete human;
    return 0;
}

/*
 * Adapter este un Structural Pattern care permite obiectelor cu interfete incompatibile sa lucreze impreuna prin convertirea interfetei unui obiect intr-o alta interfata pe care clientul o asteapta.
 *
 * Avantajele acestui pattern pot fi respectarea Single Responsibility Principle (separa responsabilitatile intre clasele care folosesc si cele care sunt folosite)
 * si respectarea Open/Closed Principle (permite adaugarea de noi adaptori fara a modifica codul existent).
 *
 * Dezavantajul acestui pattern este faptul ca se modifica complexitatea codului prin introducerea unor clase suplimentare (adaptori).
*/