#pragma once
#include <string>
#include <sstream>

class Rezervari {
private:
    std:: string numeClient;
    int idCalatorie;
    std::string data;
public:
    void setNumeClient(const std::string &name) {
        this->numeClient = name;
    }
    void setIdCalatorie(const int id) {
        this->idCalatorie = id;
    }
    void setData(const std::string data) {
        this->data = data;
    }
    std::string getNumeClient() const {
        return this->numeClient;
    }
    int getIdCalatorie() const {
        return this->idCalatorie;
    }
    std::string getData() const {
        return this ->data;
    }

     void fromCSV(const std::string& csvLine) {
        std::stringstream ss(csvLine);
        std::string tempString;

        getline(ss, tempString, ',');
        this->idCalatorie = std::stoi(tempString);

        getline(ss, tempString, ',');
        this->numeClient = tempString;

        getline(ss, tempString, ',');
        this->data = std::stoi(tempString);
    }
};
