#ifndef NURO
#define NURO

#include "math.h"
double step_function(double x){
    if(x > 0){
        return 1;
    }else{
        return 0;
    }
}
double sigmoid_function(double x){
    return 1 / (1 + exp(x));
}

double ReLU(double x){
    if(x > 0){
        return x;
    }else{
        return 0;
    }
}
#endif