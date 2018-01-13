#include <iostream>
#include "logic_circuit.hpp"
#include "nural_network.hpp"
using namespace std;
#include <eigen3/Eigen/Dense>
using namespace Eigen;
double network (double);
int main(){
    Logic l;
    cout << l.AND(0,1) << endl;
    char a[10];
    cin >> a;
    return 0;
}
// double network (double w[], double b[]){

// }