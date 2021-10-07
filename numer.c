#include<stdio.h>
#include<math.h>

double func(double x) {
    return 1-((4*x)*cos(x))+(2*x*x)+cos(2*x);
}

double absolute(double a) {
    if(a<0)
        a=  -1*a;
    return a ;
}

double Bisection(double a,double b,double TOL) {
    double p,fa=func(a),fp,fb;
    int i = 1;
    while(i<1000) {
        fb = func(b);
        p = (a+b)/2;
        fp = func(p) ;
        printf("%d  a = %.10lf  b = %.10lf  p = %.10lf  F(p) = %.10lf\n",i,a,b,p,fp);
        if(fp == 0  ||  (b-a)/2 < TOL)
            break;
        if( fa*fp  >  fb*fp ) {
            a=p ;
            fa=fp;
        } else
            b = p;
        i++;
    }
    return p ;
}

double fix(double x) {
    return cos(x);
}

double FixedPoint(double p1,double TOL) {
    int i =1;
    double p,fp ;
    while(i<1000) {
        p =  fix(p1);
        fp  =  func(p) ;
        printf("%d:  p1 = %.10lf  p = %.10lf  F(p) = %.10lf   ",i,p1,p,fp);
        printf("fp-p ==%.10lf\n",p1-p);
        if(absolute(p1-p)<TOL)
            return p ;
        i++;
        p1=p;
    }
    return 0;
}


double dif(double x) {
    return 4*x*sin(x) - 4*cos(x) + 4*x - 2*sin(2*x);
}

double Newton(double p1, double TOL) {
    int i = 1 ;
    double p, fp;
    while(i<1000) {
        p =p1-func(p1)/dif(p1);
        fp = func(p);
        printf("%-3d:  p1 = %.10lf  p = %.10lf  F(p) = %.10lf\n",i,p1,p,fp);
        if(absolute(p-p1)<TOL)
            return p;
        i++;
        p1=p;

    }
    return 0;
}


void main() {
    double n= 0;
    printf("Bisection\n");
    n = Bisection(0,1,0.000001);
    printf("answer is %.6lf F(%.10lf) == %.10lf\n",n,func(n),func(n));
    printf("\nFixedPoin\n");
    n= FixedPoint(0.5,0.000001);
    printf("answer is %.6lf F(%.10lf) == %.10lf\n",n,func(n),func(n));
    printf("\nNewton\n");
    n = Newton(0.5,0.000001);
    printf("answer is %.6lf F(%.10lf) == %.10lf\n",n,func(n),func(n));
}

