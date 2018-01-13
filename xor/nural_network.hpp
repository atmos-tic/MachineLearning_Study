#ifndef NURO
#define NURO
#include <eigen3/Eigen/Dense>
using namespace Eigen;
VectorXd step_function(VectorXd x);
double sigmoid_function(double x);
double ReLU(double x);
void softmax(double in[], double out[], int n);
#endif