#include <stdio.h>
#include <string.h>
int main(){
int n,i;
char word[8];
printf("Input the string      : ");
gets(word);
n = strlen(word);
printf("Number of characters  : %d\n",n);
printf("String in reverse are : ");
for (i=n; i>=0; i--){
    printf("%c ",word[i]);
}

}
