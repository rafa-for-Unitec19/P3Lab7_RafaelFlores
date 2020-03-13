#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>
class Complejo{
        int real, img;
    public:
        Complejo(int r, int i): real(r), img(i){};
        int getReal() const {return real;};
        int getImg() const {return img;};
        friend std::ostream& operator<<(std::ostream &strm, const Complejo &a) {
            return strm << a.getReal() << " " << a.getImg() << "i";
        };
        Complejo operator+(Complejo c){
            int tempReal = real + c.getReal();
            int tempImg = img + c.getImg();
            Complejo C(tempReal, tempImg); 
        };
};
#endif