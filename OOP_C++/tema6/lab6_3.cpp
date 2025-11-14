#include <iostream>
#include<string>
using namespace std;

class iLogger {
public:
    virtual void logMessage(string msg) = 0;
    virtual ~iLogger() =default;
};

class hibrid {
    protected:
    string numeDispozitiv;
public:
    string getNume() {
        return numeDispozitiv;
    }

    virtual bool esteConectat() = 0;

    virtual ~hibrid() = default;
};

class Imprimanta:public iLogger, public hibrid {
    private:
    bool conectat;
    public:
    Imprimanta(const string& nume, bool c):conectat(c) {}

    bool esteConectat() override {
        return conectat;
    }

    void logMessage(string msg) override {
        cout<<"[Imprimanta "<<numeDispozitiv<<"]: "<<msg<<endl;
    }


};

int main() {
    Imprimanta imprimanta1("HP LaserJet", true);
    if(imprimanta1.esteConectat()) {
        imprimanta1.logMessage("Imprimanta este conectata si functionala.");
    } else {
        imprimanta1.logMessage("Imprimanta nu este conectata.");
    }

    imprimanta1.logMessage("Incepe imprimarea documentului...");

    return 0;
}