#include <stdio.h>
#include <string.h>
int main(){
char word[20];
int i,n,check;
do{
    check=1;
    printf("Input a word : ");
    gets(word);
    n=strlen(word);
    if(n%2==0){
        for(i=1;i<=(n)/2;i++){
            if(word[i-1]!=word[n-i])
                check=0;
        }
    }else {
    for(i=1;i<=(n-1)/2;i++){
            if(word[i-1]!=word[n-i])
                check=0;
        }
    }
    if(word[0]=='q'&&word[1]=='u'&&word[2]=='i'&&word[3]=='t'){}
    else{
    if(check==1)
        printf("--> Palindrome\n");
    else printf("--> Non-Palindrome\n");
    }

} while (word[0]!='q'||word[1]!='u'||word[2]!='i'||word[3]!='t');

}
