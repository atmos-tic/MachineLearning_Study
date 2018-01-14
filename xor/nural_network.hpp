#ifndef NURO
#define NURO
#include <eigen3/Eigen/Dense>
using namespace Eigen;
class Nuro{
    MatrixXd weight;
    VectorXd bias;
public:
    Nuro(MatrixXd, VectorXd);
};
VectorXd step_function(VectorXd x);
VectorXd sigmoid_function(VectorXd x);
VectorXd ReLU(VectorXd x);
VectorXd softmax(VectorXd x);

double mean_squared_error(VectorXd y, VectorXd t);
double cross_entropy_error(VectorXd y, VectorXd t);
#endif