#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define int signed short int
const signed char NEG_ONE = 128+127; //NICE!, buffer overflow magic 

#define NUMALLOC (num*) malloc(sizeof(num));
// calculator only using +
// input parsing is not working because im too lazy

typedef struct num {
        int val;
        bool neg;
}num;

int getNeg(int val){
        int result = 0;
        for (int x = 0; x<val; x++)
                result += NEG_ONE;
        return result;
}
int getPos(int negetiveVal){
        int count;
        for (int i = 0; i > negetiveVal; i--)
                count++;
        return count;
}
num* add(num* a, num* b){
        num* result = NUMALLOC;
       int negval; 
        
       if (!(a->neg != b->neg)){
               result->val = a->val + b->val;
               result->neg = (a->neg && b->neg)? 1:0;
       }
       else {
               if (a->neg){
                       negval = getNeg(a->val) + b->val;
               }
               else{
                       negval = getNeg(b->val) + a->val;
               }
               if (negval< 0){
                       result->val = negval*-1;
                       //result->val = getPos(negval);
                       result->neg = 1;
               }
               else {
                       result->val = negval;
                       result->neg = 0;
               }
       }
       //printf("\n%hi %d\n", result->val, result->neg);
       return result;
}
num* sub(num* a, num* b){
        b->neg = !b->neg;
        return add(a,b);
}
              
num* multiply(num* x, num* y){
        num * result = NUMALLOC;
        result->val = 0;
        result->neg = ((x->neg != y->neg)) ? 1 : 0;
        for (int i = 0; i< y->val; i++)
                result->val += x->val;
        return result;
}
num* divide(num* x, num* divisor){
        int sum = 0;
        num* result = NUMALLOC;
        result->val = 0;
        result->neg = ((x->neg != divisor->neg)) ? 1 : 0;

        while (sum != x->val){
                sum += divisor->val;
                result->val++;
                if (sum > x->val){
                        printf("non integer divison\n");
                        return NULL;
                }
        }
        return result;
}
num* exponent (num *base, num *exp){
        num *result = NUMALLOC;
        result->val = 1;
        result->neg = 0;
        if (exp->val ==0)
                return result;
        if(exp->val< 0 || exp->neg)
                return NULL;
        for (int i = 0; i< exp->val; i++)
                result = multiply(result, base);
        return result;


}
        
void print(num* x){
        if(( x != NULL)){
                if (x->neg)
                        printf("-%hi\n", x->val);
                else
                        printf("%hi\n", x->val);
        }
}

/*char parseInput(char* inp, num* n1, num*n2){
        int numstart = 0;
        int numend = 0;
        char num[50];
        for(int i = 0; i < strlen(inp); i++){
                if(inp[i] == '-' || isdigit(inp[i])){
                        n1->neg = (inp[i] == '-')? 1:0;
                        numstart = i;
                        for(int j = 0; j < strlen(inp); j++){
                                if (!isdigit(inp[j]))
                                        numend = j;
                        }
                        for(int x = 
                        n1->hj

                }

}*/

int main(){
        num *x, *y, *result;
        /*
        char str[100];
        char op;
        printf("num1");
        gets(str);
        x->val = str;
        x->neg = 0;

        printf("num1");
        gets(str);
        y->val = str;
        y->neg = 0;

        
        printf("op");
        getc(op);

        switch(op){
                case '+':
                        result = add(x,y);
                        break;
                case '-':
                        result = sub(x,y);
                        break;
                case'/':
                        result = divide(x,y);
                        break;
                case '*':
                        result = multiply(x,y);
                        break;
        }*/
         x = NUMALLOC;
        y= NUMALLOC;
        x->val = 5;
        x->neg = 1;
        y->val = 5;
        y->neg = 0;
        print(exponent(x,y));

}
