#ifndef LOGIC_CIRCUIT
#define LOGIC_CIRCUIT
int AND(int x1, int x2){
    double w1 = 0.5, w2 = 0.5, b = -0.7;
    double tmp = (double)x1*w1 + (double)x2*w2 + b;
    if (tmp <= 0){
        return 0;
    }else{
        return 1;
    }
}

int NAND(int x1, int x2){
    double w1 = -0.5, w2 = -0.5, b = 0.7;
    double tmp = (double)x1*w1 + (double)x2*w2 + b;
    if (tmp <= 0){
        return 0;
    }else{
        return 1;
    }
}
int OR(int x1, int x2){
    double w1 = 0.5, w2 = 0.5, b = -0.2;
    double tmp = (double)x1*w1 + (double)x2*w2 + b;
    if (tmp <= 0){
        return 0;
    }else{
        return 1;
    }
}

int XOR(int x1, int x2){
    return AND(NAND(x1,x2),OR(x1,x2));
}
#endif