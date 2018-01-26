#include <iostream>
#include "logic_circuit.hpp"
#include "nural_network.hpp"
using namespace std;
#include <eigen3/Eigen/Dense>
using namespace Eigen;

#define LEARNING_LATE (10)//学習率
MatrixXd test_data(2, 4);

/* 3層ニューラルネット
 * 各層のweight初期化（サイズ決定）
 * 学習率代入*/
Afine afine1(3,2, LEARNING_LATE);
Afine afine2(2,3, LEARNING_LATE);
Afine afine3(1,2, LEARNING_LATE);
Sigmoid sig1, sig2, sig3;

/*関数のプロトタイプ宣言*/
MatrixXd teaching_data(MatrixXd data);
int network (void);

int main(){
    /*入力データ*/
    test_data << 
        0,0,1,1,
        0,1,0,1;

    int i = 0;
    /*ニューラルネット学習*/
    while(network()){
        i++;
    }
    cout << "execute times" << i << endl;
    cout << "last result\n" << sig3.forward(afine3.forward(sig2.forward(afine2.forward(sig1.forward(afine1.forward(test_data)))))) << endl;
    cout << "teach data\n" << teaching_data(test_data) << endl;
    /*実行終了対策*/
    char a[10];
    cin >> a;
    return 0;
}

/*教師データ生成関数*/
MatrixXd teaching_data(MatrixXd data){
    MatrixXd out(1,4);
    Logic l;
    for(int i = 0; i < 4; i++){
        out(0,i) = l.XOR(data(0,i),data(1,i));
    }
    return out;

}

/*ニューラルネット実行関数*/
int network (void){
    double loss;
    /*誤差算出*/
    loss = mean_squared_error(sig3.forward(afine3.forward(sig2.forward(afine2.forward(sig1.forward(afine1.forward(test_data)))))), teaching_data(test_data));
    /*誤差逆伝播用に各入力データの誤差の行列を作る*/
    MatrixXd m_loss = sig3.forward(afine3.forward(sig2.forward(afine2.forward(sig1.forward(afine1.forward(test_data)))))) - teaching_data(test_data);
    /*誤差逆伝播で学習*/
    afine1.backward(sig1.backward(afine2.backward(sig2.backward(afine3.backward(sig3.backward(m_loss))))));
 
    if(loss < 0.00001 && loss > -0.00001){
        return 0;
    }else{
        cout << "loss" << loss <<endl;
        return 1;
    }
}