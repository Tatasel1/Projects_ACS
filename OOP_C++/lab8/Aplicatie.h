#pragma once
#include "User.h"
#include "Calatorie.h"
#include <vector>

class Aplicatie {
    private:
    std::vector<Client> clients;
    std::vector<Calatorie> calatorii;
    public:
    void login();
    void createAccount();
    void addUser(IUser* user);
    void addCalatorie(const Calatorie& calatorie);
    void printUsers();
    void printCalatorii();
    ~Aplicatie();
};