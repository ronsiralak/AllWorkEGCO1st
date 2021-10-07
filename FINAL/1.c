#include <stdio.h>
void main() {
    int i,n;
    struct student {
        char name[30];
        int  room;
        struct friend {
            char name[30];
            int  room;
        }data_friend;
    };
    scanf("%d",&n);
    struct student st[100];

    for(i=0; i<n; i++) {
        printf("Input name[%d]: ",i+1);
        gets(st[i].name);
        /* printf("Input score: ");
         scanf("%f",&st[i].score);
         printf("Input grade: ");
         scanf("%f",&st[i].grade);*/
    }
    for(i=0; i<n; i++) {
        printf("%s %d %.2f\n",st[i].data_friend.room,st[i].name,st[i].room);
    }
}
