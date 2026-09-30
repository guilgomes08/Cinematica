#include <iostream>
#include <cmath>

class Obj {
private:
    double s0;
    double s;
    double v0;
    double v;
    double t0;
    double a;

public:
    Obj(double s0=0, double v0=0, double t0=0, double a=0, double v=0, double s=0){
        this->s0 = s0;
        this->s = s;
        this->v0 = v0;
        this->v = v;
        this->t0 = t0;
        this->a = a;
    }
    double getS0(){
        return s0;
    }
    void setS0(double s0){
        this->s0 = s0;
    }
    double getV0(){
        return v0;
    }
    void setV0(double v0){
        this->v0 = v0;
    }
    double getT0(){
        return t0;
    }
    void setT0(double t0){
        this->t0 = t0;
    }
    double getA(){
        return a;
    }
    void setA(double a){
        this->a = a;
    }
    double getS(){
        return s;
    }
    void setS(double s){
        this->s = s;
    }
    double getV(){
        return v;
    }
    void setV(double v){
        this->v = v;
    }
};

double tempomp_mru(double s01, double s02, double v1, double v2){
    if(v1 == v2){
        std::cout << "Posição entre os objetos nunca muda.";
        return 0;
    }
    return (s01 - s02)/(v2 - v1);
};

double espacomp_mru(double s01, double s02, double v1, double v2){
    return tempomp_mru(s01, s02, v1, v2)*v1 + s01;
};

double desloc_semt_mruv(double v, double v0, double a){
    if(a == 0){
        std::cout << "O movimento não é acelerado.";
        return 0;
    }
    return (std::pow(v, 2) - std::pow(v0, 2))/(2 * a);
}

int main() {
    
    //Obj(double s0, double v0, double t0, double a, double v, double s)
    Obj object1(1, 10, 0, 5, 20);
    Obj object2(10, 20);
    std::cout << tempomp_mru(object1.getS0(), object2.getS0(), object1.getV0(), object2.getV0()) << " s";
    std::cout << "\n";
    std::cout << espacomp_mru(object1.getS0(), object2.getS0(), object1.getV0(), object2.getV0()) << " m";

    std::cout << "\n";
    std::cout << "Agora tratando de MRUV\n";
    std::cout << desloc_semt_mruv(object1.getV(), object1.getV0(), object1.getA());

    return 0;
}