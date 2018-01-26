#ifndef NURO
#define NURO
#include <eigen3/Eigen/Dense>
using namespace Eigen;

#define DATA_NUM (4)
#define lEARN (0.1)

class Afine{
    MatrixXd weight;
    VectorXd bias;
    MatrixXd in,out;
    double rate;//学習係数
public:
    Afine(int out_num, int in_num, double r);
    MatrixXd param(void);
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
    double cross_entropy_error(MatrixXd y, MatrixXd t);
public:
    Softmax_With_Loss(MatrixXd t);
    double forward(MatrixXd x);
    MatrixXd backward(void);
};

double mean_squared_error(MatrixXd y, MatrixXd t);
double cross_entropy_error(MatrixXd y, MatrixXd t);
#endif