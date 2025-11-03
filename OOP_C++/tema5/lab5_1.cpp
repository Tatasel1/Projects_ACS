#include<iostream>
#include<cmath>
using namespace std;

class Volume{
public:
  void volume(float l){
      cout<<"Volumul cubului este: "<<l*l*l<<endl;
    }

    void volume(float r,string esteSfera) {
      if (esteSfera=="DA")
        cout<<"Volumul sferei este: "<<(M_PI*r*r*r)*4/3<<endl;
      else cout<<"Nu este sfera"<<endl;

  }

    void volume(float Ariab,float h) {
      cout<<"Volumul piramidei este: "<<(Ariab*h)/3<<endl;
  }

  void volume() {
    cout<<"Introduceti parametrii"<<endl;
  }

};

int main(){
Volume v1;
  v1.volume();
  v1.volume(12.44);
  v1.volume(10.22,"DA");
  v1.volume(10.22,20.22);
  return 0;
}