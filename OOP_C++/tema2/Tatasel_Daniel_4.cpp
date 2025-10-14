#include <stdio.h>
#include <iostream>
#include<cstring>

using namespace std;

class Sibling {
    public:
    string *nume;
    string *prenume;
    int *varsta;
    Sibling(){}

    Sibling(string n,string p,int v) {
        nume=new string(n);
        prenume=new string(p);
        varsta=new int(v);
    }

    /* am definit deep copy cu parametru un obiect din clasa sibling
    new string si new int se comporta ca new char din exemplu, aloca dinamic memorie pentru variabila respectiva
    apoi copiaza datele in noua variabila, returnand pointer catre noul sir de caractere
    acelasi lucru se intampla si mai sus doar ca acolo se vor salva variabile definite mai jos in main*/
    Sibling(const Sibling &s) {

        nume=new string(*s.nume);
        prenume=new string(*s.prenume);
        varsta=new int(*s.varsta);

    }

    ///aici se face acelasi lucru, doar ca pt functia de update ,pentru a se putea creea noul obiect
    Sibling(const Sibling *s) {
        delete nume;
        delete prenume;
        delete varsta;

        nume=new string(*s->nume);
        prenume=new string(*s->prenume);
        varsta=new int(*s->varsta);

    }

    ~Sibling() {}

};

int main()
{
    Sibling sibling1("Mihai","Andronache",22);
    Sibling sibling2;

    cout << *sibling1.nume <<" "<<*sibling1.prenume<<" "<<*sibling1.varsta<<" "<<endl;

    sibling2=Sibling(sibling1);///aici se apeleaza constructorul de update

    cout << *sibling2.nume <<" "<<*sibling2.prenume<<" "<<*sibling2.varsta<<" "<<endl;

    return 0;
}
