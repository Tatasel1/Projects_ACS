#include <stdio.h>
#include <iostream>
#include<cstring>

using namespace std;

class Sibling {
public:
    char *nume;
    char *prenume;
    int *varsta;

    Sibling(){}

    Sibling(const char *n,const char *p,const int v) {

        int size1=strlen(n);
        int size2=strlen(p);

        nume=new char[size1+1];
        strcpy (nume, n);

        prenume=new char[size2+1];
        strcpy (prenume, p);

        varsta=new int(v);


    }


   void update(const char *n,const char *p,const int v) {


        int size1=strlen(n);
        int size2=strlen(p);

        nume=new char[size1+1];
        strcpy (nume, n);

        prenume=new char[size2+1];
        strcpy (prenume, p);

        varsta=new int(v);

    }

    Sibling(const Sibling &s) {
        int size1=strlen(s.nume);
        int size2=strlen(s.prenume);

        nume=new char[size1+1];
        strcpy (nume, s.nume);

        prenume=new char[size2+1];
        strcpy (prenume, s.prenume);

        varsta=new int(*s.varsta);
    }

    ~Sibling() {}

};

int main()
{
    Sibling sibling1("Mihai","Andronache",22);
    Sibling sibling2;

    cout << sibling1.nume <<" "<<sibling1.prenume<<" "<<*sibling1.varsta<<" "<<endl;

    sibling2.update("Andrada","Andronache",21);

    cout << sibling2.nume <<" "<<sibling2.prenume<<" "<<*sibling2.varsta<<" "<<endl;

    return 0;
}