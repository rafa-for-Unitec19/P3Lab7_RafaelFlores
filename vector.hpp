#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using std::string;

template<typename T>
class Vector{
    T cordX, cordY, cordZ;
    public:
    Vector(){};
    Vector(T x, T y, T z){
        this->cordX = x;
        this->cordY = y;
        this->cordZ = z;
    };
    ~Vector(){};
    void setCordX(T x){this->cordX = x;};
    void setCordY(T y){this->cordY = y;};
    void setCordZ(T z){this->cordZ = z;};
    T getCordX() const {return cordX;};
    T getCordY() const {return cordY;};
    T getCordZ() const {return cordZ;};
    void toStrings(){
        std::cout << "[ " << cordX << " , " << cordY << " , " << cordZ << " ]\n" << std::endl;
    };
    Vector operator+(Vector v){
            T tempCordX = cordX + v.cordX;
            T tempCordY = cordX + v.cordX;
            T tempCordZ = cordX + v.cordX;
            Vector V(tempCordX, tempCordY, tempCordZ);
            return V; 
    };
    Vector operator*(Vector v){
            T tempCordX = cordX * v.cordX;
            T tempCordY = cordX * v.cordX;
            T tempCordZ = cordX * v.cordX;
            Vector V(tempCordX, tempCordY, tempCordZ);
            return V; 
    };

};
#endif