#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main(){
    int dice,position=0;
    char c;
    srand(time(NULL));
    printf("Start\n");
    do{
        printf("Press y for roll\n");
        scanf(" %c",&c);
        if(c=='y'){
        dice=rand()%6;
        dice++;
        position+=dice;
        if(position>100) position = 100;
        printf("You roll %d\n",dice);
        printf("You position is %d\n",position);
        }
    }while(position<100);
    printf("\nSuccess");
}

