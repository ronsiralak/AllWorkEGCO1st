#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int n=1,I=0,i=0,j,s=0;
    char  words[8];
    char sara[10]={'a','e','o','i','u','A','E','O','I','U'};
    char army[5][8];
   while(n<6){
   printf("Name[%d] :",n);
   gets(words);
    I=strlen(words);
    s=0;
       for(i=0;i<I;i++)
        {
            for(j=0;j<10;j++)
                {
                    if(words[i]==sara[j])
                    {
                        s++;
                    }
                }
        }
         if(s==3 || I==6){
                for(i=0;i<I;i++){
                    if(words[i]==97 || words[i]==101 || words[i]==105 || words[i]==111 || words[i]==117 ){
                        words[i]=toupper(words[i]);
                            }else{
                            words[i]=tolower(words[i]);
                                }
                    strcpy(army[n],words);
                    }

        n++;
       }
	}
	printf("KeronArmy :");
    for(i=0;i<n;i++)
        printf("%s\n",army[i]);
}
