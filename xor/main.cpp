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
MatrixXd test_data(2, 4);

Logic l;
Afine afine1(3,2);
Afine afine2(1,3);
Sigmoid sig;
MatrixXd teaching_data(MatrixXd data);
int network (void);
int main(){
    Logic l;
    cout << l.AND(0,1) << endl;

    test_data << 
        0,0,1,1,
        0,1,0,1;

    cout << "a" << endl;
//    while(network());
    for(int i = 0; i < 300; i++){
        network();
    }
    cout << "b" << endl;
    /*止め*/
    char a[10];
    cin >> a;
    return 0;
}

MatrixXd teaching_data(MatrixXd data){
    MatrixXd out(1,4);
    for(int i = 0; i < 4; i++){
        out(0,i) = data(0,i)*data(1,i);
    }
    return out;
}

int network (void){
    double loss;
    loss = mean_squared_error(afine2.forward(afine1.forward(test_data)), teaching_data(test_data));
    MatrixXd m_loss = afine2.forward(afine1.forward(test_data))  - teaching_data(test_data);
    afine1.backward(afine2.backward(m_loss));
    if(loss < 0.00000001 && loss > -0.00000001){
        return 0;
    }else{
        cout << "loss" << loss <<endl;
        return 1;
    }
}