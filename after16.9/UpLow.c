#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
int n,i;
char word[40];
printf("Input  : ");
gets(word);
n = strlen(word);
printf("Output : ");
for (i=0; i<n; i++){
    if(word[i]==97 || word[i]==101 || word[i]==105 || word[i]==111 || word[i]==117 ){
       word[i] = toupper(word[i]);
    }else word[i] =tolower(word[i]);
    printf("%c",word[i]);
}

}
