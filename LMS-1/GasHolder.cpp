//
// Created by Петр on 20.02.2021.
//

#include <iostream>

using namespace std;
class GasHolder
{
public:
    int counter;
    float sum;
    GasHolder(float v){
        this->v = v;
        this->P = 0;
        this->T = 273;
        this->counter = 0;
        this->sum = 0;
    }
    ~GasHolder(){
        delete[] m;
        delete[] M;
    }
    void inject(float m, float M){
        this->m[this->counter] = m;
        this->M[this->counter] = M;
        this->counter++;
    }
    void heat(float dT){
        this->T = this->T + dT;
    }
    void cool(float dT){
        if(this->T - dT <= 0) this->T = 0;
        else this->T = this->T - dT;
    }

    float getPressure(){
        this->sum = 0;
        for(int i = 0; i < this->counter; i++){
            this->sum += this->m[i] / this->M[i];
//            std::cout << "aa" << std::endl;
//            std::cout << "m " << this->m[i] << std::endl;
//            std::cout << "M " << this->M[i] << std::endl;
        }
        this->P = this->sum * 8.31 * this->T / this->v;
        return this->P;
    }

private:
    float v;
    float T;
    float P;
    float* m = new float[10];
    float* M = new float[10];
};


int main(){
    GasHolder h(0.5);
    h.inject(16, 32);
    std::cout << "sum " << h.sum << std::endl;
    std::cout << "counter " <<  h.counter << std::endl;

    std::cout << "pressure "<< h.getPressure() << std::endl;
    std::cout << "sum " << h.sum << std::endl;
    std::cout << "counter " <<  h.counter << std::endl;


    return 0;
}
/*
 * Creating gas holder with V = 0.5 m3 and default temperature
Injecting portion of gas, mass = 16 g
Gas has molar mass 32 g/mol
Pressure after operation: 2268.63 Pa
Cooling gas holder, dT = -300 K
Pressure after operation: 0 Pa
Heating gas holder, dT = +273 K
Pressure after operation: 2268.63 Pa
Injecting portion of gas, mass = 29 g
Gas has molar mass 29 g/mol
Pressure after operation: 6805.89 Pa
Heating gas holder, dT = +30 K
Pressure after operation: 7553.79 Pa
 */
/*
 * Creating gas holder with V = 0.5 m3 and default temperature
Injecting portion of gas, mass = 16 g
Gas has molar mass 32 g/mol
Pressure after operation: 0 Pa
Cooling gas holder, dT = -300 K
Pressure after operation: 0 Pa
Heating gas holder, dT = +273 K
Pressure after operation: 0 Pa
Injecting portion of gas, mass = 29 g
Gas has molar mass 29 g/mol
Pressure after operation: 4537.26 Pa
Heating gas holder, dT = +30 K
Pressure after operation: 5035.86 Pa
 */