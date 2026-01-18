#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Exceptions.h"
#include "Utils.h"
#include "Aplicatie.h"
#include "Hasher_and_passwordStrength.h"

/// Destructorul elibereaza memoria alocata pentru useri
Aplicatie::~Aplicatie() {
    for (auto user : users) {
        delete user;
    }
    users.clear();
}

void Aplicatie::loadClients() {
    std::fstream file;
    try {
        file.open("users.csv", std::ios::in);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
        return;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;
        Client* client = new Client();
        client->fromCSV(line);
        users.push_back(client);
    }
    file.close();

}

void Aplicatie::loadOperators() {
    std::fstream file;
    try {
        file.open("operator.csv", std::ios::in);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
        return;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;
        Operator* operators = new Operator();
        operators->fromCSV(line);
        users.push_back(operators);
    }
    file.close();
}

void Aplicatie::loadCalatorii() {
    loadFromCSV("calatorii.csv", calatorii);
}

void Aplicatie::loadRezervari() {
    loadFromCSV("rezervari.csv", rezervari);
}

/*void Aplicatie::printClients() {
    for (auto& c : clients) {
        std::cout << c.getName() << " - " << c.getEmail() << "\n";
    }
    std::cout<<clients.size()<<"\n";

    for (auto& c : operators) {
        std::cout << c.getName() << " - " << c.getEmail() << "\n";

    }
    std::cout<<operators.size()<<"\n";

}*/

void  Aplicatie:: createAccount() {
    std::cout<<"Creeare cont\n";
    std::cout<<"==================\n";
    std::string name, email, password;
    std::cout<<"Nume: ";

    /// pentru a se citii si spatiul daca e nume si prenume
    std::cin.ignore();
    std::getline(std::cin, name);

    try {
        std::cout<<"Email: ";
        std::cin>>email;
        if (!isEmailValid(email)) {
            throw InvalidEmailException();
        }

        std::ifstream checkFile("users.csv");
        if (checkFile.is_open()) {
            std::string line;

            while (getline(checkFile, line)) {
                if (line.empty()) continue;

                std::stringstream ss(line);
                std::string dbName, dbEmail;

                getline(ss, dbName, ',');
                getline(ss, dbEmail, ',');

                if (dbEmail == email) {
                    checkFile.close();
                    throw UserAlreadyExistsException();
                }
            }
            checkFile.close();
        }

        std::cout<<"Parola: ";
        std::cin>>password;

        verifyPasswordStrength(password);

        std::cout<<"Reintroduceti parola: ";
        std::string passwordConfirm;
        std::cin>>passwordConfirm;

        if (passwordConfirm != password) {
            throw PasswordMismatchException();
        }

        std::fstream fout;

            fout.open("users.csv", std::ios::app);
            if (!fout.is_open()) {
                throw std::ios_base::failure("File not found");
            }

        std::string hashedPassword = passwordHasher::hashPassword(password);
        fout<<name<<","<<email<<","<<hashedPassword<<"\n";

        std::cout<<"Cont creat cu succes!\n";

        fout.close();
        Client* newClient = new Client();

        newClient->setName(name);
        newClient->setEmail(email);
        newClient->setPassword(hashedPassword);

        /// Adaug in vectorul de useri
        users.push_back(newClient);

    }
    catch (InvalidEmailException &e) {
        std::cout<<e.what()<<"\n";
        return ;
    }
    catch (PasswordMismatchException &e) {
        std::cout<<e.what()<<"\n";
        return ;
    }
    catch (PasswordWeakException &e) {
        std::cout<<e.what()<<"\n";
        return ;
    }
    catch (UserAlreadyExistsException& e) {
        std::cout<<e.what()<<"\n";
        return ;
    }
}

