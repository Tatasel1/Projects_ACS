#pragma once
#include <string>
#include <sstream>

/*class IUser {
    public:
    virtual void print() = 0;
    virtual ~IUser() = default;
};
*/

class User {
    protected:
    std::string name;
    std::string email;
    std::string password;

    public:
    std::string getName() {
        return name;
    }
    std::string getEmail() {
        return email;
    }
    std::string getPassword() {
        return password;
    }

    void setName(const std::string &name) {
        this->name = name;
    }
    void setEmail(const std::string &email) {
        this->email = email;
    }
    void setPassword(const std::string& password) {
        this->password = password;
    }
    virtual void fromCSV(const std::string& csvLine) = 0;
    virtual ~User() = default;
};

class Operator : public User {
public:
    Operator() = default;
    Operator(std::string n, std::string e, std::string p) {
        this->name = n;
        this->email = e;
        this->password = p;
    }
    void fromCSV(const std::string& csvLine) override;
};

class Client: public User {
    public:
    Client() = default;
    Client(std::string n, std::string e, std::string p) {
        this->name = n;
        this->email = e;
        this->password = p;
    }
    void fromCSV(const std::string& csvLine) override;
};

inline void Operator::fromCSV(const std::string& csvLine)  {
    std::string name, email, password;
    std::stringstream ss(csvLine);

    getline(ss, name, ',');
    getline(ss, email, ',');
    getline(ss, password, ',');

    /// Verificare si eliminare caracter invizibil la sfarsit pnetru ca e posibil sa fie /r la finalul liniei
    if (!password.empty() && password.back() == '\r') {
        password.pop_back(); // Sterge caracterul invizibil
    }
    this->setName(name);
    this->setEmail(email);
    this->setPassword(password);
}

inline void Client::fromCSV(const std::string& csvLine) {
    std::string name, email, password;
    std::stringstream ss(csvLine);

    getline(ss, name, ',');
    getline(ss, email, ',');
    getline(ss, password, ',');

    /// Verificare si eliminare caracter invizibil la sfarsit pnetru ca e posibil sa fie /r la finalul liniei
    if (!password.empty() && password.back() == '\r') {
        password.pop_back(); // Sterge caracterul invizibil
    }
    this->setName(name);
    this->setEmail(email);
    this->setPassword(password);
}

