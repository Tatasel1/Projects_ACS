#include<iostream>
#include<cmath>
using namespace std;

class CEO{
protected:
    string nume;
    double salariu;
public:
    CEO(string n = "Jeff Bezos", double s = 10) : nume(n), salariu(s) {}
 virtual void salary(){
     cout<<salariu<<"M per year"<<endl;
   }
    virtual void name() {
     cout<<nume<<endl;
 }
};

class Manager:public CEO{
public:
    Manager(string n = "Mark Henry", double s= 100) : CEO(n, s) {}
    void salary() override{
        cout<<"Could buy a Porsche, but drives a Prius instead "<<"(around "<<salariu<<"k a year)"<<endl;
    }

    void name() override{
        cout<<nume<<endl;
    }

};

class Developer:public Manager{
    public:
    Developer(string n = "Matt", double s = 50) : Manager(n, s) {}

    void salary() override{
        cout<<"Loans a Porsche to drive around, lying to himself he will buy it someday"<<"(around "<<salariu<<"k a year)"<<endl;
    }

    void name() override{
        cout<<nume<<endl;
    }

};


int main(){
    Developer dev;
    Manager manager;
    CEO ceo;

    CEO* p1=&ceo;
    CEO* p2=&manager;
    CEO* p3=&dev;

    p1->name();
    p1->salary();

    p2->name();
    p2->salary();

    p3->name();
    p3->salary();
    return 0;
}