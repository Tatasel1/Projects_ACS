#pragma once
#include<string>

class passwordHasher {
public:
    static std::string hashPassword(const std::string& password) {
        std::string hashed;
        for (int i = 0; i < password.length(); i++) {
            /// Aici se adauga 3 la valoarea ASCII a fiecarui caracter, adica se trece la a 3-a urmatoare litera din parola
            /// Static cast l-am folosit pentru ca face conversie din string in int si evita caractere speciale cum ar fi virgula sau \n care
            /// au coduri ASCII ce pot fi interpretate gresit cand voi face conversia inapoi in string
            /// Hash-ul pentru parola transforma parola intr-un sir de numere
            /// Nu voi avea nevoie de decriptare la login, doar de verificare
            hashed += std::to_string(static_cast<int>(password[i]) + 3);
        }
        return hashed;
    }

    /// Functia de verificare a parolei

    static bool verifyPassword(const std::string& password, const std::string& hashedPassword) {
        return hashPassword(password) == hashedPassword;
    }
};

template<typename T>
inline std::string verifyPasswordStrength(const T& inputPassword) {
    std::string password = std::string(inputPassword);
    bool isUppercase = false;
    bool isLowercase = false;
    bool isDigit = false;
    bool isSpecialChar = false;

    if (password.length() < 8) {
        throw PasswordWeakException();
    }
    for (char c : password) {
        if (isupper(c)) {
            isUppercase = true;
        }
        else if (islower(c)) {
            isLowercase = true;
        }
        else if (isdigit(c)) {
            isDigit = true;
        }
        else {
            isSpecialChar = true;
        }
    }
    int score = 0;
    if (isUppercase) score++;
    if (isLowercase) score++;
    if (isDigit) score++;
    if (isSpecialChar) score++;

    if (score == 4) {
        return "Strong";
    }
    else if (score == 3 || score == 2) {
        return "Medium";
    }
    else {
        throw PasswordWeakException();
    }
}
