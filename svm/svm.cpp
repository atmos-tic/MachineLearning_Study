#include <iostream>
#include <eigen3/Eigen/Dense>

#include "svm.hpp"

SVM::SVM(int d, int n){
    Data_Div = d;
    Data_Num = n;
    alpha = Eigen::VectorXd::Zero(n);
    weight = Eigen::VectorXd::Zero(d);
}

void SVM::Teaching_Data_Input(Eigen::MatrixXd test, Eigen::MatrixXd teach){
    test_data = test;
    teach_data = teach;
}

void SVM::SVM_Trial_Param(double alpha, double beta, int t){
    eta_alpha = alpha;
    eta_beta = beta;
    trial = t;
}

void SVM::SVM_Gradient_Descent(void){
    Eigen::MatrixXd H_Matrix = (teach_data*Eigen::MatrixXd::Ones(1, Data_Num)).array()*((Eigen::MatrixXd::Ones(Data_Num, 1)*teach_data.transpose())).array()*(test_data*test_data.transpose()).array();
    Eigen::MatrixXd alpha(Data_Num,1);
    for(int i = 0; i < trial; i++){
        alpha = alpha + eta_alpha*((Eigen::MatrixXd::Ones(Data_Num,1)) - H_Matrix*alpha - eta_beta*(teach_data*Eigen::MatrixXd::Ones(1, Data_Num))*((Eigen::MatrixXd::Ones(Data_Num, 1)*teach_data.transpose()))*alpha);
    }
    /*重さの計算*/
    Eigen::MatrixXd k = alpha.array()*teach_data.array();
    weight =  test_data.transpose() * k;
    bias = (teach_data - test_data*weight).mean();
}