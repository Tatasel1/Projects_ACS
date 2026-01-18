#include <iostream>
#include "Aplicatie.h"
#include "Exceptions.h"

///PAROLA ADMIN: /*@dMin1234*/ fara /* */

int main() {
    Aplicatie app;

    try {
        app.loadOperators();
        app.loadClients();
        app.loadCalatorii();
        app.loadRezervari();
        std::cout<<"Date incarcate cu succes.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Eroare critica la incarcarea datelor: " << e.what() << "\n";
        return 1;
    }

    int optiune = -1;

    while (optiune != 0) {
        std::cout << "\n====================================\n";
        std::cout << "   SISTEM REZERVARI AUTOBUZ - START\n";
        std::cout << "====================================\n";
        std::cout << "1. Login OPERATOR\n";
        std::cout << "2. Login CLIENT\n";
        std::cout << "3. Creeaza Cont CLIENT\n";
        std::cout << "0. Iesire\n";
        std::cout << "Alegeti optiunea: ";

        std::cin >> optiune;

        switch (optiune) {
            case 1: {
                if (app.login("OPERATOR")) {
                    int optiuneOperator = -1;
                    while (optiuneOperator != 0) {
                        std::cout << "\n--- Meniu OPERATOR ---\n";
                        std::cout << "1. Adauga Calatorie\n";
                        std::cout << "2. Sterge Calatorie\n";
                        std::cout << "0. Logout\n";
                        std::cout << "Alegeti optiunea: ";
                        std::cin >> optiuneOperator;

                        switch (optiuneOperator) {
                            case 1:
                                app.addCalatorie();
                                break;
                            case 2:
                                app.removeCalatorie();
                                break;
                            case 0:
                                std::cout << "Logout OPERATOR.\n";
                                break;
                            default:
                                std::cout << "Optiune invalida. Incercati din nou.\n";
                        }
                    }
                }
                break;
            }

            case 2: {
                if (app.login("USER")) {
                    int optiuneClient = -1;
                    while (optiuneClient != 0) {
                        std::cout << "\n--- Meniu CLIENT ---\n";
                        std::cout << "1. Cauta Calatorii\n";
                        std::cout << "2. Rezerva Calatorie\n";
                        std::cout << "0. Logout\n";
                        std::cout << "Alegeti optiunea: ";
                        std::cin >> optiuneClient;

                        switch (optiuneClient) {
                            case 1:
                                app.searchCalatorii();
                                break;
                            case 2:
                                app.bookCursa();
                                break;
                            case 0:
                                std::cout << "Logout CLIENT.\n";
                                break;
                            default:
                                std::cout << "Optiune invalida. Incercati din nou.\n";
                        }
                    }
                }
                break;
            }

            case 3 : {
                app.createAccount();
                app.loadClients();
                break;
            }

            case 0:
                std::cout << "Iesire din aplicatie. La revedere!\n";
                break;
            default:
                std::cout << "Optiune invalida.\n";
            ///se curata bufferul
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;


        }
    }
    return 0;
}

