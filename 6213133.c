#include<stdio.h>
#include<stdlib.h>



typedef struct node {
    int id, score;
    struct node *Next;
} Node;
void insert_node(Node**,int,int);
void PrintAll(Node*);
void FreeAll(Node**);
void FindAvg(Node*);


int main() {
    struct node *st=NULL;
    struct node *head=NULL;
    int id_i,score_i,id;
    do {
        printf("INPUT ID: ");
        scanf("%d",&id_i);
        if(id_i !=0) {
            printf("INPUT SCORE: ");
            scanf("%d",&score_i);
            insert_node(&head,id_i,score_i);
        }
    } while(id_i !=0);

    PrintAll(head);
    FindAvg(head);
    FreeAll(&head);
    return 0;
}

void insert_node(Node** head,int id_i,int score_i ) {
    struct node *tmp = *head;
    struct node *NewNode;
    NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->id = id_i;
    NewNode->score = score_i;
    NewNode ->Next = NULL;

    if(*head == NULL) {
        *head = NewNode;
    } else {
        while(tmp->Next!=NULL) {
            tmp = tmp->Next;
        }
        tmp->Next = NewNode;
    }

}

void PrintAll(Node* head) {
    struct node *tmp;
    tmp = head;
    while(tmp!=NULL) {
        printf("ID : %3d   Score : %3d\n",tmp->id,tmp->score);
        tmp=tmp->Next;
    }
}

void FindAvg (Node* head) {
    float sum = 0;
    int n=0;
    struct node *tmp;
    tmp = head;
    while (tmp != NULL) {
        sum = sum + (tmp->score);
        tmp = tmp->Next;
        n++;
    }
    if(n==0){
        printf ("Average score = 0.00\n");
    }else{
        printf ("Average score = %.2f\n", sum / n);
    }

}

void FreeAll(Node** head) {
    struct node *tmp;
    while(tmp!=NULL) {
        tmp = *head;
        *head = (*head)->Next;
        free(tmp);
        tmp=tmp->Next;
    }
}
