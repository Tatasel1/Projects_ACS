#include<stdio.h>
#include<iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class date{
public:
    date() {
        time_t t=time(&t);
        tm tmp_curr=*localtime(&t);
        cout<<"Data curenta: "<<put_time(&tmp_curr,"%Y-%m-%d, Ora:%H")<<endl;

        int ora_curr=tmp_curr.tm_hour;
        int ramas=23-ora_curr;

        int minut=tmp_curr.tm_min;
        int secunda=tmp_curr.tm_sec;
        if (minut>0 || secunda>0)
            ramas--;

        cout<<"Ore ramase: "<<ramas<<endl;
    }

    ~date() {
        cout<<"Se sterge obiectul date"<<endl;
    }

};


int main(){
    date d1;

    return 0;
}