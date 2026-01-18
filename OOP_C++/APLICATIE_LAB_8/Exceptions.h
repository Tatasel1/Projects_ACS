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

class PasswordMismatchException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Eroare: Parolele nu coincid!";
    }
};

class InvalidEmailException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Eroare: Formatul email-ului este invalid (trebuie sa contina '@' si '.').";
    }
};

class PasswordWeakException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Password is too weak.";
    }
};

class Inexistent : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Inexistent entity.";
    }
};

class InvalidDateException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Invalid date format.";
    }
};

