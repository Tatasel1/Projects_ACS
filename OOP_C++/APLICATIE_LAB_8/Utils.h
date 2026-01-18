///aici definesc clase pentru securitatea parolei de exemplu, in mare, utilitati:)))
#pragma once

#include <string>
/// acest header este pentru a verifica daca un caracter contine cifre sau caractere speciale de ex @
#include <cctype>
#include <vector>
#include <sstream>

inline bool isDateValid(const std::string& date) {
    /// Aici ar trebui sa adaug logica pentru a verifica daca data este valida
    /// verificarea formatului, daca ziua/luna/anul sunt corecte, etc.
    /// dar si daca data este  in trecut, fals
    /// Formatul acceptat este ZZ/LL/AAAA-HH:MM

    if (date.length() != 16) {
        return false;
    }
    if (date[2] != '/' || date[5] != '/' || date[10] != '-' || date[13] != ':') {
        return false;
    }

    int day, month, year,hour,minutes;
    char slash;
    char line;
    char points;
    std::stringstream ss(date);
    ss >> day >> slash >> month >> slash >> year>>line>>hour>>points>>minutes;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;


    if (hour < 0 || hour > 23)
        return false;
    if (minutes < 0 || minutes > 59)
        return false;

    time_t now = time(nullptr);
    tm *timeinfo = localtime(&now);

    int currYear = timeinfo->tm_year + 1900;
    int currMonth = timeinfo->tm_mon + 1;
    int currDay = timeinfo->tm_mday;
    int currHour = timeinfo->tm_hour;
    int currMin = timeinfo->tm_min;

    if (year < currYear) return false;
    if (year > currYear) return true;

    if (month < currMonth) return false;
    if (month > currMonth) return true;

    if (day < currDay) return false;
    if (day > currDay) return true;

    if (hour < currHour) return false;
    if (hour > currHour) return true;

    if (minutes <= currMin) return false;

    return true;

}

inline bool isCityValid(const std::string& city) {
    if (city.length() < 3) {
        return false;
    }
    for (char c : city) {
        if (!isalpha(c) && !isspace(c) && c != '-') {
            return false;
        }
    }

    return true;
}

/// Functie care verifica daca un email este valid, prin cautarea de @ si .
inline bool isEmailValid(const std::string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    if (atPos == std::string::npos || dotPos == std::string::npos) {
        return false;
    }

    if (atPos == 0 || dotPos == email.length() - 1) return false;/// Daca @ este primul caracter sau . este ultimul caracter

    return true;
}

/// Functie care incarca din csv in vector
template<typename T>
void loadFromCSV(const std::string& filename, std::vector<T>& vec) {
    vec.clear();
    std::fstream file;
    try {
        file.open(filename, std::ios::in);
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

        T object;
        object.fromCSV(line);
        vec.push_back(object);
    }
    file.close();
}
