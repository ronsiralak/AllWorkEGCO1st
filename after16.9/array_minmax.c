#include <stdio.h>
int main()
{
int i,j,n,x,t;
float sum =0;
printf("Number : ");
scanf("%d",&n);
printf("Data : ");
int m[n];
for (i=0; i<n; i++){
        scanf("%d",&x);
        m[i] = x;
}
for (i=0; i<n; i++){
        sum = sum +m[i];
}
printf("Average : %.2f\n",sum/n);
for (i=0; i<n-1; i++){
    for (j=i+1; j<n; j++){
        if (m[i]>m[j]){
            t = m[i];
            m[i] = m[j];
            m[j] =t;

        }
    }
}
printf("Minimum : %d\n",m[0]);
printf("Maximum : %d\n",m[n-1]);
}
