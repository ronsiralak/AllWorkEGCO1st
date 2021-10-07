#include<stdio.h>

int main(){
int i, j, t;
int a[5]={5,9,4,8,3};
for (i=0; i<4; i++)

for (j=i+1; j<5; j++)
{

if (a[i]>a[j])
{

t = a[i];
a[i] = a[j];
a[j] =t;

}

}
for (i=0; i<5; i++){
    printf("%d,",a[i]);
}
}
