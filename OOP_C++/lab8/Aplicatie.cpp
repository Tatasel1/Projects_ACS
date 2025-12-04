#include "Aplicatie.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Aplicatie::loadUsers() {

    //Deschiderea fisierului
    std::fstream file;
    try {
        file.open("users.csv", std::ios::in);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        std::string name, email, password;
        std::stringstream ss(line);

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');

        User client;
        client.setName(name);
        client.setEmail(email);
        client.setPassword(password);
        clients.push_back(client);

    }

}

void Aplicatie::printClients() {
    for (auto& c : clients) {
        std::cout << c.getName() << " - " << c.getEmail() << "\n";
    }
    std::cout<<clients.size()<<"\n";

}

void Aplicatie::createAccount() {
    std::cout<<"Creeare cont\n";
    std::cout<<"==================\n";
    std::string name, email, password;
    std::cout<<"Nume: ";
    std::cin>>name;
    std::cout<<"Email: ";
    std::cin>>email;
    std::cout<<"Parola: ";
    std::cin>>password;

    std::fstream fout;
    try {
        fout.open("users.csv", std::ios::app);
        if (!fout.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
    }

    fout<<name<<","<<email<<","<<password<<"\n";
    ///cand urc in csv sa se encripteze parola
    fout.close();
}

bool Aplicatie::login() {
    std::fstream file;

    try {
        file.open("users.csv", std::ios::in);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
    }


    std::cout<<"Login\n";
    std::cout<<"==================\n";
    std::string email, password;
    std::cout<<"Email: ";
    std::cin>>email;
    std::cout<<"Parola: ";
    std::cin>>password;

    std::string line;
    bool found = false;
    while (getline(file, line)) {
        std::string name, fileEmail, filePassword;
        std::stringstream ss(line);

        getline(ss, name, ',');
        getline(ss, fileEmail, ',');
        getline(ss, filePassword, ',');

        if (fileEmail == email && filePassword == password) {
            std::cout<<"Login successful. Welcome, "<<name<<"!\n";
            return true;
            break;
        }
    }

    return false;


///cu bool ul asta se va continua in main sa verifice daca login ul a fost cu succes
///
///sa implementez si functia pentru decriptarea parolei
}
Aplicatie::~Aplicatie() {

}


int main() {
    Aplicatie app;
    app.login();
    app.loadUsers();
    app.printClients();

    return 0;
}