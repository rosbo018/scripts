#include <stdio.h>

int **getInput(char *);
int getHotPoint( int**);
int* average(int*);
int max(int*, int *);

int ** dataArr;
int primePoint;
int radius;
int xyAverage[2];



int main(int argc, char *argv){
	dataArr = getInput(argv);
	primePoint = getHotPoint(dataArr);
	xyAverage = average(dataArr[primePoint]);
	radius = max(xyAverage, dataArr[primePoint]);
}
