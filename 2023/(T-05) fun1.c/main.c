#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_MAQUINAS 100 

typedef struct {
    int registro;              
    char tipo[50];            
    char modelo[50];          
    char fabricante[50];
    float diaAluguel;        
} Maquina;

void texto(Maquina maquina) {
    printf("\n%s\n", "-------------------------------------------------");
    printf("Número de registro: %d\n", maquina.registro);
    printf("Tipo: %s\n", maquina.tipo);
    printf("Modelo: %s\n", maquina.modelo);
    printf("Fabricante: %s\n", maquina.fabricante);
    printf("Aluguel diário: R$ %.2f\n", maquina.diaAluguel);
}

float calculoAluguel(Maquina maquina, int dias) {
    return dias * maquina.diaAluguel;
}

int preencheMaquina(Maquina *maquinas, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("\n%s\n", "-------------------------------------------------");
        printf("Digite o número de registro: ");
        scanf("%d", &maquinas[i].registro);

        printf("Digite o tipo da máquina: ");
        scanf(" %[^\n]", maquinas[i].tipo); 

        printf("Digite o modelo da máquina: ");
        scanf(" %[^\n]", maquinas[i].modelo);

        printf("Digite o fabricante: ");
        scanf(" %[^\n]", maquinas[i].fabricante);

        printf("Digite o valor diário do aluguel: R$");
        scanf("%f", &maquinas[i].diaAluguel);
    }
    return tam; 
}

int listaMaquinario(Maquina *maquinas, int tam, const char *tipo) {
    int contando = 0;
    for (int i = 0; i < tam; i++) {
        if (tipo == NULL || strcmp(maquinas[i].tipo, tipo) == 0) {
            texto(maquinas[i]);
            contando++;
        }
    }
    return contando; 
}

int busca(Maquina *maquinas, int tam, int registro) {
    for (int i = 0; i < tam; i++) {
        if (registro == maquinas[i].registro) {
            return i;
        }
    }
    return -1; 
}

int main() 
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    while (1) {
        int quantMaquina, op;
        printf("Digite a quantidade de máquinas: ");
        scanf("%d", &quantMaquina);

        Maquina maquinas[MAX_MAQUINAS]; 
        preencheMaquina(maquinas, quantMaquina); 
        
        while (1) {
            printf("\n%s\n", "-------------------------------------------------");
            printf("[1] - Entrar com um conjunto novo de máquinas.\n"
                   "[2] - Listar maquinas por tipo.\n"
                   "[3] - Pesquisar maquina por registro.\n"
                   "[4] - Sair\n"
                   "-------------------------------------------------\n");
            printf("Escolha a sua opção: ");
            scanf("%d", &op);
            
            if (op == 1) {
                break; 
            } 
            else if (op == 2) {
                char tipo[50];
                printf("Digite o tipo de máquina: ");
                scanf(" %[^\n]", tipo); 
                int numMaquina = listaMaquinario(maquinas, quantMaquina, tipo);
                printf("\n%d máquina(s) encontrada(s).\n", numMaquina);
            } 
            else if (op == 3) {
                int registro;
                printf("Digite o registro da máquina: ");
                scanf("%d", &registro);
                int pesquisa = busca(maquinas, quantMaquina, registro);
                if (pesquisa == -1) {
                    printf("Não encontrado!\n");
                } 
                else {
                    texto(maquinas[pesquisa]);
                    int dias;
                    printf("\nDigite a quantidade de dias: ");
                    scanf("%d", &dias);
                    float aluguel = calculoAluguel(maquinas[pesquisa], dias);
                    printf("Valor total do contrato de aluguel, R$ %.2f\n", aluguel);
                }
            } 
            else if (op == 4) {
                printf("Programa encerrado!\n");
                exit(0);
            } 
            else 
                printf("Opção inválida!\n");
        }
    }
}
