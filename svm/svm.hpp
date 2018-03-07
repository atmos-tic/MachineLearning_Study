#ifndef _SVM_
#define _SVM_

#include <eigen3/Eigen/Dense>

class SVM{
    public:
        int Data_Div;//データの次元
        int Data_Num;//教師データ数
        Eigen::VectorXd weight;//重み
        double bias;//バイアス
        SVM(int d, int n);
        void Teaching_Data_Input(Eigen::MatrixXd test, Eigen::MatrixXd teach);
        void SVM_Trial_Param(double alpha, double beta, int t);
        void SVM_Gradient_Descent(void);
    private:
        Eigen::VectorXd alpha;
        Eigen::MatrixXd test_data;//テストデータ
        Eigen::MatrixXd teach_data;//教師データ
        double eta_alpha;//学習率1
        double eta_beta;//学習率2
        int trial;//試行回数
};

#endif