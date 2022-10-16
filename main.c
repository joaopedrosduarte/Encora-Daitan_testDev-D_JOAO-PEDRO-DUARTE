#include <stdio.h>
#include <stdlib.h> 

int countPennies = 0, countNickels = 0, countDimes = 0, countQuarters = 0, countChanges = 0;

void makeChange();
void countValue(int value);

int main(void) 
{
    int value;
    scanf("%d",&value);
    countValue(value);
    printf("[");
    while (countPennies != value){
        printf("[%d %d %d %d], ",countQuarters, countDimes, countNickels, countPennies);
        makeChange();
    }
    printf("[%d %d %d %d]]\n",countQuarters, countDimes, countNickels, countPennies);

    return 0;
}

void makeChange(){
    if (countNickels != 0){
        countNickels--;
        countPennies += 5;
    }
    else if (countDimes != 0){
        countDimes--;
        countNickels += 2;
    }
    else if (countQuarters != 0){
        countQuarters--;
        countDimes += 2;
        countNickels++;
    }
}

void countValue(int value)
{
    int aux = value;
    while(aux != 0){
        if(aux >= 25){
            aux -= 25;
            countQuarters++;
        } 
        else if (aux >= 10){
            aux -= 10;
            countDimes++;
        } 
        else if (aux >= 5){
            aux -= 5;
            countNickels++;
        }
        else if (aux >= 1){
            aux -= 1;
            countPennies++;
        }
    }
}