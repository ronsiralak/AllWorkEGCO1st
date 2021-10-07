#include <stdio.h>
#include <string.h>
int main(){
int i,j;
char str[8][20]={"orange","banana","mango","apple","cherry","melon","grape","durian"};
char temp[20];
for (i=0; i<8; i++){
    printf("str[%d] = %s lenght is %d\n", i, str[i],strlen(str[i]));
}
 for(i=0;i<8;i++)
    for(j=i+1;j<8;j++){
      if(str[i][0]>str[j][0]){
        strcpy(temp,str[i]);
        strcpy(str[i],str[j]);
        strcpy(str[j],temp);
        }
    }
printf("\nOut : ");                        // (3)
  for(i=0;i<=8;i++)
    printf("%s ",str[i]);
}
