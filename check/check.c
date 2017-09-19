#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//in hindsight, this would not be the best to do in c, because of the way it handles strings
//based on an /r/dailyprogrammer problem
const char * singles[] = {" ", "one ",  "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
const char *xteens[] = {"", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
const char * tens[] = {"", "ten ", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
const char * units[] = {"hundred ", "thousand ", "million "};

char *mkDec(char *decimal){
        char *decc = (char*) malloc (sizeof(char)*50);
        int ten =  (strlen(decimal)>0)?(*(decimal))-48: 0;//zero if there is no decimal
        int one =  (strlen(decimal)>1)?(*(decimal+1))-48: 0;// zero if there is no 2nd digit on decimal

        decc = strcat(decc, " and ");
        if (ten == 1 && one > 0){
                decc = strcat(decc, xteens[one]);
        }
        else if (ten == 0 && one == 0){
                decc = strcat(decc, "zero ");
        }
        else{
                decc = strcat(decc, tens[ten]);
                decc = strcat(decc, " ");
                decc = strcat(decc, singles[one]);
        }
        decc = strcat(decc, "cents.");
        return decc;
}
//1000
char *mkMain(char *digits){//AAAAAAAAAAAAAAAAAAAAaaaaah!
        
        int maxSize = strlen(digits);
        //printf("%d\n", maxSize);
        char *veb = (char *) malloc (sizeof(char)*20*maxSize);
        int secSize = (maxSize-1)/3;
        int incThree = maxSize - (secSize*3)-1;//starts at which unit
        //printf("secSize%d,incThree: %d\n", secSize, incThree);
        int numInInt, intTeen, unitFlag ;
        unitFlag = 0;
        if (strlen(digits) <1 || (strlen(digits) == 1 && *(digits) == '0')){//if there are no digits, or if there is only one digit that is '0'
               veb = strcat(veb, "zero dollars");
                return veb;
        }
        if ((strlen(digits) == 1 && *(digits) == '1')){
               veb = strcat(veb, "one dollar");
               return veb;
        }


        for (int i = 0; i< maxSize; i++){
                numInInt = *(digits+i) - 48;//turn ascii into num
                if (numInInt != 0)
                        unitFlag = 1;
                //printf("\ni:%d,num:%d,loc:%d\n",i, numInInt, incThree);
               if (incThree == 1){ //if in the tens ex 10->1<-4
                       if (numInInt == 1 &&(intTeen = *(digits+(i+1)) - 48)>0){//xteens case ex 10->14 == fourteen
                                veb = strcat(veb, xteens[intTeen]);//adding string
                                i++;//increment to after ones
                               incThree = 2;//set to next section
                               if (secSize>0)//checking if it's the end of a section, or the end
                                       veb = strcat(veb, units[secSize]);
                               secSize--;
                        } 
                       else{//normal tens
                               veb = strcat(veb, tens[numInInt]);
                               incThree--;
                       }
               }
               else{
                       veb = strcat(veb, singles[numInInt]);
                       if (incThree == 0){//if in the zero state ex 101->4
                               incThree = 2;
                               if (secSize>0 && unitFlag){
                                       veb = strcat(veb, units[secSize]);
                                       unitFlag = 0;
                               }
                               secSize--;
                       }
                       else{// if in the hundreds state ex 1->0<-12
                               incThree--;
                               if (numInInt != 0){
                                       //printf("\n %d, %d \n", i, numInInt);//adds 'hundred' if there is >0 in the hundred spot
                                       veb = strcat(veb, units[0]);
                               }
                       }
               }
                //printf("\n%s\n", digits);
                //printf("\n%s\n", veb);
        }
        
       veb = strcat(veb, "dollars");

        return veb;
}


int main(){
        char input[256];
        char *decimal = (char*) malloc(sizeof(char)*100);
        char *dig = (char*) malloc(sizeof(char)*100);
        int dec = 0;
        int j = 0;
        int decimalIndex;
        printf("enter number");
        gets(input);
        int length = strlen(input);
        for (int i = 0; i < length; i++){
                if (input[i] == '.'){
                        decimalIndex = i;
                        dec = 1;
                }
                else if (!dec){
                        (*(dig+i)) = input[i];
                }
                else{
                        (*(decimal +j)) = input[i];
                        j++;
                }
        }




        //printf("%s-%s", dig, decimal);
         if (input[0] == 'q'){
                return 0;
        }
        else{

                char *vebDecimal = mkDec(decimal);
                char *vebDigits = mkMain(dig);
                printf("%s, %s\n",vebDigits, vebDecimal);
                free(vebDecimal);//free allocated variables
                free(vebDigits);
                free(decimal);
                free(dig);
        }

} 
