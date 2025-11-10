#include <iostream>
#include <cstring>
using namespace std;
/*iau ca parametru de clasa si vectorul de string uri parti pentru a salva in el toate partile din sirul original pe care vreau sa l despart prin "-"
o alta alternativa at fi fost sa declar operatorul ca string * acesta fiind return type unde returnam vectorul parti
prin aceasta metoda nu mai declaram parti ca variabila a clasei*/
class overLoad {
    string s1;
    string s2;
    string parti[10];
    int nr_elem_parti;
public:
    overLoad() {
        s1="Ceva.";
        s2="Mai Mult";
    }
    void operator +() {
        this->s1=this->s1+this->s2;
    }

    void operator -() {
        string aux = "";
        nr_elem_parti = 0;
        string siruri[2] = {s1, s2};
        ///aici bucla for pentru j itereaza prin cele doua siruri s1 si s2
        for (int j = 0; j < 2; j++) {
            string& s = siruri[j];
            aux="";
            ///aici cauta in fiecare din siruri . sau , pentru delimitare, daca nu exista delimitare se salveaza sirul initial in parti
            for (int i = 0; i < s.length(); i++) {
                char c = s[i];
                if (c == '.' || c == ',') {
                    if (!aux.empty()) {
                        parti[nr_elem_parti++] = aux;
                        aux = "";
                    }
                } else {
                    aux += c;
                }
            }
            if (!aux.empty()) {
                parti[nr_elem_parti++] = aux;
            }
        }



        for (int i = nr_elem_parti; i < 10; i++) {
            parti[i] = "";
        }
    }

    void getSir() {
        cout<<"Sir1: "<<this->s1<<endl;
        cout<<"Sir2: "<<this->s2<<endl;
    }

    void getParti() {
        for (int i=0;i<nr_elem_parti;i++)
            cout<<this->parti[i]<<endl;

    }
};

int main() {
    overLoad o1;
    +o1;
    o1.getSir();
    -o1;
    o1.getParti();
}