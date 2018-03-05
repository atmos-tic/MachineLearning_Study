#include <iostream>
#include <eigen3/Eigen/Dense>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp> // videoioのヘッダーをインクルード
#include <opencv2/highgui.hpp> // highguiのヘッダーをインクルード

class SVM{
    public:
        double svm_func(Eigen::MatrixXd data);
        void tarin(void);
    private:
    
};

#define Ndata (2)
#define Data_Num (8)
#define eta_alpha (0.0001)
#define eta_beta (0.1)
#define trial (1000)
Eigen::VectorXd alpha(Data_Num);
Eigen::VectorXd weight(Ndata);
double bias;
Eigen::MatrixXd test_data(Data_Num, Ndata);
Eigen::MatrixXd teach_data(Data_Num, 1);

void SVM_Gradient_Descent(Eigen::MatrixXd test, Eigen::MatrixXd teach);

int main(void){

    test_data << 9,5, 5,7, 7,6, 8,9, 3,4, 2,3, 4,3, 1,2;
    teach_data << 1,1,1,1,-1,-1,-1,-1;

    cv::Mat img= cv::Mat::zeros(512, 512, CV_8UC3);
    img += cv::Scalar(255, 255 ,255);
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    for(int i = 0; i < Data_Num; i++){
        cv::circle(img, cv::Point(test_data(i,0)*32, test_data(i,1)*32), 10, cv::Scalar(124*(1+teach_data(i)), 0 ,124*(1-teach_data(i))), -1);
    }
    
    SVM_Gradient_Descent(test_data, teach_data);

    cv::imshow("image", img);
    
    cv::waitKey(0);
 
    return 0;
}

void SVM_Gradient_Descent(Eigen::MatrixXd test, Eigen::MatrixXd teach){
    Eigen::MatrixXd H_Matrix = (teach*Eigen::MatrixXd::Ones(1, Data_Num))*((Eigen::MatrixXd::Ones(Data_Num, 1)*teach.transpose()))*(test_data*test_data.transpose());
    Eigen::MatrixXd alpha(Data_Num,1);
    for(int i = 0; i < trial; i++){
        alpha = alpha + eta_alpha*((Eigen::MatrixXd::Ones(Data_Num,1)) - H_Matrix*alpha - eta_beta*(teach*Eigen::MatrixXd::Ones(1, Data_Num))*((Eigen::MatrixXd::Ones(Data_Num, 1)*teach.transpose()))*alpha);
    }
    std::cout<<alpha<<std::endl;
}

double SVM::svm_func(Eigen::MatrixXd data){

}

 void SVM::tarin(void){

 }
