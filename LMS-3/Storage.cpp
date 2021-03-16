//
// Created by Петр on 10.03.2021.
//
#include <iostream>

using namespace std;
class Storage
{
public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n){
        this->size = n;
        data = new int[size];
    }
    virtual ~Storage(){
        delete[] data;
    }
    // Добавьте нужный деструктор

    // Получение размерности хранилища
    unsigned getSize(){
        return this->size;
    }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int i){
        if(i <= this->size - 1){
            return this->data[i];
        }
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int i, int value){
        if(i <= this->size - 1){
            this->data[i] = value;
        }
    }
protected:
    unsigned int size;
    int* data;
};
// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
    // Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
    int* more_data;

public:
    // В конструкторе память выделяется,
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }
    // ... а в деструкторе освобождается - всё честно.
    ~TestStorage() {
        delete[] more_data;
    }
};

int main() {
    Storage *ts = new TestStorage(42);
    delete ts;
    return 0;
}