bool Aplicatie::login(std::string userType) {
    /* std::fstream file;
     std::string filename = (userType == "OPERATOR") ? "operator.csv" : "users.csv";
     try {
         file.open(filename, std::ios::in);
         if (!file.is_open()) {
             throw std::ios_base::failure("File not found");
         }
     }
     catch (const std::ios_base::failure& e) {
         std::cerr << "Error opening file: " << e.what() << std::endl;
         return false;
     }*/

    std::cout<<"Login "<<userType<<"\n";
    std::cout<<"==================\n";

    std::string email, password;

    std::cout<<"Email: ";
    std::cin>>email;
    std::cout<<"Parola: ";
    std::cin>>password;

    std::string hashedPassword = passwordHasher::hashPassword(password);


    try {
        for (auto user : users) {
            if (user->getEmail() == email && user->getPassword() == hashedPassword) {
                if (userType == "OPERATOR") {
                    /// Dynamic cast verifica tipul de obiect la runtime, daca nu e valid se arunca exceptie si se seteaza pointerul la nullptr
                    /// Static cast forteaza un tip de date sa se transforme in alt tip, aici e periculos pentru ca nu verifica tipul, ceea ce mie imi trebuie

                    Operator *op = dynamic_cast<Operator*>(user);
                    if (op != nullptr) {
                        std::cout<<"Login OPERATOR succes!\n";
                        nameLoggedIn = user->getName();
                        return true;
                    }
                }
                else if (userType == "USER") {
                    Client* cl = dynamic_cast<Client*>(user);
                    if (cl != nullptr) {
                        std::cout<<"Login CLIENT succes!\n";
                        nameLoggedIn = user->getName();
                        return true;
                    }
                }
            }

        }
        throw InvalidCredentialsException();

    }
        catch (InvalidCredentialsException& e) {
            std::cout<< e.what()<<"\n";

            return false;
        }

}

void Aplicatie::saveCalatorii() const {
    std:: fstream file;
    try {
        file.open("calatorii.csv", std::ios::out);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
    }

    file<<"id,start,stop,date,seats\n";
    for (auto& c : calatorii) {
        file<<c.getId()<<","<<c.getStartCity()<<","<<c.getStopCity()<<","<<c.getDate()<<","<<c.getSeats()<<"\n";
    }
    file.close();
}

void Aplicatie::addCalatorie() {
   std:: fstream file;

    try {
        file.open("calatorii.csv", std::ios::app);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
    }

    std::cout<<"Adaugare calatorie\n";
    std::cout<<"==================\n";
    std::string startCity, stopCity, date;
    int seats;
    int id = static_cast<int>(calatorii.size()) + 1;

    std::cout<<"Oras plecare: ";
    std::cin.ignore();
    std::getline(std::cin, startCity);

    try {
        if (!isCityValid(startCity)) {
            throw WrongDetailsException();
        }
    }
    catch (WrongDetailsException& e) {
        std::cout<< e.what()<<"\n";
        return;
    }

    std::cout<<"Oras sosire: ";
    std::getline(std::cin, stopCity);

    try {
        if (!isCityValid(stopCity)) {
            throw InvalidCredentialsException();
        }
    }
    catch (InvalidCredentialsException& e) {
        std::cout<< e.what()<<"\n";
        return;
    }

    std::cout<<"Data (ZZ/LL/AAAA-HH:MM) IN ACEST FORMAT: ";
    std::cin>>date;
    try {
        if (!isDateValid(date)) {
            throw InvalidDateException();
        }
    }
    catch (InvalidDateException& e) {
        std::cout<< e.what()<<"\n";
        return;
    }

    std::cout<<"Numar locuri: ";
    std::cin>>seats;

    Calatorie cal;
    cal.setStartCity(startCity);
    cal.setStopCity(stopCity);
    cal.setDate(date);
    cal.setSeats(seats);
    cal.setId(id);
    calatorii.push_back(cal);


    file<<id<<","<<startCity<<","<<stopCity<<","<<date<<","<<seats<<"\n";
    file.close();
}

void Aplicatie::removeCalatorie() {
    std:: fstream file;
    try {
        file.open("calatorii.csv", std::ios::app);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
    }

    if (calatorii.empty()) {
        std::cout << "Nu exista nicio cursa disponibila in sistem.\n";
        return;
    }
    std::cout<<"Stergere calatorie\n";
    std::cout<<"==================\n";

    std::cout << "\n--- LISTA CURSE DISPONIBILE ---\n";
    for (auto& c : calatorii) {
        std::cout << "ID: " << c.getId()
                  << " | Traseu: " << c.getStartCity() << " -> " << c.getStopCity()
                  << " | Data: " << c.getDate()
                  << " | Locuri: " << c.getSeats() << "\n";
    }
    std::cout << "-------------------------------\n";


    int id;
    std::cout<<"ID calatorie de sters: ";
    std::cin>>id;
    bool found = false;
    for (auto it = calatorii.begin(); it != calatorii.end(); ++it) {
        if (it->getId() == id) {
            calatorii.erase(it);
            found = true;
            break;
        }
    }

    try {
        if (found) {
            saveCalatorii();
            std::cout<<"Calatorie stearsa cu succes.\n";
        }
    }
    catch (WrongDetailsException &e) {
        std::cout<<e.what()<<"\n";
    }

}

