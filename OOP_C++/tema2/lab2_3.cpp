#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

class ManagerFisier {
public:
    std::ofstream fisier;

    ManagerFisier(const char* nume_fisier) {
        fisier.open(nume_fisier);
        if (fisier.is_open()) {
            cout<<"Fisier deschis"<<"\n";
        }
        else cout<<"Eroare";
    }
    ~ManagerFisier() {
        fisier.close();
        cout<<"Fisier inchis"<<"\n";
    }

    void scrie(const std::string& mesaj) {
        cout<<"Scriere in fisier...."<<"\n";
        fisier<<mesaj<<"\n";
    }
};


int main() {
    {
        ManagerFisier fisMeu("FisierMeu.txt");
        fisMeu.scrie("Salutare OOP!!!!!");
    }

return 0;
}