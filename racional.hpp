#ifndef RACIONAL_H
#define RACIONAL_H
#include <sstream>
class Racional
{
    int den, num;

public:
    Racional(){};
    Racional(int n, int d)
    {
        int negative = 0, multiplo = 2;
        if (n < 0)
        {
            n = n * (-1);
            negative++;
        }
        if (d < 0)
        {
            d = d * (-1);
            negative++;
        }

        while (multiplo <= n && multiplo <= d)
        {
            if (n % multiplo == 0 && d % multiplo == 0)
            {
                n = n / multiplo;
                d = d / multiplo;
            }
            else
                multiplo++;
        }
        if (negative % 2){
            n *= -1;
        }
        this->num = n;
        this->den = d;
};
~Racional(){};
int getDen() const { return den; };
int getNum() const { return num; };
friend std::ostream &operator<<(std::ostream &strm, const Racional &a)
{
    return strm << a.getNum() << "/" << a.getDen();
};
Racional operator+(Racional r)
{
    int tempDen = (num * r.getDen()) + (den * r.getNum());
    int tempNum = den * r.getDen();
    Racional C(tempNum, tempDen);
    return C;
};
Racional operator*(Racional r)
{
    int tempDen = den * r.getDen();
    int tempNum = num * r.getNum();
    Racional C(tempNum, tempDen);
    return C;
};
}
;
#endif