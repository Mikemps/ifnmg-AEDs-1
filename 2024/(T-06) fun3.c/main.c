#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Engenheiro {
    int id;
    char nome[50];
    char formacao[50];
} Engenheiro;

typedef struct Projeto {
    int idProjeto;
    char descricao[100];
    float valor;
    Engenheiro *engenheiro;   
} Projeto;

float totalContratos(Projeto *projetos, int tamanho, Engenheiro *engenheiro) {
    if (tamanho == 0) {
        return 0;
    }
    float valorAtual = 0;
    if (projetos[tamanho - 1].engenheiro == engenheiro) {
        valorAtual = projetos[tamanho - 1].valor;
    }
    return valorAtual + totalContratos(projetos, tamanho - 1, engenheiro);
}

Engenheiro *buscarEngenheiro(Engenheiro *engenheiros, int tamanho, const char *nome) {
    if (tamanho == 0) {
        return NULL;
    }
    if (strcmp(engenheiros[tamanho - 1].nome, nome) == 0) {
        return &engenheiros[tamanho - 1];
    }
    return buscarEngenheiro(engenheiros, tamanho - 1, nome);
}

int main() 
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Engenheiro *engenheiros = NULL;
    Projeto *projetos = NULL;
    int quantEnge = 0, quantProj = 0, op, salvar;
    
    FILE *file = fopen("dados.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &quantEnge);
        engenheiros = malloc(quantEnge * sizeof(Engenheiro));
        for (int i = 0; i < quantEnge; i++) {
            fscanf(file, "%d %s %s", &(engenheiros)[i].id, (engenheiros)[i].nome, (engenheiros)[i].formacao);
        }
    
        fscanf(file, "%d", &quantProj);
        projetos = malloc(quantProj * sizeof(Projeto));
        for (int i = 0; i < quantProj; i++) {
            int id_eng;
            fscanf(file, "%d %s %f %d", &(projetos)[i].idProjeto, (projetos)[i].descricao, &(projetos)[i].valor, &id_eng);
            (projetos)[i].engenheiro = &(engenheiros)[id_eng];
        }
        fclose(file);
    }

    do {
        printf("[1] Inserir projeto\n");
        printf("[2] Inserir engenheiro \n");
        printf("[3] Exibir projetos\n");
        printf("[4] Exibir engenheiros\n");
        printf("[5] Pesquisar engenheiro por nome\n");
        printf("[6] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        if(op > 6 || op < 1)
            printf("\nOpção inválida.\n\n");

        switch (op) {
            case 1: {
                if (quantEnge == 0) {
                    printf("\nNão há engenheiros cadastrados.\n\n");
                    break;
                }
            
                quantProj += 1;
                projetos = realloc(projetos, (quantProj) * sizeof(Projeto));
                Projeto *novo = &(projetos)[quantProj - 1];
                novo->idProjeto = quantProj - 1;  
            
                printf("Descrição do projeto: ");
                scanf(" %[^\n]", novo->descricao);
                printf("Valor do projeto: ");
                scanf("%f", &novo->valor);
            
                printf("\nEscolha o engenheiro responsável pelo projeto:\n");
                for (int i = 0; i < quantEnge; i++) {
                    printf("[%d] - %s\n", engenheiros[i].id, engenheiros[i].nome);
                }
            
                int escolha;
                printf("Digite o ID do engenheiro: ");
                scanf("%d", &escolha);
            
                novo->engenheiro = &engenheiros[escolha];
                break;
            }
            case 2: {
                int ids[quantProj];
                if(quantProj > 0) {
                    for (int i = 0; i < quantProj; i++) {
                        ids[i] = projetos[i].engenheiro->id;  
                    }
                }
                
                quantEnge += 1;
                engenheiros = realloc(engenheiros, (quantEnge) * sizeof(Engenheiro));
                Engenheiro *novo = &(engenheiros)[quantEnge - 1];
                novo->id = quantEnge - 1;  
                
                printf("Nome do engenheiro: ");
                scanf(" %[^\n]", novo->nome);
                printf("Formação do engenheiro: ");
                scanf(" %[^\n]", novo->formacao);
                
                if(quantProj > 0) {
                    for (int i = 0; i < (quantProj); i++) {
                        projetos[i].engenheiro = &engenheiros[ids[i]];
                    }
                }
                break;
            }
            case 3: {
                if (quantProj == 0) {
                    printf("\nNenhum projeto cadastrado\n\n");
                    break;
                }
                printf("\n-------------------- Projetos --------------------");
                for (int i = 0; i < quantProj; i++) {
                    printf("\nProjeto: %s, Valor: R$ %.2f, Engenheiro: %s\n", projetos[i].descricao, projetos[i].valor, projetos[i].engenheiro->nome);
                }
                printf("--------------------------------------------------\n\n");
                break;
            }
            case 4: {
                if (quantEnge == 0) {
                    printf("\nNenhum engenheiro cadastrado\n\n");
                    break;
                }
                printf("\n---------- Engenheiros ----------");
                for (int i = 0; i < quantEnge; i++) {
                    printf("\nNome: %s, Formação: %s\n", engenheiros[i].nome, engenheiros[i].formacao); 
                }
                printf("---------------------------------\n\n");
                break;
            }
            case 5: {
                char nome[50];
                printf("Digite o nome do engenheiro: ");
                scanf(" %[^\n]", nome);
                Engenheiro *buscar = buscarEngenheiro(engenheiros, quantEnge, nome);
                if (buscar) {
                    printf("\n---------- Engenheiro ----------");
                    printf("\nNome: %s, Formação: %s\n", buscar->nome, buscar->formacao);
                    float total = totalContratos(projetos, quantProj, buscar);
                    printf("Total em contratos: R$ %.2f\n", total);
                    printf("--------------------------------\n\n");
                } 
                else 
                    printf("\nEngenheiro não encontrado.\n\n");
                break;
            }
            case 6: {
                printf("\n   [1] Sim  [2] Não \nDeseja salvar o arquivo? ");
                scanf("%d", &salvar);
                
                if (salvar == 1) {
                    
                    FILE *file = fopen("dados.txt", "w");
                    if (file == NULL) {
                        printf("Erro ao abrir arquivo\n");
                        break;
                    }
                
                    fprintf(file, "%d\n", quantEnge);
                    for (int i = 0; i < quantEnge; i++) {
                        fprintf(file, "%d %s %s\n", engenheiros[i].id, engenheiros[i].nome, engenheiros[i].formacao);
                    }
                    fprintf(file, "%d\n", quantProj);
                    for (int i = 0; i < quantProj; i++) {
                        fprintf(file, "%d %s %.2f %d\n", projetos[i].idProjeto, projetos[i].descricao, projetos[i].valor, projetos[i].engenheiro->id);
                    }
                
                    fclose(file);
                }
                break;
            }
        }
    } while (op != 6);

    free(engenheiros);
    free(projetos);
}