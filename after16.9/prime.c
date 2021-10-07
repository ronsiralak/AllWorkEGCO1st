#include <stdio.h>
int main()
{
int a,x,i;
do{
x=1;
printf("Input : ");
scanf("%d",&a);
if(a>=4){
    for(int i=2;i<a;i++){
        if(a%i==0){
            x=0;
            break;
        }
    }
}

if(x==0){
    printf("Result: %d is not a prime number.\n",a);
}else printf("Result: %d is a prime number.\n",a);

}while (a>=2);

printf("---Bye---");
}
