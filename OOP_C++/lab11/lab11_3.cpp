#include <iostream>
#include <string>
#include <vector>

class Handler {
    protected:
    Handler* next;
public:
    Handler* setNext(Handler* handler) {
        next = handler;
        return handler;
    }

    virtual void handle(int suma) {
        if (next) {
            next->handle(suma);
        }
    }
};

class Bancnota100 : public Handler {
public:
    void handle(int suma) override {
        if (suma >= 100) {
            int numarBancnote = suma / 100;
            suma = suma % 100;
            std::cout << "Predau " << numarBancnote << " bancnote de 100" << std::endl;
        }

            Handler::handle(suma);

    }
};

class Bancnota50 : public Handler {
public:
    void handle (int suma) override {
        if (suma >=50) {
            int numarBancnote = suma / 50;
            suma = suma % 50;
            std::cout << "Predau " << numarBancnote << " bancnote de 50" << std::endl;
        }

            Handler::handle(suma);

    }
};

class Bancnota10 : public Handler {
public:
    void handle (int suma) override {
        if (suma >= 10) {
            int numarBancnote = suma / 10;
            suma = suma % 10;
            std::cout << "Predau " << numarBancnote << " bancnote de 10" << std::endl;
        }

            Handler::handle(suma);

    }
};

int main() {
    Handler *h100 = new Bancnota100();
    Handler *h50 = new Bancnota50();
    Handler *h10 = new Bancnota10();

    h100->setNext(h50);
    h50->setNext(h10);

    std:: cout<< "Cer suma de 380 lei:" << std::endl;
    h100->handle(380);

    delete h50;
    delete h10;
    delete h100;

    return 0;
}
/*
 * Pattern-ul Chain of Responsibility este un Behavioral Pattern care permite trecerea cererilor de-a lungul unui lant de obiecte handler pana cand unul dintre ele se ocupa de cerere.
 * Avantajele acestuia includ permiterea controlului asupra ordinii cererilor, respectarea Single Responsibility Principle (deoarece se pot ignora ("decupla") clasele care invoca operatii de cele care le executa)
 * dar si respectarea Open/Closed Principle (deoarece se pot adauga noi handler-e fara a modifica codul existent).
 *
 * Dezavantajul principal al acestuia este ca unele request-uri au posibilitatea de a nu fi procesate niciodata daca niciun handler din lant nu le poate gestiona.
*/