#include <stdio.h>

int main()
{
int i, j,ROW,COLUMN,x=0,y=0,sum=0;
printf("Number of rows =  ");
scanf("%d",&ROW);
printf("Number of columns = ");
scanf("%d",&COLUMN);
int a[ROW][COLUMN],c[COLUMN],r[ROW];
for (i=0; i<ROW; i++){
    r[i]=0;
}
for (i=0; i<COLUMN; i++){
    c[i]=0;
}
for (i=0; i<ROW; i++){
    for (j=0; j<COLUMN; j++){
        printf("a(%d,%d) = ",i+1,j+1);
        scanf("%d",&x);
        a[i][j] = x;
    }
}
for (i=0; i<ROW; i++){//A
    for (j=0; j<COLUMN; j++){
        r[i]=r[i]+a[i][j];
    }
}
for (i=0; i<COLUMN; i++){//A
    for (j=0; j<ROW; j++){
        c[i]=c[i]+a[j][i];
    }
}
printf("\n");
for (i=0; i<ROW; i++){
    for (j=0; j<=COLUMN; j++){
            if(j==COLUMN){
                printf("  |  %d\n",r[i]);
            }else {
                printf("%3d",a[i][j]);
            }

    }
}
printf("  ----------------\n");
for (i=0; i<COLUMN; i++){
    printf("%3d",c[i]);
}
for (i=0; i<ROW; i++){
        sum = sum +r[i];
}
printf("  |  %d\n",sum);
}
