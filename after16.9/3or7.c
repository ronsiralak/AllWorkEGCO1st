#include <stdio.h>
int main(){
/*int n,a=3,b=7,c=21,an,bn,cn;
printf("Input: ");
scanf("%d",&n);
an=n/a;
bn=n/b;
cn=n/c;
printf("Count = %d",an+bn-cn);*/
int n,a=0,count=1;
printf("Input: ");
scanf("%d",&n);
while(count<=n){
    if(count%3==0){
        a++;
    }
    if(count%7==0){
        a++;
    }
    if(count%21==0){
        a--;
    }
count++;
}

printf("Count = %d",a);
}
