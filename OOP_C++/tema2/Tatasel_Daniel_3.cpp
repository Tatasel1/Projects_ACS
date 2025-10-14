#include <stdio.h>
#include <iostream>

using namespace std;

class Motorbike {
public:
    float topSpeed;
    string name;
    string model;
    int cubicCapacity;

    Motorbike(float ts,string nm, string mdl, int cbc);
    Motorbike(string nm, string mdl, int cbc);
    Motorbike(string nm, string mdl);
    Motorbike(float ts,int cbc);
    Motorbike();
    ~Motorbike();
};

Motorbike::Motorbike() {
     topSpeed=0.2f;
     name="Motor motocicleta";
    model="Model motocicleta";
     cubicCapacity=0;
}

Motorbike::Motorbike(float ts,string nm, string mdl, int cbc) {
    topSpeed = ts;
    name = nm;
    model = mdl;
    cubicCapacity = cbc;
}

Motorbike::Motorbike(string nm, string mdl, int cbc) {
    topSpeed = 220.34;
    name = nm;
    model = mdl;
    cubicCapacity = cbc;
}

Motorbike::Motorbike(string nm, string mdl) {
    topSpeed = 350.99;
    name = nm;
    model = mdl;
    cubicCapacity = 1099;
}

Motorbike::Motorbike(float ts,int cbc) {
    name="Necunoscut, trebuie mentionat";
    model="Necunoscut, trebuie mentionat";
    cubicCapacity = cbc;
    topSpeed = ts;
}

//destructor in afara clasei
Motorbike::~Motorbike(){}


int main()
{
    Motorbike motor1(400.67,"Honda","1000RR",1000);
    Motorbike motor2("Hayabusa","1000RR",1340);
    Motorbike motor3("Kawasaki ","Ninja");
    Motorbike motor4(200.81,500);
    Motorbike motor5;

    cout<<motor1.topSpeed<<" | "<<motor1.name<<" | "<<motor1.model<<" | "<<motor1.cubicCapacity<<endl;
    cout<<motor2.topSpeed<<" | "<<motor2.name<<" | "<<motor2.model<<" | "<<motor2.cubicCapacity<<endl;
    cout<<motor3.topSpeed<<" | "<<motor3.name<<" | "<<motor3.model<<" | "<<motor3.cubicCapacity<<endl;
    cout<<motor4.topSpeed<<" | "<<motor4.name<<" | "<<motor4.model<<" | "<<motor4.cubicCapacity<<endl;
    cout<<motor5.topSpeed<<" | "<<motor5.name<<" | "<<motor5.model<<" | "<<motor5.cubicCapacity<<endl;


    return 0;
}
