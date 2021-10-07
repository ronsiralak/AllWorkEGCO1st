#include <stdio.h>

struct point
{
    int x;
    int y;
    int z;
};

int main()
{
    int i,j;
    FILE *myfile;
    struct point p;

    // Writing to binary file
    myfile = fopen("point", "w");
    if (!myfile) {
        printf("Could not open file to write.");
        return 1;
    }

    for (i = 1; i < 12; i++){
        for (j = 0; j < 12; j++){
            p.x = (i + 1);
            p.y = (j + 1);
            p.z = p.x*p.y;
            fwrite(&p, sizeof(struct point), 1, myfile);
    }
    }
    fclose(myfile);

    // Reading from binary file
    myfile = fopen("point", "r");
    if (!myfile) {
        printf("Could not open file to write.");
        return 1;
    }

    for (i = 1; i < 12; i++){
            for (j = 0; j < 12; j++){
        fread(&p, sizeof(struct point), 1, myfile);
        printf("%d*%d = %d\n", p.x, p.y, p.z);
        }
        printf("----------------------\n");
    }
    fclose(myfile);

    return 0;
}
