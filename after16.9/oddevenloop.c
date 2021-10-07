#include <stdio.h>
int main()
{
int n,a;
do{
printf("Input : ");
scanf("%d",&a);
n=a%2;
if(n==0){
    printf("Output : Even");
}else printf("Output : Odd");
printf("\n--------------------\n");

}while (a>=0);

printf("Bye...");
}
