#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int casino() {
    int n,bet,result;
    printf("Welcome to Casino\n");
    printf("Bet money if you bet more than gold mean all in however bet less than 0 mean 0:");
    scanf("%d",&bet);
    if(bet>tester.gold)
        bet = tester.gold;
    if(bet<0)
        bet =0;
    printf("Head or Tail\n");
    printf("1 for Head\n");
    printf("2 for Tail\n");
    printf("etc. mean Head\n");
    scanf("%d",&n);
    result = 1+(rand()%2);
    if(n==result) {
        printf("You WIN\n");
        tester.gold = tester.gold + bet;
    } else  {
        printf("You LOSE\n");
        tester.gold = tester.gold - bet;
    }

    printf("Now you have %d gold",tester.gold);
}
void main() {
    srand(time(NULL));
    casino();
}
