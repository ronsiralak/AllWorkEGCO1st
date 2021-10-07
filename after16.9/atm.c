#include <stdio.h>
int main()
{
int h,f,t,h1,f1,t1,start,withdraw,i=1,a,b,c;
printf("Start\n");
printf("#100 : ");
scanf("%d",&h);
printf("#500 : ");
scanf("%d",&f);
printf("#1000 : ");
scanf("%d",&t);
do{
    printf("Person%d-Withdraw: ",i);
    scanf("%d",&withdraw);
    start = withdraw;
        if(withdraw==0){
            printf("End\n");
            break;
        }
        if(withdraw%100==0){
            h1=h;
            f1=f;
            t1=t;
            a=0;
            b=0;
            c=0;
            while((withdraw/1000>0)&&(t>0)){
                t--;
                withdraw = withdraw-1000;
                a++;
            }
            while((withdraw/500>0)&&(f>0)){
                f--;
                withdraw = withdraw-500;
                b++;
            }
            while((withdraw/100>0)&&(h>0)){
                h--;
                withdraw = withdraw-100;
                c++;
            }
            int total = (1000*a)+(500*b)+(100*c);
            if(total == start){
                printf("#100 : %d\n",c);
                printf("#500 : %d\n",b);
                printf("#1000 : %d\n",a);
            }else {
                h=h1;
                f=f1;
                t=t1;
                printf("Cannot Pay!\n");
            }

        }else printf("Cannot Pay!\n");
    i++;
}while(start>0);
}

