#include <iostream>
#include <eigen3/Eigen/Dense>

#include "svm.hpp"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp> // videoioのヘッダーをインクルード
#include <opencv2/highgui.hpp> // highguiのヘッダーをインクルード

 SVM svm(2, 8);//二次元データ　データ数8
Eigen::MatrixXd test_data(svm.Data_Num, svm.Data_Div);
Eigen::MatrixXd teach_data(svm.Data_Num, 1);

int main(void){

    /*学習・教師データ*/
    test_data << 9,5, 5,7, 7,6, 8,9, 3,4, 2,3, 4,3, 1,2;
    teach_data << 1,1,1,1,-1,-1,-1,-1;
    svm.Teaching_Data_Input(test_data, teach_data);
    svm.SVM_Trial_Param(0.0001, 0.1, 30000);  

    /*データの描画*/
    cv::Mat img= cv::Mat::zeros(512, 512, CV_8UC3);
    img += cv::Scalar(255, 255 ,255);
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    for(int i = 0; i < svm.Data_Num; i++){
        cv::circle(img, cv::Point(test_data(i,0)*32, test_data(i,1)*32), 10, cv::Scalar(128*(1+teach_data(i)), 0 ,128*(1-teach_data(i))), -1);
    }
    
    /*最急降下法*/
    svm.SVM_Gradient_Descent();

    /*直線描画*/
    cv::Point rp(-svm.bias/svm.weight(1)*32, 0);
    cv::Point lp(0,-svm.bias/svm.weight(0)*32);
    cv::line(img, rp, lp, cv::Scalar(0, 255, 0), 10);
    cv::imshow("image", img);
    
    cv::waitKey(0);
 
    return 0;
}
