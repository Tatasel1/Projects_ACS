#include <iostream>
#include<string>
using namespace std;
/*
 *Clasa carte nu este o abstractizare pura, deoarece avem nevoie de datele din aceasta
 *pentru a le folosi in clasa Biblioteca si in clasa CarteElectronica
*/

class Carte{
private:
    string titlu;
    string autor;
    int anPublicare;
    bool disp;

public:
    Carte(const string& t="", const string& a="", int an=0, bool d=true): titlu(t), autor(a), anPublicare(an), disp(d) {}

    string getTitlu() const {
        return titlu;
    }

    string getAutor() const {
        return autor;
    }

    int getPublicare() const {
        return anPublicare;
    }

    bool getDisp() const {
        return disp;
    }

    string setTitlu(const string &t) {
        titlu = t;
        return titlu;
    }

    virtual void afiseazaInfo() {}
    virtual void verifDisp() {}

    friend class Biblioteca;

};

/*
 *Functiile virtuale afiseazaInfo si verifDisp sunt suprascrise in clasa derivata CarteElectronica.
*/

class CarteElectronica : public Carte {
private:
    float dimensiuneMB;

public:
    CarteElectronica(const string &t ="", const string &a="", int an=0, bool d=true, float dim=0.0): Carte(t,a,an,d), dimensiuneMB(dim) {}

    void verifDisp() override{
        if(getDisp()) {
            cout<<"Cartea electronica "<<getTitlu()<<" este disponibila pentru descarcare."<<endl;
        }
        else {
            cout<<"Cartea electronica nu este disponibila pentru descarcare."<<endl;
        }
    }
    void afiseazaInfo() override {
        cout<<"Titlu: "<<getTitlu()<<endl;
        cout<<"Autor: "<<getAutor()<<endl;
        cout<<"An Publicare: "<<getPublicare()<<endl;
        cout<<"Disponibilitate: "<<(getDisp() ? "Disponibila" : "Indisponibila")<<endl;
        cout<<"Dimensiune (MB): "<<dimensiuneMB<<endl;
    }
};

class Biblioteca {
    public:
    void modifAutor(Carte &c, const string a) {
        if(c.autor != a) {
            c.autor = a;
            cout<<"Autorul a fost modificat!"<<endl;
        }
        else {
            cout << "Autorul este acelasi!" << endl;
        }
    }

     static void verifDispo(Carte &c) {
        if (c.disp) {
            cout<<"Cartea "<<c.titlu<<" este disponibila."<<endl;
        }
        else {
            cout<<"Cartea nu este disponibila."<<endl;
        }
    }

     static void afiseazaInformatii(Carte &c) {
        cout<<"Titlu: "<<c.titlu<<endl;
        cout<<"Autor: "<<c.autor<<endl;
        cout<<"An Publicare: "<<c.anPublicare<<endl;
        cout<<"Disponibilitate: "<<(c.disp ? "Disponibila" : "Indisponibila")<<endl;
    }

   friend void modifTitlu( Carte c, string t);
};

///functia modifTitlu este friend function al clasei Biblioteca.
void modifTitlu(Carte &c, const string t) {
    if(c.getTitlu() != t) {
        c.setTitlu(t);
        cout<<"Titlul cartii a fost modificat in "<<t<<endl;
    }
    else {
        cout << "Titlul este acelasi!" << endl;
    }
}

/*
 *Functia afiseazaInformatii nu este aceeasi cu afiseazaInfo, insa poate face acelasi lucru chiar daca afiseazaInfo este functie virtuala.
 *Acest lucru se datoreaza faptului ca Biblioteca este friend function al clasei Carte si poate accesa datele private ale acesteia.
 *Acelasi lucru este valabil si pentru functia verifDispo.
*/

int main() {
    Carte c1("Ion","Liviu Rebreanu",1920,true);
    Carte c2("Morometii","Marin Preda",1955,false);
    CarteElectronica ce1("1984","George Orwell",1949,true,1.5);

    Biblioteca b;

    Biblioteca::verifDispo(c1);
    Biblioteca::afiseazaInformatii(c1);

    cout<<endl;

    modifTitlu(c1,"Ional");
    Biblioteca::verifDispo(c1);
    Biblioteca::afiseazaInformatii(c1);

    cout<<endl;

    b.modifAutor(c2,"Marin Predut");
    Biblioteca::verifDispo(c2);
    Biblioteca::afiseazaInformatii(c2);

    cout<<endl;

    ce1.verifDisp();
    ce1.afiseazaInfo();

}