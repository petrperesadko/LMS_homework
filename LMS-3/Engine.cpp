#include <iostream>
using namespace std;
#include <cassert>

namespace namespaceA {
    class Engine {
    public:
        static void run() {
            cout << "EngineA run" << endl;
        }
    };
}

namespace namespaceB {
    class Engine {
    public:
        static void run() {
            cout << "EngineB run" << endl;
        }
    };
}

namespace namespaceC {
    class Engine {
    public:
        static void run() {
            cout << "EngineC run" << endl;
        }
    };
}
class MyEngine{
public:

    void run(unsigned int number){
        if(number == 1){
            namespaceA::Engine::run();
        }
        else if(number == 2){
            namespaceB::Engine::run();
        }
        else if(number == 3){
            namespaceC::Engine::run();
        }
    };
};



int main() {
    MyEngine e;
    e.run(1); // вызов run из Engine-а из библиотеки A
    e.run(2); // вызов run из Engine-а из библиотеки B
    e.run(3); // вызов run из Engine-а из библиотеки C
    e.run(10); // ничего не происходит
    return 0;
}
