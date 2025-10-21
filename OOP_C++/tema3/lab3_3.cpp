#include <iostream>
#include<stdio.h>
#include<cstring>
#include<ctime>

using namespace std;

class ContBancar {
    string titularCont;
    double sold;
public:
    ContBancar(string titCont,double sld) {
        this->titularCont=titCont;
        this->sold=sld;
    }

    const string getTitular() {
        return this->titularCont;
    }

    const double getSold() {
        return this->sold;
    }

    void depune(double suma) {
        this->sold+=suma;
    }

    void retrage(double suma) {
        if (suma<this->sold) {
            this->sold-=suma;
            cout<<"S-a retras suma RON "<<suma<<endl;
        }
        else cout<<"Fonduri insuficiente"<<endl;
    }

    private:
    static double rataDobanda;

public:
    static void seteazaRataDobanda(double rataNoua) {
        rataDobanda=rataNoua;
    }

    void aplicaDobanda() {

        double d=rataDobanda*this->sold;
        this->sold+=d;

    }

    void prinCont() {
        cout<<this->titularCont<<" "<<this->sold<<endl;
    }
};

double ContBancar::rataDobanda=0;


int main(){
    ContBancar cont1("Andreescu Mihai",13600.2341),cont2("Dinca Angela",23.456);

    cont1.depune(1230.234);
    cont2.depune(10);
    cont1.retrage(1230.234);
    cont2.retrage(1230.234);

    double s1=cont1.getSold();
    double s2=cont2.getSold();

    cout<<"Sold cont 1 "<<s1<<"\n"<<"Sold cont 2 "<<s2<<endl;

    ContBancar::seteazaRataDobanda(0.07);

    cont1.aplicaDobanda();
    cont2.aplicaDobanda();
    cont1.prinCont();
    cont2.prinCont();

    return 0;

  }