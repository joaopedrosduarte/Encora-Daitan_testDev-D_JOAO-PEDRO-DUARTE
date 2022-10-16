#include <stdio.h>
#include <stdlib.h> 

int countPennies = 0, countNickels = 0, countDimes = 0, countQuarters = 0, countChanges = 0;

void makeChange();
void countValue(int value);

int main(void) 
{
    //variavel que armazena a quantidade de cents
    int value;
    //recebendo os cents na variavel value
    scanf("%d",&value);
    //entrando na função countValue
    countValue(value);
    //printando o inicio da padronização
    printf("[");
    //while que compara o numero de pennies com a quantidade de cents no total,
    //ou seja se a quantidade de pennies for a quantidade de cents totais, significa que
    //todas as transferencias foram feitas e só resta a ultima possibilidade para ser printada.
    while (countPennies != value){
        //printando uma possibilidade
        printf("[%d %d %d %d], ",countQuarters, countDimes, countNickels, countPennies);
        //entra na função makeChange
        makeChange();
    }
    //printando a ultima possibilidade
    printf("[%d %d %d %d]]\n",countQuarters, countDimes, countNickels, countPennies);

    //retornando 0 para função main, ou seja dizendo que ela ja terminou.
    return 0;
}

//Função responsavel por trocar moedas com valores maiores em moedas com valores menores porem com a mesma quantidade de cents, que no caso de
//ser 1 quarter ( 25 cents ) seria trocado por 2 dimes ( cada um 10 cents ) e 1 nickel ( 5 cents ).
void makeChange(){
    //Se o numero de nickels for diferente de 0, ele transforma uma moeda nickels em 5 moedas de pennies, ou seja, diminui um no numero de moedas de nickels e aumenta 5 a quantidade de pennies.
    if (countNickels != 0){
        countNickels--;
        countPennies += 5;
    }
    //Se o numero de dimes for diferente de 0, ele transforma uma moeda dime em 2 moedas de nickels, ou seja, diminui um no numero de moedas de dimes e aumenta 2 a quantidade de nickels.
    else if (countDimes != 0){
        countDimes--;
        countNickels += 2;
    }
    //Se o numero de quarters for diferente de 0, ele transforma uma moeda quarters em 2 moedas de dimes e uma de nickel, ou seja, diminui um no numero de moedas de quarters, aumenta 2 a quantidade de dimes e 1 a quantidade de nickels.
    else if (countQuarters != 0){
        countQuarters--;
        countDimes += 2;
        countNickels++;
    }
}

//Função responsavel por traduzir o valor de cents recebidos no menor numero de moedas correspondestes a essa quantidade de cents, 
//por exemplo 26 cents seriam traduzidos em 1 quarter e 1 pennie.
void countValue(int value)
{
    //Valor copiado do args para uma variavel local, costume de boas praticas
    int aux = value;
    //laço de repetição que roda enquanto a variavel aux for diferente de 0;
    while(aux != 0){
        //sé o aux for maior ou igual a 25 a maior moeda a alcançar o valor sera a de 25, ou seja entra na condicional se aux for maior ou iguala 25
        if(aux >= 25){
            //Ja que entrou na condição ou seja foi escolhida uma moeda de 25, se diminui 25 cents no valor da variavel aux, 
            //que armazena o total de cents que as moedas devem repersentar.
            aux -= 25;
            //Soma mais um quarter na quantidade de quarters
            countQuarters++;
        } 
        // segue a mesma linha de raciocinio do quarter, porem só é possivel entrar nessa condicional se a primeira condição for falsa, 
        // ou seja é menor que 25 e se for maior ou igual a 1, ele entra nessa condição.
        else if (aux >= 10){
            //Diminui 10 no valor de aux e soma 1 no total de moedas de dimes.
            aux -= 10;
            countDimes++;
        } 
        // segue a mesma exata logica do if de cima, se for maior que 5 e menor que 10 entra na condicional.
        else if (aux >= 5){
            //Diminui 5 no valor de aux e soma 1 no total de moedas de nickels.
            aux -= 5;
            countNickels++;
        }
        // segue a mesma exata logica do if de cima, se for maior que 1 e menor que 5 entra na condicional.
        else if (aux >= 1){
            //Diminui 1 no valor de aux e soma 1 no total de moedas de pennies.
            aux -= 1;
            countPennies++;
        }
    }
}