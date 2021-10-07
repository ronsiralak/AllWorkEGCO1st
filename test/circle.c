#include<stdio.h>
int main()
{
    float pi=3.14159625;
    float area1,area2,area3,c1,c2,c3;
    int r1 = 24;
    int r2 = 125;
    int r3 = 215;
    area1 = pi*r1*r1;
    c1=2*r1*pi;

    area2 = pi*r2*r2;
    c2=2*r2*pi;

    area3 = pi*r3*r3;
    c3=2*r3*pi;


    printf("**************************************************\n");
    printf("   Radius               Area           Circular\n");
    printf("**************************************************\n");
    printf("   %d                 %.2f            %.2f\n",r1,area1,c1);
    printf("   %d               %.2f            %.2f\n",r2,area2,c2);
    printf("   %d              %.2f           %.2f\n",r3,area3,c3);
    printf("**************************************************\n");
    printf("My ID: 6213133");
    return 0;
}
