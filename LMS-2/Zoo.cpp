//
// Created by Петр on 25.02.2021.
//
#include <iostream>

using namespace std;
class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
public:
    // Создаём смотрителя зоопарка
    ZooKeeper() {
        danger = 0;
    }

    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal *a){
        if(a->isDangerous()) danger++;
    }

    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount(){
        return danger;
    }

private:
    int danger;
}


int main(){

    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;


    return 0;
}