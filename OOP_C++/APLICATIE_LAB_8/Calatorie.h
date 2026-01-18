#pragma once
#include <string>
#include <sstream>

class Calatorie {
    private:
    int idCalatorie;
    std:: string startCity;
    std:: string stopCity;
    std:: string data;
    int seats;
    public:
   /// Calatorie(const int id, const std::string start, const std::string stop, const std::string date, const int seats):
       /// idCalatorie(id), startCity(start), stopCity(stop), data(date), seats(seats) {}

    void setId(const int id) {
        this->idCalatorie = id;
    }

    void setStartCity(const std::string start) {
        this->startCity = start;
    }

    void setStopCity(const std::string stop) {
        this->stopCity = stop;
    }

    void setDate(const std::string date) {
        this->data = date;

    }
    void setSeats(const int seats) {
        this->seats = seats;
    }

    int getId() const {
        return this->idCalatorie;
    }

    std::string getStartCity() const {
        return this->startCity;
    }

    std::string getStopCity() const {
        return this->stopCity;
    }

    std::string getDate() const {
        return this->data;
    }

    int getSeats() const {
        return this->seats;
    }

    void fromCSV(const std::string& csvLine) {
        std::stringstream ss(csvLine);
        std::string tempString;

        getline(ss, tempString, ',');
        this->idCalatorie = std::stoi(tempString);

        getline(ss, tempString, ',');
        this->startCity = tempString;

        getline(ss, tempString, ',');
        this->stopCity = tempString;

        getline(ss, tempString, ',');
        this->data = tempString;

        getline(ss, tempString, ',');
        this->seats = std::stoi(tempString);
    }
};


///data curenta o fac in clasa de aplicatie, unde se si verifica daca este data curenta