#include<iostream>
using namespace std;

class Student{
  public:
    string nume;
    string prenume;
    string grupa;
    string placut;
    string neplacut;
    string am_facut_vara;
    string vreau_sa_fac;

};

int main(){
    Student Tatasel;

    Tatasel.nume = "Tatasel";
    Tatasel.prenume = "Daniel-Valentin";
    Tatasel.grupa = "322AC";
    Tatasel.placut = "La laboratorul de PA mi-a placut intreaga desfasurare. As dori sa fie pastrat in special felul in care se bazeaza pe intrebari de interviu";
    Tatasel.neplacut="La lab-ul de PA nu au fost lucruri care sa imi displaca in mod special,dar temele ar putea fi pana duminica";
    Tatasel.am_facut_vara="Vara aceasta am incercat sa ma explorez pe mine insumi si sa imi dau seama de ce vreau sa fac cu adevarat.";
    Tatasel.vreau_sa_fac="Dupa ce termin facultatea, as dori sa imi dau foc la laptop-ul de acum si sa imi iau un MacBook, sa ma angajez,evident si sa incep sa calatoresc in Europa pentru inceput";

    cout<<Tatasel.nume<<" "<<Tatasel.prenume<<endl<<Tatasel.grupa<<endl<<endl<<Tatasel.placut<<endl<<endl<<Tatasel.neplacut<<endl<<endl<<Tatasel.neplacut<<endl<<endl<<Tatasel.am_facut_vara<<endl<<endl<<Tatasel.vreau_sa_fac;
}
