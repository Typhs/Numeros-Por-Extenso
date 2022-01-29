#include <stdio.h>
#include <stdlib.h>

int x = 0;

void unidade(FILE *w){

    if ((x>9) && ((x%10)>0)){
        fprintf(w," e "); //checa se a casa da dezena de x não é zero e se há outro dígito além da dezena para adicionar o "e"
    }
    x = x%10;//transforma números de 2 dígitos em de 1
    //printf("agora em Uidade, o x eh: %i",x);
    switch(x){
        case 1:
            fprintf(w,"um");
            break;
        case 2:
            fprintf(w,"dois");
            break;
        case 3:
            fprintf(w,"tres");
            break;
        case 4:
            fprintf(w,"quatro");
            break;
        case 5:
            fprintf(w,"cinco");
            break;
        case 6:
            fprintf(w,"seis");
            break;
        case 7:
            fprintf(w,"sete");
            break;
        case 8:
            fprintf(w,"oito");
            break;
        case 9:
            fprintf(w,"nove");
            break;
        case 0:;
            break;
    }
}

void dezena(FILE *w){
    if ((x>99) && ((x%100)>0)){
        fprintf(w," e "); //checa se a casa da centena de x não é zero e se há outro dígito além da centena para adicionar o "e"
    }
    x = x%100;//transforma número de 3 digitos em de 2
    //printf("agora em Dezena, x eh: %i\n",x);
    switch(x){
        case 10: //aqui ocorre uma peculiaridade, do 11 até o 19 na pronuncia não há regra constante de nomenclatura, cada numero é pronunciado de um jeito específico
            fprintf(w,"dez");
            break;
            //início da peculiaridade de 10 -----------
        case 11:
            fprintf(w,"onze");
            x = 0; // x é setado a dez em cada uma dessas exceções para evitar que a função da unidade seja ativada, já que nesses casos a unidade ja foi expressa
            break;
        case 12:
            fprintf(w,"doze");
            x = 0;
            break;
        case 13:
            fprintf(w,"treze");
            x = 0;
            break;
        case 14:
            fprintf(w,"quatorze");
            x = 0;
            break;
        case 15:
            fprintf(w,"quinze");
            x = 0;
            break;
        case 16:
            fprintf(w,"dezesseis");
            x = 0;
            break;
        case 17:
            fprintf(w,"dezessete");
            x = 0;
            break;
        case 18:
            fprintf(w,"dezoito");
            x = 0;
            break;
        case 19:
            fprintf(w,"dezenove");
            x = 0;
            break;
            //fim da peculiaridade de 10 --------------
        case 20 ... 29:
            fprintf(w,"vinte");
            break;
        case 30 ... 39:
            fprintf(w,"trinta");
            break;
        case 40 ... 49:
            fprintf(w,"quarenta");
            break;
        case 50 ... 59:
            fprintf(w,"cinquenta");
            break;
        case 60 ... 69:
            fprintf(w,"sessenta");
            break;
        case 70 ... 79:
            fprintf(w,"setenta");
            break;
        case 80 ... 89:
            fprintf(w,"oitenta");
            break;
        case 90 ... 99:
            fprintf(w,"noventa");
            break;
        default:
            break;
    }
}

void centena(FILE *w){
    if ((x>999) && ((x%1000)>0)){
        fprintf(w," e "); //checa se a casa da centena de x não é zero e se há outro dígito além da centena para adicionar o "e"
    }
    x = x%1000;//transforma número de 4 digitos em de 3
    //printf("agora em Centena, x eh: %i\n",x);
    switch(x){
        case 100 ... 199:
            if (x == 100){//nota-se uma peculiaridade dos numeros com uma centena,100 é "cem", entre 101 e 199 é "cento"
                fprintf(w,"cem");
            } else {
                fprintf(w,"cento");
            }
            break;
        case 200 ... 299:
            fprintf(w,"duzentos");
            break;
        case 300 ... 399:
            fprintf(w,"trezentos");
            break;
        case 400 ... 499:
            fprintf(w,"quatrocentos");
            break;
        case 500 ... 599:
            fprintf(w,"quinhentos");
            break;
        case 600 ... 699:
            fprintf(w,"seiscentos");
            break;
        case 700 ... 799:
            fprintf(w,"setecentos");
            break;
        case 800 ... 899:
            fprintf(w,"oitocentos");
            break;
        case 900 ... 999:
            fprintf(w,"novecentos");
            break;
        default:
            break;
    }
}

