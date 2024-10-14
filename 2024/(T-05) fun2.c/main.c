#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    char endereco[100];
    float circTor; 
    float dist_CP;
} Gato;

float calcularPGCF(Gato gato) {
    return (((gato.circTor / 0.7067) - gato.dist_CP) / 0.9156) - gato.dist_CP;
}

const char* classificarPGCF(float pgcf) {
    if (pgcf < 20) {
        return "Abaixo do peso";
    } else if (pgcf >= 20 && pgcf < 27) {
        return "Peso ideal";
    } else {
        return "Acima do peso";
    }
}

Gato* alocarGatos(int numGatos) {
    Gato *gatos = (Gato*) malloc(numGatos * sizeof(Gato));
    for (int i = 0; i < numGatos; i++) {
        printf("\n------------------- Gato %i -------------------\n", i+1);
        printf("Nome do gato: ");
        scanf("%s", gatos[i].nome);
        printf("Endere�o: ");
        scanf(" %99[^\n]", gatos[i].endereco);
        printf("Circunfer�ncia Tor�cica (cm): ");
        scanf("%f", &gatos[i].circTor);
        printf("Dist�ncia Calc�neo-Patela (cm): ");
        scanf("%f", &gatos[i].dist_CP);
    }
    return gatos;
}

void exibirGato(Gato gato) {
    printf("\n----------------------------------------------\n");
    printf("Nome: %s\n", gato.nome);
    printf("Endere�o: %s\n", gato.endereco);
    printf("Circunfer�ncia Tor�cica: %.2f cm\n", gato.circTor);
    printf("Dist�ncia Calc�neo-Patela: %.2f cm\n", gato.dist_CP);
    float pgcf = calcularPGCF(gato);
    printf("PGCF: %.2f\n", pgcf);
    printf("Classifica��o: %s\n", classificarPGCF(pgcf));
    printf("----------------------------------------------\n");
}

int encontrarGatoPorNome(Gato *gatos, int tamanho, const char *nome) {
    if (tamanho == 0) 
        return -1; 
    if (strcmp(gatos[0].nome, nome) == 0)
        return 0;
    int resultado = encontrarGatoPorNome(gatos + 1, tamanho - 1, nome);
    if (resultado == -1) 
        return -1;
    else
        return resultado + 1;
}

int main() 
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao, numGatos = 0;
    char nomeBuscado[50];
    Gato *gatos = NULL;

    do {
        printf("\n-------------------- Menu --------------------\
        \n[1] Inserir novo conjunto de gatos\
        \n[2] Buscar e exibir dados de gatos por nome\
        \n[3] Finalizar\
        \nOp��o: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Quantos gatos deseja cadastrar? ");
            scanf("%d", &numGatos);
            gatos = alocarGatos(numGatos);
        } else if (opcao == 2 && gatos != NULL) {
            printf("Informe o nome do gato que deseja buscar: ");
            scanf("%s", nomeBuscado);
            if (encontrarGatoPorNome(gatos, numGatos, nomeBuscado) != -1) {
                exibirGato(gatos[encontrarGatoPorNome(gatos, numGatos, nomeBuscado)]);
            } else {
                printf("Gato n�o encontrado.\n");
            }
        }
        else if (opcao == 3){
            printf("\nPrograma encerrado!!\n\n");
        }
        else
            printf("\nOp��o invalida!\n\n");     
    } while (opcao != 3);
}
