//
// Created by Петр on 10.03.2021.
//

class Item {
public:
    // Так можно создать предмет, указав его название, вес, уровень и магичность
    Item(string title, int weight, int level, bool magical);
    // Получить вес предмета
    int getWeight();
    // Получить уровень предмета
    int getLevel();
    // Получить, является ли предмет магичным
    int isMagical();
};
class Player {
protected:
    // Сила и уровень героя
    int strength;
    int level;
public:
    // Создать героя, все подробности будут указаны позже
    Player() { }
    // Удалить героя, ничего умного эта процедура пока что не требует
    virtual ~Player() { }

    // Базовые методы, пока что очень простые.
    // На данном этапе можно считать, что для всех героев они ведут себя одинаково,
    // так что пусть будут в базовом классе.

    // Задать силу
    void setStrength(int strength) {
        this->strength = strength;
    }
    // Задать уровень
    void setLevel(int level) {
        this->level = level;
    }

    // Получить силу
    int getStrength() {
        return this->strength;
    }
    // Получить уровень
    int getLevel() {
        return this->level;
    }

    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item) = 0;
};
class Knight: public Player{
public:
    Knight(){}
    ~Knight(){}
    bool canUse(Item* item) override{
        if(item->isMagical() == 1) return false;
        else if(this->getStrength() >= item->getWeight() && this->getLevel() >= item->getLevel()){
            return true;
        }
        else return false;
    }
};
class Wizard: public Player{
public:
    Wizard(){   }
    ~Wizard() {   }
    bool canUse(Item* item) override{
        if(item->isMagical() == 1) return true;
        else if(this->getStrength() >= item->getWeight() && this->getLevel() >= item->getLevel()){
            return true;
        }
        else return false;
    }
};
// Рыцарь может использовать только немагические предметы и только если
// (а) сила героя не меньше веса предмета,
// (б) уровень героя не меньше уровня предмета.
// Волшебник устроен в целом так же, но магические предметы использовать тоже может.

int main(){
    Item* items[3];
    items[0] = new Item("Small sword", 1, 1, false);
    items[1] = new Item("Big sword", 5, 3, false);
    items[2] = new Item("Ward", 1, 3, true);

    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Can use: " << players[i]->canUse(items[j]) << endl;
        }
    }
}



