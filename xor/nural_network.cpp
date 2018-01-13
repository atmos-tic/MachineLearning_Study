#include <iostream>
#include "nural_network.hpp"
#include <eigen3/Eigen/Dense>
using namespace Eigen;
#include "math.h"

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
    return ((y - t)*(y - t)).sum()/2;
}

double cross_entropy_error(VectorXd y, VectorXd t){
    VectorXd delta = VectorXd::Constant(y.size(),0.0000001);
    return -(t.array()*((y + delta).array().log())).sum();
}

/*gradient*/
VectorXd gradient(double(*func)(VectorXd, VectorXd), VectorXd x, VectorXd t){
    VectorXd grad(x.size());
    VectorXd tmp_x[2];
    double h = 0.0001;
    for(int i = 0;i < x.size(); i++){
        tmp_x[0] = x;
        tmp_x[0](i) += h;
        tmp_x[1] = x;
        tmp_x[1](i) -= h;
        grad(i) = (func(tmp_x[0], t) - func(tmp_x[1], t)) / (2*h);
    }
    return grad;
}