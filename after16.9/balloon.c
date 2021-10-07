#include<stdio.h>
int main()
{
int i,j,k,row,v,h,w,n;
printf("Input : ");
scanf("%d",&row);
if((row%2==1)&&(row<20)){
    w=(2*row)+5;
    h=(row+3)/2;
    n=(row+1)/2;
        for(i=1;i<=h;i++){
            for(v=0;v<h;v++){
                printf(" ");
            }
            for(j=i;j<h;j++){
                printf(" ");
            }
            for(k=1;k<(i*2);k++){
                printf("*");
            }
            printf("\n");
        }  //top
        for(i=1;i<=w;i++){
            if(i==h){
                printf("*");
            } else if(i==w-h+1){
                printf("*");
            }else printf(" ");
        }//1bantan
        printf("\n");
        for(i=1;i<=n;i++){
            for(j=0;j<=n;j++){
                if(j<n-i){
                    printf(" ");
                }else printf("*");
            }
            printf(" ");
            for(j=1;j<=row;j++){
                printf("*");
            }
            printf(" ");
            for(j=0;j<=n;j++){
                if(j>=n-i){
                    printf("*");
                }
            }
            printf("\n");//สามเหลี่ยมแรก
        }

        for(i=1;i<=n-1;i++){
            for(j=0;j<=n;j++){
                if(i>j){
                    printf(" ");
                }else printf("*");
            }
            printf(" ");
            for(j=1;j<=row;j++){
                printf("*");
            }
            printf(" ");
            for(j=0;j<=n;j++){
                if(j<=n-i){
                    printf("*");
                }else printf(" ");
            }
            printf("\n");//สามเหลี่ยม2
        }
        for(i=1;i<=w;i++){
            if(i==h){
                printf("*");
            } else if(i==w-h+1){
                printf("*");
            }else printf(" ");
        }//1bantan
        printf("\n");
        for(i=h;i>=1;i--){
            for(v=0;v<h;v++){
                printf(" ");
            }
            for(j=i;j<h;j++){
                printf(" ");
            }
            for(k=1;k<(i*2);k++){
                printf("*");
            }
            printf("\n");
            }//สามเหลี่ยมคว่ำ

        for(i=2;i<h;i++){
            for(v=0;v<h;v++){
            printf(" ");
            }
            for(j=i;j<h;j++){
                printf(" ");
            }
            for(k=1;k<(i*2);k++){
                printf("*");
            }
            printf("\n");
            }  //ฐาน
        for(i=1;i<=row;i++){
            for(j=1;j<w;j++){
                if(j==row+3){
                printf("*");
                }else printf(" ");
            }
            printf("\n");
        }
        if(row==1){
            printf("   *");
            printf("\n");
            printf("  ***  ");
            printf("\n");
        }else {
        for(i=h-1;i<=h;i++){
            for(v=0;v<h;v++){
                printf(" ");
            }
            for(j=i;j<h;j++){
                printf(" ");
            }
            for(k=1;k<(i*2);k++){
                printf("*");
            }
            printf("\n");
        }
        }
}else printf("Please input 1,3,5,7,9,11,13,15,17,19\n");
}

