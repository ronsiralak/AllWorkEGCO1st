#include <iostream>
#include"NODE.h"
#include"LL.h"
using namespace std;
LL::LL(){
       hol=NULL;
       size=0;
}

LL::~LL(){
          //clear all nodes
}

void LL::show_all(){
     NODE* t=hol;
     int i;
     for(i=0;i<size;i++){
                 /**
                 complete this part
                 */
     }
}
void LL::add_node(NODE *&A){

          hol->insert(A);
          hol=A;

       size++;

 }
