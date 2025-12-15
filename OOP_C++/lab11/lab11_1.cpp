#include <iostream>
#include <string>
#include <vector>

/* COMPOSITE DESIGN PATTERN */

class Componenta {
public:
    virtual void deschide() = 0;
    virtual void inchide() = 0;
    virtual void adauga(Componenta* c) {}

    virtual ~Componenta() {}

};


class Fisier: public Componenta {
    std::string nume;
public:
    explicit Fisier(std::string nume) : nume(nume) {}
    void deschide() override {
        std::cout << "Deschid fisierul: " << nume << std::endl;
    }
    void inchide() override {
        std::cout << "Inchid fisierul: " << nume << std::endl;
    }

};

class FolderComposite: public Componenta {
    std::string nume;
    std::vector<Componenta*> componente;
public:
    FolderComposite(std::string nume = "Root") : nume(nume) {}
    void adauga(Componenta* c) override {
        componente.push_back(c);
    }

    void deschide() override {
        std::cout << "Deschid folderul: " << nume << std::endl;
        for (auto& c : componente) {
            c->deschide();
        }
    }

    void inchide() override {
        std::cout << "Inchid folderul: " << nume << std::endl;
        for (auto& c : componente) {
            c->inchide();
        }
    }
};

int main() {

    FolderComposite *root = new FolderComposite();
    root->adauga(new Fisier("Hello World"));

    FolderComposite *subFolder1 = new FolderComposite("Subfolder 1");
    subFolder1->adauga(new Fisier("Subfile 1"));
    subFolder1->adauga(new Fisier("Subfile 2"));

    root->adauga(subFolder1);

    root->deschide();
    root->inchide();

    delete root;
    delete [] subFolder1;
    return 0;
}

/*
 * Composite Design Pattern este un pattern structural care permite tratarea ierarhiilor de obiecte compuse si simple in mod uniform.
 * Acesta simuleaza structura unui arbore, cu radacina, noduri si frunze.
 * Avantajele acestui pattern pot fi faptul ca simplifica structurile complexe de arbori, folosind polimorfismul.
 * Principiul Open/Closed este respectat. Acesta presupune ca entitatile software (clase, module, functii etc.) trebuie sa fie deschise pentru extindere, dar inchise pentru modificare.
 * In pattern, acest principiu se observa prin faptul ca putem adauga noi tipuri de componente (de exemplu, noi tipuri de fisiere sau foldere) fara a modifica codul existent al componentelor.
 *
 * Dezavantajul acestui pattern poate fi dificultatea de a oferi o interfata comuna claselor care au functionalitati diferite, obligand la "suprageneralizarea" interfetei.
 * Pe scurt unele obiecte trebuie tratate ca avand aceleasi functionalitati cu altele, chiar daca ele nu le au in mod natural.
 * Acest lucru poate face logica mai greude inteles.
 */