void Aplicatie::searchCalatorii() const {

    std::cout<<"Cautare calatorii\n";
    std::cout<<"==================\n";
    std::string startCity, stopCity;
    std::string date;

    std::cout<<"Oras plecare: ";
    std::cin.ignore();
    std::getline(std::cin, startCity);

    try {
        if (!isCityValid(startCity)) {
            throw WrongDetailsException();
        }
    }
    catch (WrongDetailsException& e) {
        std::cout<< e.what()<<"\n";
        return;
    }

    std::cout<<"Oras sosire: ";
    std::getline(std::cin, stopCity);

    try {
        if (!isCityValid(stopCity)) {
            throw InvalidCredentialsException();
        }
    }
    catch (InvalidCredentialsException& e) {
        std::cout<< e.what()<<"\n";
        return;
    }

    try {
        for (auto& c : calatorii) {
            if (c.getStartCity() == startCity && c.getStopCity() == stopCity) {
                std::cout<<"ID: "<<c.getId()<<" | Plecare: "<<c.getStartCity()<<" | Sosire: "<<c.getStopCity()
                <<" | Data: "<<c.getDate()<<" | Locuri disponibile: "<<c.getSeats()<<"\n";
                return;
            }
        }
            throw Inexistent();

    }
    catch (Inexistent& e) {
        std::cout<<e.what()<<"\n";
        return;
    }

}

void Aplicatie::bookCursa() {

    if (nameLoggedIn.empty()) {
        std::cout << "EROARE: Nu sunteti logat! (nameLoggedIn este gol)\n";
        return;
    }

    std:: fstream file;
    try {
        file.open("rezervari.csv", std::ios::app);
        if (!file.is_open()) {
            throw std::ios_base::failure("File not found");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
        return;
    }

    std::cout<<"Rezervare calatorie\n";
    std::cout<<"==================\n";
    std::string startCity, stopCity;

    std::cout<<"Oras plecare: ";
    std::cin.ignore();
    std::getline(std::cin, startCity);

    try {
        if (!isCityValid(startCity)) {
            throw WrongDetailsException();
        }
    }
    catch (WrongDetailsException& e) {
        std::cout<< e.what()<<"\n";
        return;
    }

    std::cout<<"Oras sosire: ";

    std::getline(std::cin, stopCity);

    try {
        if (!isCityValid(stopCity)) {
            throw InvalidCredentialsException();
        }
    }
    catch (InvalidCredentialsException& e) {
        std::cout<< e.what()<<"\n";
        return;
    }

    time_t now = time(nullptr);
    tm *timeinfo = localtime(&now);

    char buffer[10];
    strftime(buffer, sizeof(buffer), "%H:%M", timeinfo);
    std::string timeStr(buffer);
try {
    for (auto& c : calatorii) {
        if (c.getStartCity() == startCity && c.getStopCity() == stopCity) {
            if (c.getSeats() <= 0) {
                std::cout << "Ne pare rau, nu mai sunt locuri disponibile.\n";
                file.close();
                return;
            }

            c.setSeats(c.getSeats()-1);


            Rezervari r;
            r.setIdCalatorie(c.getId());
            r.setNumeClient(nameLoggedIn);
            r.setData(timeStr);
            rezervari.push_back(r);

            file<<c.getId()<<","<<nameLoggedIn<<","<<timeStr<<"\n";
            std::cout<<"Calatorie rezervata cu succes!\n";
            file.close();
            saveCalatorii();
            return;

        }
    }
    throw Inexistent();
}
    catch (Inexistent& e)
{
        std::cout<<e.what()<<"\n";
    }

}


