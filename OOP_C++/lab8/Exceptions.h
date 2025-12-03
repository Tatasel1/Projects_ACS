///definesc exceptiile ca clase cu functia what() noexcept override{}
#pragma once
#include <exception>
#include <string>

class UserAlreadyExistsException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "User already exists.";
    }
};

class UserNotFoundException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "User not found.";
    }
};

class InvalidCredentialsException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Invalid credentials.";
    }
};

class WrongDetailsException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Wrong details provided.";
    }
};


