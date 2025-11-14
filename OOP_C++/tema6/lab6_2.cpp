#include <iostream>
#include<string>
using namespace std;

class Carte{
private:
    string titlu;
    string autor;
    int anPublicare;
    bool disp;

public:
    Carte(string t="", string a="", int an=0, bool d=true): titlu(t), autor(a), anPublicare(an), disp(d) {}

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

    virtual void modifTitlu(string t,string a) {}

    virtual void afiseazaInfo(){}



    friend class Raft;
    friend class Biblioteca;

};

class Raft: public Carte{
protected:
    int nr_raft;
public:
    Raft(string t="", string a="", int an=0, bool dis=true, int nr=0)
      : Carte(t, a, an, dis), nr_raft(nr) {}

    void cautaDisp(Carte &c) {
        if (c.disp == true) {
            cout<<"Cartea "<<c.titlu<<" este disponibila.\n";
        } else {
            cout<<"Cartea "<<c.titlu<<" nu este disponibila.\n";
        }
    }

    void afiseazaInfo() override{
        cout<<"Carte: "<<titlu<<", Autor: "<<autor<<", An Publicare: "<<anPublicare<<", Nr Raft: "<<nr_raft<<endl;

    }

    friend void modifRaft(Raft &r, int nr);

};

class Biblioteca:public Raft{
    public:
    Biblioteca():Raft("","",0,false,0) {}

    void modifTitlu(string t,string a) override {
        if (a==autor) {
            titlu = t;
            cout<<"Titlul cartii a fost modificat la "<<titlu<<".\n";
        }
        else {
            cout<<"Datele autorului nu corespund. Titlul nu a fost modificat.\n";
        }
    }

    void imprumutaCarte(Carte &c,Raft &r) {
        if (c.disp == true) {
            c.disp = false;
            cout<<"Ai imprumutat \n ";
            r.afiseazaInfo();
        } else {
            r.afiseazaInfo();
            cout<<endl<<"Nu este disponibila pentru imprumut.\n";
        }
    }


};

void modifRaft(Raft &r, int nr) {
    r.nr_raft = nr;
    cout<<"Numarul raftului a fost modificat la "<<r.nr_raft<<".\n";
}

int main() {
    Raft r1("Enigma Otiliei","George Calinescu",1938,true,5);
    Biblioteca b;
    Carte c1("Ion","Liviu Rebreanu",1920,true);
    Carte c2("Morometii","Marin Preda",1955,false);
    b.imprumutaCarte(c2,r1);
    b.modifTitlu("Ionelule","George Calinescu");


}