#pragma once
#include <string>

class IUser {
    public:
    virtual void print() = 0;
    virtual ~IUser() = default;
};

class User: public IUser {
    protected:
    std::string name;
    std::string email;
    std::string password;

    public:
    void print() override;
};

class Operator: public User {
    public:
    void addCursa();
    void removeCursa();
    void print() override;
    ~Operator() override = default;
};

class Client: public User {
    public:
    void createAccount();
    void bookCursa();
    void cancelCursa();
    void print() override;
    ~Client() override = default;
};
