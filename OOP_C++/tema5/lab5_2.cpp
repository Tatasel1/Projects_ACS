#include<iostream>
#include<cmath>
using namespace std;

class CEO{
public:
 void salary(){
     cout<<"10M per year"<<endl;
   }
    void name() {
     cout<<"Jeff Bezos"<<endl;
 }
};

class Manager:public CEO{
public:
    void salary() {
        cout<<"Could buy a Porsche, but drives a Prius instead (around 100k a year)"<<endl;
    }

    void name() {
        cout<<"Mark Henry"<<endl;
    }

};

class Developer:public Manager{
    public:
    void salary() {
        cout<<"Loans a Porsche to drive around, lying to himself he will buy it someday (around 60k a year)"<<endl;

    }

    void name() {
        cout<<"Matt"<<endl;
    }

};


int main(){
    CEO ceo;
    Manager m;
    Developer d;

    ceo.name();
    ceo.salary();
    cout<<"\n";
    m.name();
    m.salary();
    cout<<"\n";
    d.name();
    d.salary();
    return 0;
}