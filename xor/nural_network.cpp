#include <iostream>
#include "nural_network.hpp"
#include <eigen3/Eigen/Dense>
using namespace Eigen;
#include "math.h"

Afine::Afine(int in_num, int out_num){
    weight = MatrixXd::Random(out_num, in_num);
    DATA_NUM = in_num.cols();
    bias = VectorXd::Zero(DATA_NUM);
}
MatrixXd Afine::forward(MatrixXd x){
    in = x;
    out = weight * in + bias * MatrixXd::Ones(DATA_NUM,DATA_NUM);
    return out;
}
MatrixXd Afine::backward(MatrixXd din){
    MatrixXd dout = weight.transpose() * din;
    weight += -din * in.transpose() / DATA_NUM;
    bias += -din * VectorXd::Ones(DATA_NUM);
    return dout;
}

// class Step{
//     MatrixXd in, out;
// public:
//     MatrixXd forward(MatrixXd x){
//         in = x;
//         for(int i = 0; i < x.size(); i++){
//             out(i) = x(i) > 0;
//         }
//         return out;
//     }
//     MatrixXd backward(MatrixXd din){
//         MatrixXd dout = MatrixXd::Zero(din.size(), din.size());
//         return dout;
//     }
// };

MatrixXd Sigmoid::forward(MatrixXd x){
    in = x;
    out = 1 / (1 + x.array().exp());
    return out;
}
MatrixXd Sigmoid::backward(MatrixXd din){
    MatrixXd dout = din.array() * (1.0 - out.array()) * out.array();
    return dout;
};

// class ReLU{
//     MatrixXd in, out;
// public:
//     MatrixXd forward(MatrixXd x){
//         in = x;
//         out = 1 / (1 + x.array().exp());
//         return out;
//     }
//     MatrixXd backward(MatrixXd din){
//         MatrixXd dout = din.array() * (1.0 - out.array()) * out.array();
//         return dout;
//     }
//     // VectorXd ReLU(VectorXd x){
//     //     VectorXd y(x.size());
//     //     for(int i = 0; i < x.size(); i++){
//     //         if(x(i) > 0){
//     //             y(i) = x(i);
//     //         }else{
//     //             y(i) = 0;
//     //         }
//     //     }
//     //     return y;
//     // }
// };

MatrixXd Softmax_With_Loss::softmax(MatrixXd x){
    double max = x.maxCoeff();
    MatrixXd exp_x, y;
    exp_x = (x - max*MatrixXd::Ones(x.rows(),x.cols())).array().exp();//オーバーフロー対策・最大値を求め全要素から引く
    y = exp_x/exp_x.sum();
    return y;
}
double Softmax_With_Loss::cross_entropy_error(MatrixXd y, VectorXd t){
    MatrixXd delta = MatrixXd::Constant(y.rows(), y.cols(),0.00001);
    return -(((y + delta).array().log())*(t*VectorXd::Ones(y.size()).transpose()).array()).sum();
}
Softmax_With_Loss::Softmax_With_Loss(MatrixXd t){
    teach = t;
}
double Softmax_With_Loss::forward(MatrixXd x){
    in = x;
    out = softmax(in);
    loss = cross_entropy_error(out, teach);
    return loss;
}
MatrixXd Softmax_With_Loss::backward(MatrixXd din){
    MatrixXd dout = out - teach;
    return dout;
}

/*loss function*/
double mean_squared_error(VectorXd y, VectorXd t){
    return ((y - t).array().pow(2)).sum()/2;
}