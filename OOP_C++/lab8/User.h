#pragma once
#include <string>

/*(class IUser {
    public:
    virtual void print() = 0;
    virtual ~IUser() = default;
};*/

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

    void setName(const std::string name) {
        this->name = name;
    }
    void setEmail(const std::string email) {
        this->email = email;
    }
    void setPassword(const std::string password) {
        this->password = password;
    }
};

/*class Operator: public User {
    public:

};*/

/*class Client: public User {
    public:

};
*/