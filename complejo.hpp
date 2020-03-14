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
        friend std::ostream& operator<<(std::ostream &strm, const Complejo &a) {
            if (a.getImg() < 0){
                return strm << a.getReal() << " " << a.getImg() << "i";
            }else{
                return strm << a.getReal() << " + " << a.getImg() << "i";
            }
        };
        Complejo operator+(Complejo c){
            int tempReal = real + c.getReal();
            int tempImg = img + c.getImg();
            Complejo C(tempReal, tempImg); 
            return C;
        };

        Complejo operator*(Complejo c){
            int complexTemp1 = 0, realComplex1 =0, realTemp1 = 0, realComplex2 = 0;
            
            realTemp1 = this->real * c.getReal();
            realComplex1 = this->real * c.getImg();
            realComplex2 = this->img * c.getReal();
            complexTemp1 = this->img * c.getImg();
            complexTemp1 *= -1;

            int tempReal = realTemp1 + complexTemp1;
            int tempImg = realComplex1 + realComplex2;
            Complejo C(tempReal, tempImg); 
            return C;
        };
};
#endif