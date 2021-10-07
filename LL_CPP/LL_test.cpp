#include <iostream>
#include<cstdlib>
#include"NODE.h"
#include"LL.h"
using namespace std;
int main(int argc, char *argv[])
{  LL A;
   int i;
   NODE *t;

   for(i=1;i<argc;i++) {
                       t=new NODE(atoi(argv[i]));
                       A.add_node(t);
                       }
   A.show_all();
    system("PAUSE");
    return EXIT_SUCCESS;
}
