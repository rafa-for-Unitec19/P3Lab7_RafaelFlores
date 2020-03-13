#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <sstream>
class Complejo{
        int real, img;
    public:
        Complejo(){};
        Complejo(int r, int i): real(r), img(i){};
        ~Complejo(){};
        int getReal() const {return real;};
        int getImg() const {return img;};
        /*std::string const toString(){
            std::stringstream stre;
            stre << real << " " << img << "i";
            return stre.str();
        }*/
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