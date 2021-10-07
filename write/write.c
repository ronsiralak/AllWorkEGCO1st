#include<stdio.h>
int main(){
int a = 187;
int b = 3;
int p,m,t,mod;
float d;
p=a+b;
m=a-b;
t=a*b;
mod = a%b;
d = a/b;
char ear[6] = " /\\_/\\ ";
printf("       %s ",ear);
printf("\n     =(  0 0  )=\n");
printf("        > - <");
printf("\n _ _ _ _ _ _ _ _ _ _\n");
printf("|                   |\n",p);
printf("|  187 + 3 = %d    |\n",p);
printf("|  187 - 3 = %d    |\n",m);
printf("|  187 * 3 = %d    |\n",t);
printf("|  187 / 3 = %d      |\n",d);
printf("|  187 %% 3 = %d      |\n",mod);
printf("|_ _ _ _ _ _ _ _ _ _|\n");

printf("My ID: 6213133");
}
