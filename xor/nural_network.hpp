#ifndef NURO
#define NURO
#include <eigen3/Eigen/Dense>
using namespace Eigen;

class Afine{
    MatrixXd weight;
    VectorXd bias;
    MatrixXd in,out;
    int DATA_NUM;
public:
    Afine(int in_num, int out_num);
    MatrixXd forward(MatrixXd x);
    MatrixXd backward(MatrixXd din);
};

class Sigmoid{
    MatrixXd in, out;
public:
    MatrixXd forward(MatrixXd x);
    MatrixXd backward(MatrixXd din);
};

class Softmax_With_Loss{
    MatrixXd in, out;
    double loss;
    MatrixXd teach;
private:
    MatrixXd softmax(MatrixXd x);
    double cross_entropy_error(MatrixXd y, VectorXd t);
public:
    Softmax_With_Loss(MatrixXd t);
    double forward(MatrixXd x);
    MatrixXd backward(MatrixXd din);
};

#endif