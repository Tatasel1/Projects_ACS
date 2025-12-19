#include <iostream>
#include <string>
#include <vector>

class IComponent {
public:
    virtual void update(std::string &message) = 0;
    virtual ~IComponent() {}
};

class Event  {
    std::vector<IComponent*> components;

public:
    void eventRegistered(IComponent *c) {
        components.push_back(c);
    }

    void eventOccurred(std::string message) {
        for (auto &c: components) {
            c->update(message);
        }
    }

    void Action() {
        std::cout << "Listener start" << std::endl;
        eventOccurred("Displaying event: ");
    }
};

class KeyboardListener : public IComponent {
public:
    void update(std::string &message) override {
        std::cout << message << "Pressed Keyboard" << std::endl;
    }
};

class MouseListener : public IComponent {
public:
    void update(std::string &message) override {
        std::cout << message << "Pressed Mouse" << std::endl;
    }
};

int main() {
    Event* e = new Event();

    e->eventRegistered(new KeyboardListener());
    e->eventRegistered(new MouseListener());

    e->Action();

    delete e;

    return 0;
}

/*
 * Observer este un Behavioral Pattern care defineste un mecanism de subscriptie care notifica mai multe obiecte despre orice nou event care s-a intamplat cu obiectul pe care il urmaresc.
 *
 * Avantajele acestuia includ respectarea Open/Closed Principle (permitand adaugarea de noi observatori fara a modifica obiectul subiect), dar si permiterea cuplarii intre obiecte la runtime
 *
 * Dezavanajul acestui pattern este ca subscriberii sunt notificati intr-o ordine total random
*/