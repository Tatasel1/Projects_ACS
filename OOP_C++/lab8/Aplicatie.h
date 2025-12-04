#pragma once
#include "User.h"
#include "Calatorie.h"
#include <vector>

class Aplicatie {
    private:
    std::vector<User> clients;
    std::vector<Calatorie> calatorii;
    public:

    void loadUsers();
    bool login();
    void createAccount();
    void addUser(User user);
    void addCalatorie(const Calatorie& calatorie);
    void removeCalatorie(int idCalatorie);

    void printCalatorii();
    void bookCursa();
    void printClients();

    ~Aplicatie();
};