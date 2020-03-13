#ifndef RACIONAL_H
#define RACIONAL_H
#include <sstream>
class Racional{
    int den, num;
    public:
    Racional(){};
    Racional(int d, int n): den(d), num(n){};
    ~Racional(){};
    int getDen() const {return den;};
    int getNum() const {return num;};
    /*std::string const toString(){
            std::stringstream stre;
            stre << num << " / " << den;
            return stre.str();
    }*/
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