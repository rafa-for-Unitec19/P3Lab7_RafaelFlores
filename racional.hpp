#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>
class Racional{
    int den, num;
    public:
    Racional(int, int){};
    int getDen() const {return den;};
    int getNum() const {return num;};
    friend std::ostream& operator<<(std::ostream &strm, const Racional &a) {
        return strm << a.getDen() << "/" << a.getNum();
    };
    Racional operator+(Racional r){
            int tempDen = (num * r.getDen()) + (den * r.getNum());
            int tempNum = den + r.getDen();
            Racional C(tempNum, tempDen);
            return C; 
    };
    Racional operator*(Racional r){
            int tempDen = den + r.getDen();
            int tempNum = num + r.getNum();
            Racional C(tempNum, tempDen);
            return C; 
    };
};
#endif