#include <stdio.h>

int main(){
    int x[13]={2,3,4,5,6,7,8,9,10,11,12};
    int y[13]={1,2,3,4,5,6,7,8,9,10,11,12};
    int z;
    int i,j;
     FILE *table;
     table = fopen("table.txt", "w");
     for(i=0;i<11;i++){
        for(j=0;j<12;j++){
            z=x[i]*y[j];
          //  printf("%d*%d = %d\n",x[i],y[j],z);
            fprintf(table,"%d*%d = %d\n",x[i],y[j],z);
        }
        fprintf(table,"---------------------------\n");
     }
     fclose(table);
}
