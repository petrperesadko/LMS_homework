//
// Created by Петр on 10.03.2021.
//
#include <iostream>
using namespace std;

class Animal {
public:
    // Погладить данную зверушку.
    // Последствия зависят от реализации данного метода для класса конкретной зверушки.
    virtual void pet() = 0;

    virtual ~Animal() {};
};
class NPC {
public:
    // Поговорить с NPC.
    // Что он скажет - зависит от реализации данного метода для конкретного NPC.
    virtual void talk() = 0;

    virtual ~NPC() {};
};
class SmartCat: virtual public NPC, virtual public Animal{
public:
    void talk() override{
//        NPC::talk();
        std::cout << "Meow!" << std::endl;
    }
    void pet() override{
//        Animal::pet();
        std::cout << "Meow!" << std::endl;
    }
};
//Нужно реализовать класс SmartCat, который реализует оба интерфейса.
// И на попытку заговорить, и на попытку погладить SmartCat должен выводить на экран строку "Meow!",
// завершённую символом конца строки. (Какое ТЗ - такая и реализация.)

int main(){
    // Примерно так с нашим классом будут обращаться части движка,
    // которые вообще-то отвечают за взаимодействие со зверями.
    Animal *a = new SmartCat();
    a->pet();
    delete a;

    // А так - части движка, которые работают с NPC.
    NPC *n = new SmartCat();
    n->talk();
    delete n;
    return 0;
}