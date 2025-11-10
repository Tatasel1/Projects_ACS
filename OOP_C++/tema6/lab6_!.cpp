#include <iostream>
#include<string>

using namespace std;

class City{
protected:
  string street;
  string* attractions;
  int nrAttractions;
  int population;
  public:
  City(string s="",int n=0, int p=0):street(s),nrAttractions(n),population(p) {
    attractions=new string[nrAttractions];
  }
  virtual void getStreet() = 0;
  virtual void getAttraction() = 0;
  virtual void getNrAttractions() = 0;
  virtual void getPopulation() = 0;
  virtual ~City() {
    delete[] attractions;
  };
};

class Bucharest: public City {
public:
  Bucharest(string s="B-dul Iuliu Maniu",int n=2,int p=1716961): City(s,n,p) {
    if (nrAttractions>=2) {
      attractions[0]="Piata Constitutiei";
      attractions[1]="Car-Meet Maniu";
    }
  }

    void getStreet() override{
      cout<<"An important street: "<<street<<endl;
    }
  void getNrAttractions() override {
    if (nrAttractions>0) {
      cout<<"There are some attractions in this city\n";
    }
    else cout<<"There are no attractions in this city\n";
  }
    void getAttraction() override {
      cout<<"Displaying Attractions:\n";
      for (int i=0;i<nrAttractions;i++) {
        cout<<attractions[i]<<endl;
      }
    }
  void getPopulation() override {
    cout<<"Population: "<<population<<endl;
  }

  };

class Mumbai:public City {
  public:
  Mumbai(string s="Marine Dive",int n=0,int p=21700000):City(s,n,p){};

  void getStreet() override {
    cout<<"An important street: "<<street<<endl;
  }

  void getNrAttractions() override {
    if (nrAttractions>0) {
      cout<<"There are some attractions in this city\n";
    }
    else cout<<"There are no attractions in this city\n";
  }

  void getAttraction() override {
    if (nrAttractions>0) {
      for (int i=0;i<nrAttractions;i++) {
        cout<<attractions[i]<<endl;
      }
    }
  }

  void getPopulation() override {
    cout<<"Population: "<<population<<endl;
  }
};

class Rio:public City {
  public:
  Rio(string s="Rio Ave",int n=3, int p=6700000):City(s,n,p) {
    if (nrAttractions>=3) {
      attractions[0]="Copacabana Beach";
      attractions[1]="Jesus Christ Statue";
      attractions[2]="Carnival de Rio";
    }
  }

  void getStreet() override {
    cout<<"An important street: "<<street<<endl;
  }

  void getNrAttractions() override {
    if (nrAttractions>0) {
      cout<<"There are some attractions in this city\n";
    }
    else cout<<"There are no attractions in this city\n";
  }

  void getAttraction() override {
    if (nrAttractions>0) {
      cout<<"Displaying Attractions:\n";
      for (int i=0;i<nrAttractions;i++) {
          cout<<attractions[i]<<endl;
    }
    }

  }

  void getPopulation() override {
    cout<<"Population: "<<population<<endl;
  }
};

int main(){
  Bucharest b;
  Mumbai m;
  Rio r;
  b.getStreet();
  b.getNrAttractions();
  b.getAttraction();
  b.getPopulation();

  cout<<endl;

  m.getStreet();
  m.getNrAttractions();
  m.getAttraction();
  m.getPopulation();

  cout<<endl;

  r.getStreet();
  r.getNrAttractions();
  r.getAttraction();
  r.getPopulation();

  cout<<endl;

  City *c=&b;
  c->getStreet();
  c->getNrAttractions();
  c->getAttraction();
  c->getPopulation();

}