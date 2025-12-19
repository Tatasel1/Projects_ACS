#include <iostream>
#include <string>
#include <vector>


class Lion;
class Giraffe;

class IVisitor {
public:
    virtual void visit(Lion *lion) = 0;
    virtual void visit(Giraffe *giraffe) = 0;
    virtual ~IVisitor() = default;
};
class IAnimal {
public:
    virtual void accept(IVisitor* visitor) = 0;
    virtual ~IAnimal() = default;
};

class Lion : public IAnimal {
public:
    void accept(IVisitor* visitor) override {
        visitor->visit(this);
    }

    void roar() {
        std::cout << "Lion: Roar!" << std::endl;
    }
};

class Giraffe : public IAnimal {
public:
    void accept(IVisitor* visitor) override {
        visitor->visit(this);
    }

    void bendNeck() {
        std::cout << "Giraffe: Bending Neck!" << std::endl;
    }
};

class AnimalVisitor : public IVisitor {
public:
    void visit(Lion *lion) override {
        lion->roar();
    }
    void visit(Giraffe *giraffe) override {
        giraffe->bendNeck();
    }
};

int main() {
    std::vector<IAnimal*> zoo;
    zoo.push_back(new Lion());
    zoo.push_back(new Giraffe());

    AnimalVisitor* visitor = new AnimalVisitor();

    std::cout<<"Visited Animals in the Zoo:"<<std::endl;
    for (auto animal : zoo) {
        animal->accept(visitor);
    }

    for (auto animal : zoo) {
        delete animal;
    }
    delete visitor;

    return 0;
}

/*
 * Visitor este un Behavioral Pattern care permite adaugarea de noi operatii la obiectele dintr-o structura fara a modifica clasele obiectelor.
 *
 *Avantajele acestui pattern pot fi respectarea Open/Closed Principle (permite adaugarea de noi operatii fara a modifica clasele obiectelor)
 *si a Single Responsibility Principle (se pot muta versiuni multiple ale aceluasi behaviour in aceeasi clasa).
 *Totodata este foarte util atunci cand structura obiectelor este complexa si stabila, iar operatiile asupra acestor obiecte se schimba frecvent, cum ar fi arborii.
 *
 *Dezavantajele acestui pattern sunt faptul ca toti visitorii trebuie sa fie modificati atunci cand se adauga o noua clasa de obiecte in structura
 *si ca visitorii nu pot accesa membrii privati ai obiectelor pe care le viziteaza.
 *
 */