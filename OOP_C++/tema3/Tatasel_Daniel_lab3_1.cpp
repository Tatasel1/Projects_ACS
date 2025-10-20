#include<iostream>
#include<stdio.h>
#include<cstring>
#include<ctime>
using namespace std;

class Exchange{
  public:

  static int nr;
  float money;
  Exchange() {
    money=rand() % 5001;
  }

  int getMoney() {
    return money;
  }

    static int getNumber() {
      return nr;
  }

  ~Exchange(){}
};

int Exchange::nr=0;


int main(){

  srand(time(NULL));

  time_t t=time(&t);
  tm current=*localtime(&t);


  for (int i=0;i<current.tm_mday;i++) {
    Exchange obiect;

    if (obiect.getMoney() >3000)
      Exchange::nr++;
  }

  cout<<Exchange::getNumber()<<endl;

  return 0;
}