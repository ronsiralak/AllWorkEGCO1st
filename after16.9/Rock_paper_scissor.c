#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int RPS() {
    printf("A child want to play Rock Paper Scissor with you\n");
    int a,b;
    char janken[3][10] = {"Rock","Paper","Scissor"};
    printf("You choose\n");
    printf(" 1.Rock\n");
    printf(" 2.Paper\n");
    printf(" 3.Scissor\n");
    printf(" etc. mean Rock\n");
    scanf("%d",&a);
    if(a!=1 || a!=2 || a!=3) a=1;
    b=rand()%3;
    printf("You choose %s\n",janken[a-1]);
    printf("Enemy choose %s\n",janken[b]);
    b++;
    if(a-b==1 || b-a == 2) {
        printf("You WIN\n");

    } else if(a==b) {
        printf("DRAW\n");
    } else {
        printf("You LOSE\n");
    }
}
void main() {
    srand(time(NULL));
    RPS();

}
