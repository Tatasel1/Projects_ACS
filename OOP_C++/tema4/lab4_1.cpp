#include<iostream>
#include<string.h>

using namespace std;

class Beer {
    protected:
    string type;
    string origin;

public:
    Beer();
    Beer(string t,string o) {
        type=t;
        origin=o;
    }

    string getType() {
        return type;
    }
    string getOrigin() {
        return origin;
    }

};

class TypeA:private Beer {
    private:
    float length;

public:
    TypeA();

    TypeA(string t,string o,float l):Beer{t,o} {
        length=l;

    }

    string getType() {
        return this->type;


    }

    string getOrigin() {
        return this->origin;
    }

    float Area() {
        float l=length;
        return l*l;
    }



};

class TypeB:private Beer {
    private:
    float radius;

    public:
    TypeB();
    TypeB(string t,string o,float r):Beer{t,o} {


        radius=r;
    }

    string getType() {
        return this->type;
    }
    string getOrigin() {
        return this->origin;
    }
    float Area() {
        float r=radius;
        float pi=3.14159;
        return r*r*pi;
    }

};

class TypeC:private Beer {
    private:
    float base;
    float height;
    public:
    TypeC();
    TypeC(string t,string o,float b, float h):Beer{t,o} {


        base=b;
        height=h;
    }

    string getType() {
        return this->type;
    }
    string getOrigin() {
        return this->origin;
    }
    float Area() {
        float b=base;
        float h=height;
        return (b*h)/2;
    }

};

int main(){


    TypeA bereA("Blonda","Heineken",45.56);
    TypeB bereB("Neagra","Guiness",4.56);
    TypeC bereC("Nepasteurizata","Timisoreana",12.34,13.55);

    cout<<bereA.getType()<<"-> "<<bereA.getOrigin()<<endl;
    cout<<bereB.getType()<<"-> "<<bereB.getOrigin()<<endl;
    cout<<bereC.getType()<<"-> "<<bereC.getOrigin()<<endl;

    cout<<"Ariile berilor sunt: "<<endl;

    cout<<bereA.Area()<<endl<<bereB.Area()<<endl<<bereC.Area();



}