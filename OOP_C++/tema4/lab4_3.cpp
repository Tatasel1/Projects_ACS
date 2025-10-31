#include <iostream>

using namespace std;

class Baza {
public: void metodaPublica() {
        cout<<"Baza metodaPublica"<<endl;

    }
protected: void metodaProtected() {
        cout<<"Baza metodaProtected"<<endl;
    }
private: void metodaPrivate() {
    cout<<"Baza metodaPrivate"<<endl;

    }
};

class DerivataProtected:protected Baza {
    public:
    void testAccesInterior() {
        metodaPublica();
        metodaProtected();
        metodaPrivate();
    }
};

class DerivataPrivata: private Baza {
    public:
    void testAccesInterior() {
        metodaPublica();
        metodaProtected();
        metodaPrivate();
    }
};

int main() {
    DerivataProtected objProt;
    DerivataPrivata objPriv;
    objProt.metodaPublica();
    objProt.testAccesInterior();
    objPriv.testAccesInterior();
    objPriv.metodaPublica();
    return 0;
}


/*
 *In testAccesInterior() din ambele clase, nu a compilat decat metodaPrivate() deoarece in clasa parinte aceasta este declarata ca private,
 *ceea ce inseamna ca in clasele derivate este inaccesibila
 *
 *objProt.metodaPublica() nu a compilat, desi el e declarat public in clasa parinte deoarece clasa DerivataProtected mosteneste PROTECTED din baza Parinte.
 *Acest lucru duce la convertirea in interiorul clasei copil a tuturor metodelor,mai putin cea private, care este inaccesibila, in protected, ceea ce inseamna ca ele pot fi apelate decat in interiorul clasei si a claselor derivate acesteia, si nu in afara,respectiv main()
 *
 *objPriv.metodaPublica nu a compilat din acelasi motiv,convertind metodele in private de aceasta data, ceea ce inseamna ca nu vor putea fi apelate DECAT in interiorul clasei respective, nu si in afara ei.
 *
 */