void milhar(FILE *w){
    //printf("agora em Milhar, x eh: %i\n",x);
    switch(x){
        case 0:
            fprintf(w,"zero");//caso o número seja zero ele escreve isso aqui, uma vez que as outras função não seriam ativadas por zero
            break;
        case 1000 ... 1999:
            fprintf(w,"mil");
            break;
        case 2000 ... 2999:
            fprintf(w,"dois mil");
            break;
        case 3000 ... 3999:
            fprintf(w,"tres mil");
            break;
        case 4000 ... 4999:
            fprintf(w,"quatro mil");
            break;
        case 5000 ... 5999:
            fprintf(w,"cinco mil");
            break;
        case 6000 ... 6999:
            fprintf(w,"seis mil");
            break;
        case 7000 ... 7999:
            fprintf(w,"sete mil");
            break;
        case 8000 ... 8999:
            fprintf(w,"oito mil");
            break;
        case 9000 ... 9999:
            fprintf(w,"nove mil");
            break;
        default:
            break;
    }
}


int main(){
//iniciação----------------------------------------------------------------
    int decimal = 0,menu = 0;
    double numero = 0;
    char palavra[100];
    FILE *arquivo_w, *arquivo_r;
    arquivo_w = fopen("numeros.txt","a");
    arquivo_r = fopen("numeros.txt","r");

//Corpo Principal----------------------------------------------------------
    menu = 1;
    //conjuncaoE(arquivo_w, 10); //isso testa a conjunçãoE

    printf("Digite 1 para adicionar ao documento ou 2 para ler\n");
    scanf("%i",&menu);
    if (menu == 1){//segue o processo de adicionar ao txt
        printf("Digite um numero (0000.00)\n");
        scanf("%lf",&numero);
        x = (int) numero;
        numero = (numero - x)*100;
        numero = numero + 0.5 - (numero<0);//arredonda a parte inteira do numero
        decimal = (int) (numero);//separa a parte decimal do numero em 'decimal'

        if (x>9999){
            printf("valor muito alto\n");
            exit(0);
        }

        fprintf(arquivo_w,"%d.%d: ",x,decimal);

        milhar(arquivo_w);//esse trecho ativa as funções que escrevem a parte inteira do numero por extenso no arquivo
        centena(arquivo_w);
        dezena(arquivo_w);
        unidade(arquivo_w);

        if (decimal != 0){//trecho que escreve a parte decimal do numero por extenso no arquivo
            fprintf(arquivo_w," virgula ");
            x = decimal;
            milhar(arquivo_w);
            centena(arquivo_w);
            dezena(arquivo_w);
            unidade(arquivo_w);
        } else {
            fprintf(arquivo_w," virgula zero");
        }
        fprintf(arquivo_w, "\n");// pula a linha ao fim do digito
        printf("valor gravado\n");
    }
    if (menu == 2){//segue o processo de ler o txt
        printf("Cheque: \n\n");
        while(fgets(palavra, 100, arquivo_r) != NULL){//essa estrutura escreve o que há no arquivo numeros.txt na tela
            printf("%s",palavra);
        }
    }
    if ((menu != 1) && (menu != 2)){
        printf("Valor invalido\n");
    }

//finalização--------------------------------------------------------------
    printf("\n");
    fclose(arquivo_r);
    fclose(arquivo_w);
    system("pause");
}
