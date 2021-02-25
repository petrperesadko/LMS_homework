#include <iostream>


class Train
{
public:
    // Создать паровоз массой m,
    // стоящий в начале координат
    Train(double m){
        this->m = m;
        this->x = 0;
        this->v = 0;
    }

    // Ехать с текущей скоростью в течение времени dt
    void move(double dt){
        this->x = this->x + dt * this->v;
    }

    // Изменить полный импульс паровоза (p = mv) на dp
    // Изменение может менять знак скорости
    void accelerate(double dp){
            this->v = (this->m * this->v + dp)/this->m;
    };

    // Получить текущую координату паровоза
    double getX(){
        return this->x;
    }

private:
    double m;
    double v;
    double x;
};
//Код для базового тестирования реализации класса:



int main() {
    Train t(10);
    t.accelerate(1); // Скорость стала 0.1
    t.move(1);
    std::cout << "Current X: " << t.getX() << std::endl;
    t.move(1);
    std::cout << "Current X: " << t.getX() << std::endl;
    t.accelerate(-2); // Скорость стала -0.1
    t.move(3);
    std::cout << "Current X: " << t.getX() << std::endl;
    return 0;
}
