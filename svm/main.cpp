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

int data1[3][2] = {{9,5},{5,7},{7,6}};
int data2[3][2] = {{3,4},{1,3},{4,3}};

int main(void){

    cv::Mat img= cv::Mat::zeros(512, 512, CV_8UC3);
    img += cv::Scalar(255, 255 ,255);
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    for(int i = 0; i < 3; i++){
        cv::circle(img, cv::Point(data1[i][0]*32, data1[i][1]*32), 10, cv::Scalar(255, 0 ,0), -1);
        cv::circle(img, cv::Point(data2[i][0]*32, data2[i][1]*32), 10, cv::Scalar(0, 0 ,255), -1);
    }
    
    cv::imshow("image", img);
    
    cv::waitKey(0);
 
    return 0;
}

double SVM::svm_func(Eigen::MatrixXd data){

}

 void SVM::tarin(void){

 }
