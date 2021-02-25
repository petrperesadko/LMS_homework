//
// Created by Петр on 24.02.2021.
//
#include <iostream>

using namespace std;

class SpacePort
{
public:
    SpacePort(unsigned int size){
        this->size = size;
        empty = new bool[size];
        for(unsigned int i = 0; i < this->size; i++){
            this->empty[i] = true;
        }
    }
    ~SpacePort(){
        delete[] empty;
    }
    bool requestLanding(unsigned int dockNumber){
        if(dockNumber > this->size - 1 || dockNumber < 0) return false;
        else{
            if (this->empty[dockNumber - 1]) {
                this->empty[dockNumber - 1] = false;
                return true;
            }
            else return false;
        }
    }
    bool requestTakeoff(unsigned int dockNumber){
        if(dockNumber > this->size - 1 || dockNumber < 0) return false;
        else{
            if (this->empty[dockNumber - 1]) return false;
            else {
                this->empty[dockNumber - 1] = true;
                return true;
            }
        }
    }
private:
    bool *empty;
    unsigned int size;
};

int main(){
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(-1) << endl;
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;

    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;


    return 0;
}