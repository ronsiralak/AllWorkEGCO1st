#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
FILE *SAVE,*LOAD;
int position =10;
struct player {
    char name[100];
    int max_hp,hp,atk,gold;
    int item[5];
};
struct player tester = { "test",2,200,15,200,{2,2,2,2,2}};
void save() {
    SAVE = fopen("save.txt","w");
    fprintf(SAVE,"%s\n",tester.name);
    fprintf(SAVE,"%d %d %d %d %d %d %d %d %d %d\n",tester.max_hp,tester.hp,tester.atk,tester.gold,tester.item[0],tester.item[1],tester.item[2],tester.item[3],tester.item[4],position);
    fclose(SAVE);
}
void load() {
    LOAD = fopen("save.txt","r");
    fgets(tester.name,100,LOAD);
    fscanf(LOAD,"%d %d %d %d %d %d %d %d %d %d\n",&tester.max_hp,&tester.hp,&tester.atk,&tester.gold,&tester.item[0],&tester.item[1],&tester.item[2],&tester.item[3],&tester.item[4],&position);
    fclose(LOAD);
}

void status() {
    char temp[5];
    int i,n=0;
    itoa(tester.hp,temp,10);
    n=n+strlen(temp);
    itoa(tester.max_hp,temp,10);
    n=n+strlen(temp);
    itoa(tester.atk,temp,10);
    n=n+strlen(temp);
    itoa(tester.gold,temp,10);//convert int to string (,,base number)
    n=n+strlen(temp);
    //printf("%d\n",strlen(tester.name));
    printf("+");
    for(i=0; i<strlen(tester.name)+n+23; i++)
        printf("-");
    printf("+\n");
    printf("| Name:%s HP %d/%d ATK %d gold %d |\n",tester.name,tester.hp,tester.max_hp,tester.atk,tester.gold);
    printf("+");
    for(i=0; i<strlen(tester.name)+n+23; i++)
        printf("-");
    printf("+\n");
}
void main() {
    load();
    status();
    printf("%d %d %d %d %d %d",tester.item[0],tester.item[1],tester.item[2],tester.item[3],tester.item[4],position);

}
