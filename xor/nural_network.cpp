#include <iostream>
#include "nural_network.hpp"
#include <eigen3/Eigen/Dense>
using namespace Eigen;
#include "math.h"

Nuro::Nuro(MatrixXd w, VectorXd b){
    weight = w;
    bias = b;
}
VectorXd step_function(VectorXd x){
    VectorXd y(x.size());
    for(int i = 0; i < x.size(); i++){
        y(i) = x(i) > 0;
    }
    return y;
}

VectorXd sigmoid_function(VectorXd x){
    VectorXd y(x.size());
    for(int i = 0; i < x.size(); i++){
        y(i) = 1 / (1 + exp(x(i)));
    }
    return y;
}

VectorXd ReLU(VectorXd x){
    VectorXd y(x.size());
    for(int i = 0; i < x.size(); i++){
        if(x(i) > 0){
             y(i) = x(i);
        }else{
            y(i) = 0;
        }
    }
    return y;
}

VectorXd softmax(VectorXd x){
    double max = x.maxCoeff(), sum;
    VectorXd y, exp_x;
    exp_x = (x - max*VectorXd::Ones(x.size())).array().exp();//オーバーフロー対策・最大値を求め全要素から引く
    sum = exp_x.sum();
    y = exp_x/sum;
}

/*loss function*/
double mean_squared_error(VectorXd y, VectorXd t){
    return ((y - t).array().pow(2)).sum()/2;
}

double cross_entropy_error(VectorXd y, VectorXd t){
    VectorXd delta = VectorXd::Constant(y.size(),0.00001);
    return -(t.array()*((y + delta).array().log())).sum();
}