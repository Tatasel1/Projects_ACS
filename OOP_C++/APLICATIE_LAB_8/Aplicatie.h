#pragma once
#include "User.h"
#include "Calatorie.h"
#include "Rezervari.h"
#include <vector>


class Aplicatie {
    private:
    std::vector<User*> users; /// vector comun pentru toti userii, clienti si operatori

    ///std::vector<Client> clients;
    ///std::vector<Operator> operators;

    std::vector<Calatorie> calatorii;
    std::vector<Rezervari> rezervari;

    /// acest string este pentru a retine numele celui logat, la rezervare de cursa/ adaugare cursa etc, se va verifica user-ul si de acolo se va salva si numele lui,
    /// unde este cazul

    std::string nameLoggedIn;
    public:

    void loadClients();
    void loadOperators();
    void loadCalatorii();
    void loadRezervari();

    bool login(std::string userType);
    void createAccount();

    void addCalatorie();
    void removeCalatorie();

    void  saveCalatorii() const ;

    void bookCursa();
    void searchCalatorii() const ;

   /// void printClients(); ->pentru teste

    ~Aplicatie();

};
