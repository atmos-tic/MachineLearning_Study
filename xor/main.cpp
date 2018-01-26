#include <iostream>
#include "logic_circuit.hpp"
#include "nural_network.hpp"
using namespace std;
#include <eigen3/Eigen/Dense>
using namespace Eigen;

#define NURO_LAIYOR (1)
#define LEARNING_LATE (10)
MatrixXd test_data(2, 4);

Afine afine1(3,2, LEARNING_LATE);
Afine afine2(2,3, LEARNING_LATE);
Afine afine3(1,2, LEARNING_LATE);
Sigmoid sig1, sig2, sig3;

MatrixXd teaching_data(MatrixXd data);
int network (void);

int main(){
    test_data << 
        0,0,1,1,
        0,1,0,1;

    int i = 0;
    while(network()){
        i++;
    }
    cout << "execute times" << i << endl;
    cout << "last result" << sig3.forward(afine3.forward(sig2.forward(afine2.forward(sig1.forward(afine1.forward(test_data)))))) << endl;
    /*実行終了対策*/
    char a[10];
    cin >> a;
    return 0;
}

MatrixXd teaching_data(MatrixXd data){
    MatrixXd out(1,4);
    Logic l;
    for(int i = 0; i < 4; i++){
        out(0,i) = l.XOR(data(0,i),data(1,i));
    }
    return out;

}

int network (void){
    double loss;

    /*シグモイド　二乗和誤差*/
    loss = mean_squared_error(sig3.forward(afine3.forward(sig2.forward(afine2.forward(sig1.forward(afine1.forward(test_data)))))), teaching_data(test_data));
    MatrixXd m_loss = sig3.forward(afine3.forward(sig2.forward(afine2.forward(sig1.forward(afine1.forward(test_data)))))) - teaching_data(test_data);
    afine1.backward(sig1.backward(afine2.backward(sig2.backward(afine3.backward(sig3.backward(m_loss))))));
 
    if(loss < 0.00001 && loss > -0.00001){
        return 0;
    }else{
        cout << "loss" << loss <<endl;
        return 1;
    }
}