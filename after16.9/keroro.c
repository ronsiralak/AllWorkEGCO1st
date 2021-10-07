#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
char word[40],name[5][40],temp[40];
int i,j,n,check=0,vowel=0;
do{
    printf("Name%d : ",check+1);
    gets(word);
    n= strlen(word);
    vowel=0;
    for(i=0;i<6;i++){
        if(word[i]==97 || word[i]==101 || word[i]==105 || word[i]==111 || word[i]==117 ){
            vowel++;
        }
    }
    if(n==6 && vowel==3){
        for (i=0; i<6; i++){
            if(word[i]==97 || word[i]==101 || word[i]==105 || word[i]==111 || word[i]==117 ){
                word[i] = toupper(word[i]);
            }else {word[i] =tolower(word[i]);}
            name[check][i]=word[i];
        }
        check++;
    }
}while (check<5);
for(i=0;i<5;i++)
    for(j=i+1;j<5;j++){
      if(name[i][0]>name[j][0]){
        strcpy(temp,name[i]);
        strcpy(name[i],name[j]);
        strcpy(name[j],temp);
        }
    }
printf("KeronArmy: ");
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
        printf("%c",name[i][j]);
    }
    printf(" ");
  }

}

