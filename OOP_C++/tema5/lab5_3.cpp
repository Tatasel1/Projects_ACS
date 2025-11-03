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
    public:
    overLoad() {
        s1="Ceva.";
        s2="Mai Mult";
    }
    void operator +() {
        this->s1=this->s1+this->s2;
    }

    void operator -() {
        string aux="";
        int k=0;
        for (int i=0;i<s1.length();i++) {
            char c=s1[i];
            if (c == '.' || c==',') {
                parti[k++]=aux;
                aux="";
            }
            else {
                aux+=c;
            }
        }
        if (!aux.empty()) {
            parti[k++] = aux;
        }
        for (int i = k; i < 10; i++) {
            parti[i] = "";
        }

    }

    void getSir() {
        cout<<"Sir1: "<<this->s1<<endl;
        cout<<"Sir2: "<<this->s2<<endl;
    }

    void getParti() {
        for (int i=0;i<10;i++)
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