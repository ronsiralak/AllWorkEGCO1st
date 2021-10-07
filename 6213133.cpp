
#include<iostream>
#include <math.h>
#include<stdio.h>
using namespace std;
double h = 0.4;
double f1(double x) {
    double value =exp(x)*sin(x);
    return value;

}
double TP(double x,double h) {
    double value =1/(2*h) * (-3*f1(x) + 4*f1(x + h) - f1(x + 2*h));
    return  value;
}
double NJ(double n1,double n2,int j) {
    double value = n2 + (n2 - n1)/(pow(4,j) -1);
    return value;
}
int main() {
    double N[4][4];
    int count =1;
    for(int i=0; i<4; i++) {
        for(int j = i; j<4; j++) {
            if(i == 0) {
                N[i][j] = TP(2.1,h/(pow(2,j)));

            } else {
                N[i][j] = NJ(N[i-1][j-1],N[i-1][j],i);
            }
        }
    }

    for(int i=0; i<4; i++) {
        for(int j = 0; j<i+1; j++) {
            cout <<  count <<  "  >>   "  <<  N[j][i] << "  ";// << endl;
            count++;
        }
        cout << endl;
    }

}
