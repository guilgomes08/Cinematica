#include <iostream>

class Obj {
private:
    double s0;
    double v0;
    double t0;

public:
    Obj(double s0=0, double v0=0, double t0=0){
        this->s0 = s0;
        this->v0 = v0;
        this->t0 = t0;
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
};

double timesp_mru(double s01, double s02, double v1, double v2){

    double t = 0;

    if(v1 < 0){
        t = (s01 - s02)/(v1*-1 + v2);
        return t;
    }
    if(v2 < 0){
        t = (s02 - s01)/(v1 + v2*-1);
        return t;
    }
};

double spacesp_mru(double s01, double s02, double v1, double v2){

    return timesp_mru(s01, s02, v1, v2)*v1 + s01;
};

int main() {
    
    Obj object1(-50, 10);
    Obj object2(100, -10);
    std::cout << timesp_mru(object1.getS0(), object2.getS0(), object1.getV0(), object2.getV0()) << " s";
    std::cout << "\n";
    std::cout << spacesp_mru(object1.getS0(), object2.getS0(), object1.getV0(), object2.getV0()) << " m";

    return 0;
}