#include <iostream>
#include "logic_circuit.h"
using namespace std;

int main(){
   cout <<" AND 00|"<<AND(0,0)<<" 01|"<<AND(0,1)<<" 10|"<<AND(1,0)<<" 11|"<<AND(1,1)<< endl;
   cout <<"NAND 00|"<<NAND(0,0)<<" 01|"<<NAND(0,1)<<" 10|"<<NAND(1,0)<<" 11|"<<NAND(1,1)<< endl;
   cout <<"  OR 00|"<<OR(0,0)<<" 01|"<<OR(0,1)<<" 10|"<<OR(1,0)<<" 11|"<<OR(1,1)<< endl;
   cout <<" XOR 00|"<<XOR(0,0)<<" 01|"<<XOR(0,1)<<" 10|"<<XOR(1,0)<<" 11|"<<XOR(1,1)<< endl;
    char a[10];
    cin >> a;
    return 0;
}
