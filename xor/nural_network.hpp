#ifndef NURO
#define NURO
#include <eigen3/Eigen/Dense>
using namespace Eigen;
VectorXd step_function(VectorXd x);
VectorXd sigmoid_function(VectorXd x);
VectorXd ReLU(VectorXd x);
VectorXd softmax(VectorXd x);
#endif