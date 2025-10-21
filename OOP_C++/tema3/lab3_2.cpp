#include <iostream>
#include<cstring>
#include<ctime>

using namespace std;

class Student {
    string nume;
    string prenume;
    string CNP;
    int anNastere;
    string numeFac;
    int anInfiintare;

    public:

    void genCNP() {
        srand(time(NULL));

        string cnp="";

        ///Mai jos se verifica prima cifra,respectiv 5-masculin si 6-feminin pentru cei nascuti peste 2000 si 1-masculin 2-feminin pentru cei nascuti sub 2000
        int s;
        if (anNastere >= 2000) {
            if (rand() %2==1)
                cnp="5";
            else
                cnp="6";
        }
        else {
            if (rand() %2==1)
                cnp="1";
            else
                cnp="2";
        }

        ///Aici se adauga urmatoarele doua cifre, respectiv ultimele doua cifre din anul nasterii
        int aa=anNastere%100;

        ///Daca ultimele doua cifre din anul nasterii reprezina un numar mai mic ca 10 (ex:7,8) atunci trebuie adaugat 0 in fata acestuia pentru a aparea 07,08 in CNP
        if (aa<10) cnp+="0";
        cnp+=to_string(aa);

        ///Aici se ia o valoare aleatorie pentru luna si pentru zi
        int luna=rand()%12 +1;
        ///La zile consideram 28 de zile intr-o luna pentru a nu avea probleme de logica, spre exemplu 30 februarie
        int zi=rand() %28 +1;

        ///Aceeasi logica cu adaugarea unui 0 in fata ca mai sus la cifrele din anul nasterii
        if (luna<10) cnp+="0";
        cnp+=to_string(luna);
        if (zi<10) cnp+="0";
        cnp+=to_string(zi);

        ///Aici am adaugat ultimele 6 cifre complet aleatoriu
        for (int i=0;i<6;i++) {
            int cif=rand()%10;
            cnp+=to_string(cif);
        }

        ///Aici se calculeaza ultima cifra, cea de control dupa un algoritm pe care il voi cita mai jos, de pe Google
        /*Cifra de control a unui CNP este a 13-a cifră, folosită pentru a verifica corectitudinea codului. E
         *a se calculează prin înmulțirea fiecărei cifre a CNP-ului cu cifra corespondentă dintr-o constantă (279146358279),
         *adunarea rezultatelor și apoi împărțirea sumei la 11; restul acestei împărțiri, dacă este mai mic decât 10, este cifra de control, iar dacă este 10, cifra de control este 1. */

        string control="279146358279";

        int sum=0;
        for (int i=0;i<12;i++) {
            sum+=(cnp[i]-'0')*(control[i]-'0');
            int rest=sum%11;

            int cifControl;
            if (rest<10)
                cifControl=rest;
            else
                cifControl=1;

        }

        ///Apoi ne folosim de this pointer pentru a salva CNP-ul generat in adresa variabilei clasei
        this->CNP=cnp;
    }

    void setNume(string nume) {
        this->nume=nume;
    }
    void setPrenume(string prenume) {
        this->prenume=prenume;
    }
    void setCNP(string cnp) {
        this->CNP=cnp;
    }
    void setAnNastere(int anNastere) {
        this->anNastere=anNastere;
    }
    void setNumeFac(string numeFac) {
        this->numeFac=numeFac;
    }
    void setAnInfiintare(int anInfiintare) {
        this->anInfiintare=anInfiintare;
    }


    string getNume() {
        return this->nume;
    }
    string getPrenume() {
        return this->prenume;
    }
    string getCNP() {
        return this->CNP;
    }
    int getAnNastere() {
        return this->anNastere;
    }
    string getNumeFac() {
        return this->numeFac;
    }
    int getAnInfiintare() {
        return this->anInfiintare;
    }

    string getSex(string cnp) {
        char s=cnp[0];
        switch (s) {
            case '5': return "Masculin";
            case '6': return "Feminin";
            case '1': return "Masculin";
            case '2': return "Feminin";
            default: return "Necunoscut";
        }
    }

    int getVarsta() {

        time_t t=time(NULL);
        tm* tm = localtime(&t);

        ///Aici se calculeaza anul curent,se adauga 1900 deoarece ctime ia numarul de ani de la 1900 spre anul curent
        int curr=tm->tm_year+1900;

        return curr-anNastere;

    }

    int Diff() {
        return anInfiintare-anNastere;
    }

    void print() {
        cout << "Nume: " << nume << " " << prenume << endl;
        cout << "Anul nasterii: " << anNastere << endl;
        cout << "Varsta: " << getVarsta() << " ani" << endl;
        cout << "Facultatea: " << numeFac << " (" << anInfiintare << ")" << endl;
    }

};

int main() {
Student student1;
    student1.genCNP();
    student1.setNume("Popescu");
    student1.setPrenume("Matei");
    student1.setAnNastere(2004);
    student1.setNumeFac("UPB");
    student1.setAnInfiintare(1800);

    student1.print();
    cout<<student1.getSex(student1.getCNP())<<endl;
    return 0;



}