#include <stdio.h>
int main()
{
int i,j,x,t,n,c=0,I;
int m[10];
printf("A : ");
for (i=0; i<10; i++){
        scanf("%d",&x);
        m[i] = x;
}
for (i=0; i<9; i++){
    for (j=i+1; j<10; j++){
        if (m[i]>m[j]){
            t = m[i];
            m[i] = m[j];
            m[j] =t;
        }
    }
}
printf("SortA : ");
for (i=0; i<10; i++){
    printf("%d ",m[i]);
}
printf("\n");
do{
    I=0;
    c=0;
    printf("K : ");
    scanf("%d",&n);
    if(n==-100){
        printf("---Bye---");
        break;
    }else{
        for(i=0; i<10; i++){
            if(n==m[i]){
                c=1;
                I=i+1;
            }
        }
        if(c==1){
            printf("Position is %d\n",I);
        }else {
            printf("Not Found!\n");
        }
        }
}while(n!=-100);
}
