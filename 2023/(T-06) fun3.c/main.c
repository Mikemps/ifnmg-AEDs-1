#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Docente {
    int identificador;
    char nome[50];
    char areaAtuacao[50];
    char departamento[50];
};

struct Disciplina {
    int identificador;
    char nome[50];
    char ementa[100];
    struct Docente* docente;
    int carga_horaria;
};

int cargaHorariaTotal(struct Disciplina disciplinas[], int numDisciplinas, const char* nomePesquisa, int index) {
    if (index >= numDisciplinas)
        return 0;  
    int cargaHorariaDocente = 0;
    if (disciplinas[index].docente != NULL && strcmp(nomePesquisa, disciplinas[index].docente->nome) == 0) 
        cargaHorariaDocente = disciplinas[index].carga_horaria;
    return cargaHorariaDocente + cargaHorariaTotal(disciplinas, numDisciplinas, nomePesquisa, index + 1);  
}

struct Docente* pesquisa(struct Docente docentes[], int numDocentes, const char* nome, int index) {
    if (index >= numDocentes) 
        return NULL; 
    if (strcmp(docentes[index].nome, nome) == 0) 
        return &docentes[index]; 
    return pesquisa(docentes, numDocentes, nome, index + 1);  
}

int main() 
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct Disciplina disciplinas[100];
    struct Docente docentes[100];
    int numDisciplinas = 0, numDocentes = 0;

    FILE *file = fopen("arquivo.txt", "r");
    if (file == NULL)
        printf("Nenhum arquivo encontrado. Cadastre novas disciplinas e docentes.\n");
    else {
        char linha[256];
        while (fgets(linha, sizeof(linha), file)) {
            linha[strcspn(linha, "\n")] = 0;

            char* token = strtok(linha, ",");
            if (token != NULL) {
                if (strcmp(token, "docente") == 0) {
                    struct Docente* docente = &docentes[numDocentes];
                    docente->identificador = atoi(strtok(NULL, ","));
                    strcpy(docente->nome, strtok(NULL, ","));
                    strcpy(docente->areaAtuacao, strtok(NULL, ","));
                    strcpy(docente->departamento, strtok(NULL, ","));
                    numDocentes++;
                } 
                else if (strcmp(token, "disciplina") == 0) {
                    struct Disciplina* disciplina = &disciplinas[numDisciplinas];
                    disciplina->identificador = atoi(strtok(NULL, ","));
                    strcpy(disciplina->nome, strtok(NULL, ","));
                    strcpy(disciplina->ementa, strtok(NULL, ","));
                    char* nomeDocente = strtok(NULL, ",");
                    disciplina->carga_horaria = atoi(strtok(NULL, ","));
                    
                    struct Docente* docente_responsavel = pesquisa(docentes, numDocentes, nomeDocente, 0);
                    if (docente_responsavel != NULL) {
                        disciplina->docente = docente_responsavel;
                        numDisciplinas++;
                    } 
                    else 
                        printf("Erro: Docente '%s' não encontrado para a disciplina '%s'.\n", nomeDocente, disciplina->nome);
                }
            }
        }
        fclose(file);
    }

    while (1) {
        int op;
        printf("[1] Inserir nova disciplina\n");
        printf("[2] Inserir novo docente\n");
        printf("[3] Exibir lista de disciplinas\n");
        printf("[4] Exibir lista de docentes\n");
        printf("[5] Pesquisar docente pelo nome\n");
        printf("[6] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        getchar();  

        if (op == 1) {
            if (numDocentes == 0) {
                printf("\nErro: Nenhum docente cadastrado.\n\n");
                continue;
            }

            printf("Docentes disponíveis:\n");
            for (int i = 0; i < numDocentes; i++) {
                printf("%d. %s\n", i + 1, docentes[i].nome);
            }

            int escolhaDocente;
            printf("Escolha o docente responsável pela disciplina: ");
            scanf("%d", &escolhaDocente);
            getchar();

            if (escolhaDocente > 0 && escolhaDocente <= numDocentes) {
                struct Disciplina* disciplina = &disciplinas[numDisciplinas];
                disciplina->identificador = numDisciplinas + 1;  
                printf("Nome da disciplina: ");
                fgets(disciplina->nome, sizeof(disciplina->nome), stdin);
                strtok(disciplina->nome, "\n"); 

                printf("Ementa da disciplina: ");
                fgets(disciplina->ementa, sizeof(disciplina->ementa), stdin);
                strtok(disciplina->ementa, "\n"); 

                printf("Carga horária da disciplina: ");
                scanf("%d", &disciplina->carga_horaria);
                disciplina->docente = &docentes[escolhaDocente - 1];
                numDisciplinas++;
            } else {
                printf("Escolha de docente inválida.\n");
            }
        } 
        else if (op == 2) {
            struct Docente* docente = &docentes[numDocentes];
            docente->identificador = numDocentes + 1;
            printf("Nome do docente: ");
            fgets(docente->nome, sizeof(docente->nome), stdin);
            docente->nome[strcspn(docente->nome, "\n")] = 0;  

            printf("Área de atuação do docente: ");
            fgets(docente->areaAtuacao, sizeof(docente->areaAtuacao), stdin);
            docente->areaAtuacao[strcspn(docente->areaAtuacao, "\n")] = 0;  

            printf("Departamento do docente: ");
            fgets(docente->departamento, sizeof(docente->departamento), stdin);
            docente->departamento[strcspn(docente->departamento, "\n")] = 0; 

            numDocentes++;
        } 
        else if (op == 3) {
            printf("\n---------- Disciplinas ----------\n");
            for (int i = 0; i < numDisciplinas; i++) {
                struct Disciplina* disciplina = &disciplinas[i];
                printf("Nome: %s\n", disciplina->nome);
                printf("Ementa: %s\n", disciplina->ementa);
                printf("Docente: %s\n", disciplina->docente->nome);
                printf("Carga horária: %d Horas\n", disciplina->carga_horaria);
                printf("--------------------------------\n");
            }
        } 
        else if (op == 4) {
            printf("\n---------- Docentes ----------\n");
            for (int i = 0; i < numDocentes; i++) {
                struct Docente* docente = &docentes[i];
                printf("Nome: %s\n", docente->nome);
                printf("Área de atuação: %s\n", docente->areaAtuacao);
                printf("Departamento: %s\n", docente->departamento);
                printf("------------------------------\n");
            }
        } 
        else if (op == 5) {
            char nomePesquisa[50];
            printf("Digite o nome do docente: ");
            fgets(nomePesquisa, sizeof(nomePesquisa), stdin);
            strtok(nomePesquisa, "\n"); 
            
            struct Docente* docenteEncontrado = pesquisa(docentes, numDocentes, nomePesquisa, 0);
            if (docenteEncontrado) {
                printf("\n-------------------------------\n");
                printf("Docente: %s\n", docenteEncontrado->nome);
                printf("Área de atuação: %s\n", docenteEncontrado->areaAtuacao);
                printf("Departamento: %s\n", docenteEncontrado->departamento);
                printf("Carga horária total: %d Horas\n", cargaHorariaTotal(disciplinas, numDisciplinas, docenteEncontrado->nome, 0));
                printf("-------------------------------\n\n");
            } 
            else 
                printf("\nDocente não encontrado.\n");
            
        } else if (op == 6) {
            char salvar;
            printf("Deseja salvar as alterações? (S/N): ");
            scanf(" %c", &salvar);
            getchar(); 
            
            if (salvar == 'S' || salvar == 's') {
                FILE *file = fopen("arquivo.txt", "w");
                if (file == NULL) {
                    printf("Erro ao salvar os dados.\n");
                    break;
                }
                for (int i = 0; i < numDocentes; i++) {
                    struct Docente* docente = &docentes[i];
                    fprintf(file, "docente,%d,%s,%s,%s\n", 
                            docente->identificador, 
                            docente->nome, 
                            docente->areaAtuacao, 
                            docente->departamento);
                }
                for (int i = 0; i < numDisciplinas; i++) {
                    struct Disciplina* disciplina = &disciplinas[i];
                    fprintf(file, "disciplina,%d,%s,%s,%s,%d\n", 
                            disciplina->identificador, 
                            disciplina->nome, 
                            disciplina->ementa, 
                            disciplina->docente->nome, 
                            disciplina->carga_horaria);
                }
                fclose(file);
                printf("\nDados salvos com sucesso.\n\n");
            }
            break;
        } 
        else 
            printf("\nOpção inválida. Tente novamente.\n\n");
    }
}