#include<iostream>
#include <string>
#include <vector>

class Pizza {
private:
    std:: string blat;
    std:: string sos;
    std:: vector<std:: string> toppinguri;
public:
    void setBlat(std:: string _blat) {
        this->blat = _blat;
    }
    void setSos(std:: string _sos) {
        this->sos = _sos;
    }
    void setTopping(std:: string topping) {
        this->toppinguri.push_back(topping);
    }
    void descriere() {
        std:: cout << "Blat: " << blat << std:: endl;
        std:: cout << "Sos: " << sos << std:: endl;
        std:: cout << "Toppinguri: ";
        for (const auto& topping : toppinguri) {
            std:: cout << topping << " ";
        }
        std:: cout << std:: endl;
    }
};

class IPizzaBuilder {
public:
    virtual void buildBlat(const std:: string& blat) = 0;
    virtual void buildSos(const std:: string& sos) = 0;
    virtual void buildTopping(const std:: string& topping) = 0;
    virtual Pizza getPizza() = 0;
    virtual void reset() = 0;
    virtual ~IPizzaBuilder() = default;
};

class PizzaBuilder: public IPizzaBuilder {
private:
    Pizza pizza;
public:
    PizzaBuilder() {
        pizza = Pizza();
    }
    void buildBlat(const std:: string& blat) override {
        pizza.setBlat(blat);
    }
    void buildSos(const std:: string& sos) override {
        pizza.setSos(sos);
    }
    void buildTopping(const std:: string& topping) override {
        pizza.setTopping(topping);
    }

    Pizza getPizza() override {
        return pizza;
    }

    void reset() override {
        this->pizza = Pizza();
    }
};

class PizzaBuilderFactory {
private:
    PizzaBuilder builder;
public:
    Pizza makeMargherita(IPizzaBuilder& builder) {
        builder.buildBlat("clasic");
        builder.buildSos("rosii");
        builder.buildTopping("mozzarella");
        builder.buildTopping("busuioc");
        return builder.getPizza();

    }
    Pizza makePepperoni(IPizzaBuilder& builder) {
        builder.buildBlat("subtire");
        builder.buildSos("rosii picante");
        builder.buildTopping("mozzarella");
        builder.buildTopping("pepperoni");
        return builder.getPizza();
    }
    Pizza makeQuatroStagioni(IPizzaBuilder& builder) {
        builder.buildBlat("gros");
        builder.buildSos("cremă de brânză");
        builder.buildTopping("mozzarella");
        builder.buildTopping("ciuperci");
        builder.buildTopping("sunca");
        builder.buildTopping("masline");
        return builder.getPizza();
    }

    Pizza makePizzaCustom(IPizzaBuilder& builder, const std:: string& blat, const std:: string& sos, const std:: vector<std:: string>& toppinguri) {
        builder.buildBlat(blat);
        builder.buildSos(sos);
        for (const auto& topping : toppinguri) {
            builder.buildTopping(topping);
        }
        return builder.getPizza();
    }


};

int main() {

    PizzaBuilder builder;
    PizzaBuilderFactory factory;
    Pizza margherita;
    margherita = factory.makeMargherita(builder);
    std:: cout << "Pizza Margherita:" << std:: endl;
    margherita.descriere();

    builder.reset();

    std::cout<<"============INTRODUCETI O PIZZA CUSTOMIZATA:===========\n";
    std:: string blat, sos;
    int nrToppinguri;
    std:: vector<std:: string> toppinguri;
    std:: cout << "Tip blat (DOAR SUBTIRE SAU PUFOS):";
    std:: getline(std:: cin, blat);

    try {
        if (blat != "subtire" && blat != "pufos") {
            throw std:: invalid_argument("Tip de blat invalid. Trebuie sa fie 'subtire' sau 'pufos'.");
        }
    }
    catch (const std:: invalid_argument& e) {
        std:: cout << e.what() << std:: endl;
        return 1;
    }

    std:: cout << "Tip sos: (DOAR ALB SAU ROSU):";
    std:: getline(std:: cin, sos);

    try {
        if (sos != "alb" && sos != "rosu") {
            throw std:: invalid_argument("Tip de sos invalid. Trebuie sa fie 'subtire' sau 'pufos'.");
        }
    }
    catch (const std:: invalid_argument& e) {
        std:: cout << e.what() << std::endl;
        return 1;
    }

    std:: cout << "Numar toppinguri: ";
    std:: cin >> nrToppinguri;
    std:: cin.ignore();
    for (int i = 0; i < nrToppinguri; i++) {
        std:: string topping;
        std:: cout << "Topping " << (i + 1) << ": ";
        std:: getline(std:: cin, topping);
        toppinguri.push_back(topping);
    }
    std::cout<<"=============Pizza Customizata:============\n";
    Pizza pizzaCustom = factory.makePizzaCustom(builder, blat, sos, toppinguri);
    pizzaCustom.descriere();

}