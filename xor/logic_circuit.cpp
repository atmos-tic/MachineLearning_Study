#include <iostream>
#include "logic_circuit.hpp"
#include <eigen3/Eigen/Dense>
using namespace Eigen;
int Logic::AND(int x1, int x2){
     Vector2d x(x1, x2), w(0.5, 0.5);
     double b = -0.7;
     double  tmp = x.dot(w) + b;
    if(tmp <= 0){
        return 0;
    }else{
        return 1;
    }
}

int Logic::NAND(int x1, int x2){
    Vector2d x(x1, x2), w(-0.5, -0.5);
     double b = 0.7;
     double  tmp = x.dot(w) + b;
    if (tmp <= 0){
        return 0;
    }else{
        return 1;
    }
}
int Logic::OR(int x1, int x2){
    Vector2d x(x1, x2), w(0.5, 0.5);
    double b = -0.2;
    double  tmp = x.dot(w) + b;
    if (tmp <= 0){
        return 0;
    }else{
        return 1;
    }
}

int Logic::XOR(int x1, int x2){
    return AND(NAND(x1,x2),OR(x1,x2));
}
