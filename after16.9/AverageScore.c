#include <stdio.h>
int main()
{
int n,count;
float s,sum = 0;
printf("Number of Students (n) : ");
scanf("%d",&n);
for (count=1; count<=n; count++)
{
printf("Student %d : ",count);
scanf("%f",&s);
sum=sum+s;
}
printf("Average =  %.2f\n", sum/n);
}
