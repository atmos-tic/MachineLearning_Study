#include <iostream>
#include "logic_circuit.hpp"
#include "nural_network.hpp"
using namespace std;
#include <eigen3/Eigen/Dense>
using namespace Eigen;

#define NURO_LAIYOR (1)
#define LEARNING_LATE (0.1)
VectorXd w0 = VectorXd::Random(2);
VectorXd b0 = VectorXd::Random(1);
VectorXd w, b;
Vector3d param;
Vector2d test_data[4];
Logic l;

int network (void);
int main(){
    Logic l;
    cout << l.AND(0,1) << endl;
    Vector4d x(2,3,0,-1);
    VectorXd y;
    y = step_function(x);
    cout << l.AND(0,1) << endl;
    cout << y(0) << y(3) << endl;

    test_data[0] << 0,0;
    test_data[1] << 0,1;
    test_data[2] << 1,0;
    test_data[3] << 1,1;
    cout << "a" << endl;
    //w << 0,0;
    //b << 0;
    cout << "b" << endl;
    cout <<"w size"<<w.size()<< endl;
    cout <<"b size"<<b.size()<< endl;
    // param(0) = w(0);
    // param(1) = w(1);
    // param(2) = b(0);
    param << 0,0,0;
    cout <<"param size"<<param.size()<< endl;
    cout <<"w1"<<param(0)<<"w2"<<param(1)<<"b"<<param(2)<< endl;
    while(network());
    cout <<"w1"<<param(0)<<"w2"<<param(1)<<"b"<<param(2)<< endl;
    /*止め*/
    char a[10];
    cin >> a;
    return 0;
}

/*gradient*/
VectorXd gradient(double(*func)(VectorXd, VectorXd)){
    Vector3d tmp_param[2];
    Vector3d grad;
    Vector4d y[2][4];
    Vector4d t[4];
    double h = 0.01, loss[2];
    for(int i = 0;i < param.size(); i++){
        tmp_param[0] = param;
        tmp_param[0](i) += h;
        tmp_param[1] = param;
        tmp_param[1](i) -= h;
        for(int j = 0; j < 4; j++){
            y[0][j](0) = test_data[j].dot(tmp_param[0].block(0,0,2,1)) + tmp_param[0](2);
            y[1][j](0) = test_data[j].dot(tmp_param[1].block(0,0,2,1)) + tmp_param[1](2);
            t[j](0) = (double)l.OR(test_data[j](0),test_data[j](1));
            loss[0] += func(y[0][j], t[j]);
            loss[1] += func(y[1][j], t[j]);
        }
        grad(i) = (loss[0]/4.0 - loss[1]/4.0) / (2.0*h);
        cout <<"grad"<<grad(i)<< endl;
    }
    return grad;
}

int network (void){
    Vector4d y[4], t[4];
    Vector3d grad;
    double loss;
    grad = gradient(&mean_squared_error);
    for(int i = 0; i < param.size(); i++){
        param(i) -=  grad(i)*LEARNING_LATE;
    }
    cout <<"Gw1"<<grad(0)<<"Gw2"<<grad(1)<<"Gb"<<grad(2)<< endl;
    for(int i = 0; i < 4; i++){
        y[i](0) = 1 / (1 + exp((test_data[i].dot(param.block(0,0,2,1)) + param(2))));
        t[i](0) = l.OR(test_data[i](0),test_data[i](1));
        loss += mean_squared_error(y[i], t[i]);
    }
    cout <<"w1"<<param(0)<<"w2"<<param(1)<<"b"<<param(2)<< endl;
    if(loss == 0){
        return 0;
    }else{
        return 1;
    }
}