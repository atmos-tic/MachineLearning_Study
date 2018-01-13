#include <iostream>
#include "nural_network.hpp"
#include <eigen3/Eigen/Dense>
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

void softmax(double in[], double out[], int n){
    int sum = 0, max = 0;
    //オーバーフロー対策・最大値を求め引く
    for(int i = 0; i < n; i++){
        if(max < in[i]){
            max = in[i];
        }
    }
    for(int i = 0; i < n; i++){
        sum += exp(in[i]-max);
    }
    for(int i = 0; i < n; i++){
        out[i] = exp(in[i]-max)/sum;
    }
}