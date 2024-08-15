#include <stdio.h>
#include <string.h>

//Função de tipo de dado "maquina"
typedef struct{
    int registro;
    char tipo[50];
    char modelo[50];
    char fabricante[50];
    float valorDia;
}Maquina;

//Função (a)
float totalContrato(float valorDia, int dias){
    float aluguelTotal;
    return aluguelTotal = valorDia*dias;
}
//Função (b)
//Tipo "void" quando não retorna dado 
void preencher(Maquina maq[], int num){
    for (int i=0; i<num; i++){ //Dados de cada máquinas
        printf("\n---------------- Máquina %i ----------------", i+1);
        printf("\nDigite o numero de registro: ");
        scanf("%i", &maq[i].registro);
        
        printf("Digite o tipo: ");
        scanf("%s", maq[i].tipo);
        
        printf("Digite o modelo: ");
        scanf("%s", maq[i].modelo);
        
        printf("Digite o fabricante: ");
        scanf("%s", maq[i].fabricante);
        
        printf("Valor do aluguel diario: ");
        scanf("%f", &maq[i].valorDia);
    }
}
//Função (c)
void tipoEspecifico(Maquina maq[], int num, char tipo[50]){
    for(int i=0; i<num; i++){
        if(strcmp(maq[i].tipo, tipo) == 0){
            printf("\n---------------- Máquina %i ----------------", i+1);
            printf("\nNumero de registro: %d", maq[i].registro);
            printf("\nTipo: %s ",maq[i].tipo);
            printf("\nModelo: %s",maq[i].modelo);
            printf("\nFabricante: %s", maq[i].fabricante);
            printf("\nAluguel diario: %.2f\n", maq[i].valorDia);
        }
    }
}
//Função (d)
int registroEspecifico(Maquina maq[], int num, int registro){
    for(int i=0; i<num; i++){
        if(registro == maq[i].registro){
            return i;
        }
    }
    return -1;
}

int main()
{
    int num, op = 0, registro;
    char tipo[50];
    
    while(op!=4){
        printf("Informe o número de máquinas: ");
        scanf("%i", &num);
        
        Maquina maq[num];
        preencher(maq, num);
        
        while(1){ //Menu de opções
            printf("\n-------------------------------------------\
            \n[1]Entrar com um novo conjunto de máquinas\
            \n[2]Listar máquinas de um determinado tipo\
            \n[3]Pesquisar uma máquina pelo registro\
            \n[4]Encerrar\
            \n-------------------------------------------\
            \nOpção: ");
            scanf("%i", &op);
            
            if(op==1){
                break;
            }
            else if(op==2){
                printf("Escolha o tipo de máquina: ");
                scanf("%s", tipo);
                
                tipoEspecifico(maq, num, tipo);
            }
            else if(op==3){
                printf("Digite o número de registro da máquina: ");
                scanf("%d", &registro);
                
                int retorno = registroEspecifico(maq, num, registro);
                
                if(retorno>=0){
                    printf("\n----------- Máquina %i -----------", retorno+1);
                    printf("\nNumero de registro: %d", maq[retorno].registro);
                    printf("\nTipo: %s ",maq[retorno].tipo);
                    printf("\nModelo: %s",maq[retorno].modelo);
                    printf("\nFabricante: %s", maq[retorno].fabricante);
                    printf("\nAluguel diario: %.2f\n", maq[retorno].valorDia);
                }
                else
                    printf("Máquina não encontrada!\n");
                
                int dias;
                printf("\nDigite a quantidade de dias: ");
                scanf("%i", &dias);
                printf("%.2f R$\n", totalContrato(maq[retorno].valorDia, dias));
            }
            else if(op==4){
                printf("Programa encerrado!");
                break;
            }
            else{
                printf("Opção invalida!\n");
            }
        }
    }
}
