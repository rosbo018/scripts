#include<stdio.h>
#include<stdlib.h>
#define NODEALLOC (NODE *) malloc(sizeof(NODE))

typedef struct NODE {
        struct NODE* back;
        struct NODE* next;
        int val;
}NODE;

NODE* initList (int inval){
        NODE* n = NODEALLOC;
        n->val = inval;
        return n;
}

void printList (NODE* start, NODE* end){
        NODE* index = start;
        printf("start\n");
        while(index != end){
                printf("%d\n", index->val);
                index = index->next;
        }
        printf("end\n");
}
NODE* addNODE ( NODE* location, int val){
        NODE* n =  NODEALLOC;
        n->val = val;
        n->next = location->next;
        n->back = location;
        location->next->back = n;
        location->next = n;
        return n;
}
int main(){
        NODE* start = initList(1);
        NODE* end = NODEALLOC;
        start->next = end;
        end->back = start;
        NODE* index = start;
        printList(start, end);
}

