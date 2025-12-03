#pragma once
#include <string>

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

    void printCalatorie();

};


///data curenta o fac in clasa de aplicatie, unde se si verifica daca este data curenta