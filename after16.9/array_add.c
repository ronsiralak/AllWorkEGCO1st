#include <stdio.h>

int main()
{
int i, j,ROW,COLUMN,x;
printf("Number of rows =  ");
scanf("%d",&ROW);
printf("Number of columns = ");
scanf("%d",&COLUMN);
int matrixa[ROW][COLUMN],matrixb[ROW][COLUMN];
printf("Matrix A: \n");
for (i=0; i<ROW; i++){//A
    for (j=0; j<COLUMN; j++){
        printf("a(%d,%d) = ",i,j);
        scanf("%d",&x);
        matrixa[i][j] = x;
    }
}
printf("---------------------------------\n");
printf("Matrix B: \n");
for (i=0; i<ROW; i++){//B
    for (j=0; j<COLUMN; j++){
        printf("b(%d,%d) = ",i,j);
        scanf("%d",&x);
        matrixb[i][j] = x;
    }
}
printf("---------------------------------\n");
printf("Matrix A+B: \n");
for (i=0; i<ROW; i++){//A+B
    for (j=0; j<COLUMN; j++){
        printf("a+b(%d,%d) = %d\n",i,j,matrixa[i][j]+matrixb[i][j]);
    }
}
printf("---------------------------------\n");
for (i=0; i<ROW; i++){//print
    for (j=0; j<COLUMN; j++){
        printf("%d %d   %d %d   %d %d",matrixa[i][j],j,matrixa[i][j]+matrixb[i][j]);
    }
}
}
