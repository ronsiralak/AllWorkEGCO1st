#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int count = 0;
int cf=0;

int bubble(int[],int);
int selection(int[],int);
int insertion(int[],int);
void display(int[],int);

int main(int argc,char *argv[]) {
    char *Mode;
    int i, j, k, *a, N ;
    N = argc - 1;
    a = (int*)malloc(sizeof(int)*N);

    Mode = argv[1];

    for(i=0; i<=N-1; i++) {
        a[i] = atoi(argv[i+1]);
    }

    printf("\n");
    printf("Before Sorting :");

    for(i=1; i<N; i++) {
        printf(" %d",a[i]);
    }

    printf("\n");

    if(strcmp(Mode,"bubble")==0) {
        bubble(a,N);
    }

    if(strcmp(Mode,"selection")==0) {
        selection(a,N);
    }

    if(strcmp(Mode,"insertion")==0) {
        insertion(a,N);
    }

    if(strcmp(Mode,"bubble")!=0 && strcmp(Mode,"selection")!=0  &&  strcmp(Mode,"insertion")!=0) {
        printf("\n");
        printf("After Sorting : \"Error\"\nFunction have 1.bubble 2.selection 3.insertion ");
        printf("\n");

        return 0 ;
    }
    if(N-1<=0) {
        printf("NO Data");
        return 0 ;
    }

    printf("\n");
    printf("After Sorting : ");

    for(i=1; i<N; i++) {
        printf("%d ",a[i]);
    }

    printf("\nMoves with %s sort: %d times\n",Mode,count);
    printf("\nUSE FOR LOOP: %d times\n",cf);
}

int bubble(int a[],int N) {
    int i,j,temp;
    for (i = 0 ; i < N - 1; i++) {
        for (j = 0 ; j < N - i - 1; j++) {
                cf++;
            if (a[j] > a[j+1]) {
                temp  = a[j];
                a[j]   = a[j+1];
                a[j+1] = temp;
                count++;
                display(a,N);
            }
        }
    }
}

int selection(int a[],int N) {
    int i, j, m, mi, check ;

    for (i=0; i<N-1; i++) {
        mi = i;
        check = 0;

        for (j=i+1; j<N; j++) {
                cf++;
            if(a[j]<a[mi]) {
                mi=j;
                check=1;
            }
        }
        if(mi!= i) {
            m=a[i];
            a[i]=a[mi];
            a[mi]=m;
        }
        if(check==1) {
            count++;
            display(a,N);
        }

    }
}

int insertion(int a[],int N) {
    int i, j, value;
    for (i = 1; i < N; i++) {
            int printed = 0;
        value = a[i];
        for (j = i - 1; j >= 0; j--) {
                cf++;
            if (a[j] > value) {
                a[j + 1] = a[j];
                printed =0;
            } else
                break;
            if(printed == 0)display (a, i);
            printed =1;
            count++;
        }
        a[j + 1] = value;
        if(printed == 0)display (a, i+1);


    }
}
void display(int a[],int N) {
    int i;
    for(i=1; i<N; i++)
        printf("%5d",a[i]);
    printf("\n");

}
