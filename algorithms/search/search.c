#include <stdio.h>
#include <stdlib.h>

int * generateData (int);


int main(){
    int *dat;
    dat = generateData(10);
    int i = 0;
    while ((dat+i) != NULL){
         printf("%d", *(dat + (i++)));
    }

    return 0;
}
int *generateData(int size){
    int * dat;
    dat = ( int* ) malloc(sizeof( int) * size);
    for (int i = 0; i < size; i++){
        *(i+dat) = i;
    }
    return dat;
}
