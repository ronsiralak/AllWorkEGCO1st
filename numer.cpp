// C++ program for implementation of Bisection Method for
// solving equations
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define TOL  0.000001
#define PI 3.14159265
// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x) {
    return 1 - 4*x*cos(x) +2*x*x+cos(2*x);
}

// Prints root of func(x) with error of EPSILON
double bisection(double a, double b) {
    int i =0;
    double p;
    while (true) {
        // Find middle point
        p= (a+b)/2;
        double        FP = func(p);
        double FA = func(a);
        // Check if middle point is root
        if (FP== TOL || (b-a)/2 < TOL)
            return p;
        i++;
        // Decide the side to repeat the steps
        if (FP*FA >func(p)*func(b)) {
            a= p;
            FA=FP;
        } else
            b=p;

        cout << " NO. "<< i << "    "<< "The value of root is : " << p<< "   Func is" << FP<<endl;;

    }

}
double fix(double p0) {
    int i =0;
    double p;
    while (true) {
        // Find middle point
        p=func(p0);
        double dif = p-p0;
        dif = abs(dif);
        // Check if middle point is root
        if (dif<=TOL)
            return p;
        p0=p;
        i++;
        cout << " NO. "<< i << "    "<< "The value of root is : " << p<<"  dif is  "<< dif<<endl;
    }
}
// Driver program to test above function
int main() {
    // Initial values assumed
    double a =0, b = 1;
    bisection(a, b);
    cout<<endl;
    fix(0.5);
    return 0;
}
