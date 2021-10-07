#include <stdio.h>

int main(){
    int x,y,z,sum;
     FILE *number;
     number = fopen("number.txt", "rw");
     for(i=0;i<11;i++){
        for(j=0;j<12;j++){
            z=x[i]*y[j];
          //  printf("%d*%d = %d\n",x[i],y[j],z);
            fprintf(number,"%d*%d = %d\n",x[i],y[j],z);
        }
        fprintf(number,"---------------------------\n");
     }

     fclose(number);
}
