#include <iostream>
#include <stdio.h>
using namespace std;

class planta{
    public:
    planta(){}
};

class colorata {
    public:
    string culoare="Rosu";
    colorata() {}
};

class floare: public planta, public colorata {

};


int main() {
    floare trandafir;
    cout<<trandafir.culoare;
    return 0;
}