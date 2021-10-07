#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
int n,i,nc;
char word[40],shift[40];
printf("String  : ");
gets(word);
printf("Integer  : ");
scanf("%d",&nc);
nc=nc%26;
n = strlen(word);
printf("Reverse : ");
for (i=0; i<n; i++){
    printf("%c",word[n-1-i]);
    shift[i]=word[n-1-i]+nc;
}
printf("\n");
printf("Shifting : ");
for (i=0; i<n; i++){
    printf("%c",shift[i]);
}
printf("\n");
}
