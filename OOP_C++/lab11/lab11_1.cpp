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


