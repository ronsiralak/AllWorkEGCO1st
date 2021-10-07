#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
FILE *drop_data;
int n,i;
struct item
{
    char item_name[40];
    int gold,item_hp,item_atk;
};
struct item drop = {"",0,0,0};
void space(char str[40],int len){
for(i=0;i<len;i++){
    if(str[i]=='_') str[i]= ' ' ;
}
}
void main(){
    drop_data = fopen("drop.txt", "r");
    printf("input: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        fscanf(drop_data,"%d %d %d %s",&drop.gold,&drop.item_hp,&drop.item_atk,drop.item_name);
             // printf(mon,"%d %d %d %s",drop.gold,drop.item_hp,drop.item_atk,drop.item_name);
    }
    space(drop.item_name,strlen(drop.item_name));

printf("%d %d %d %s\n",drop.gold,drop.item_hp,drop.item_atk,drop.item_name);
printf("you get gold: %d\n item: %s",drop.gold,drop.item_name);
fclose(drop_data);
}
