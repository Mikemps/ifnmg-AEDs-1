#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    float op, taxa, tempo, dados, tamArq;

    do{
        printf("[1] Calcular taxa de transmiss?o (Mbps)\
        \n[2] Calcular o tempo de transmiss�o (min)\
        \n[3] Calcular dados transmitidos (GB)\
        \n[4] Sair\
        \nOp��o: ");
        scanf("%f", &op);

        if (op==1)
        {
            printf("Informe o tamanho do arquivo (GB): ");
            scanf("%f", &tamArq);
            printf("Informe o tempo de transmiss�o (min): ");
            scanf("%f", &tempo);

            taxa = (tamArq * 1024 * 8) / (tempo * 60);
            printf("\nA taxa de transmiss�o �: %.2f Mbps\n\n", taxa);
        }
        else if (op==2)
        {
            printf("Informe a taxa de transmiss�o (Mbps): ");
            scanf("%f", &taxa);
            printf("Informe o tamanho do arquivo (GB): ");
            scanf("%f", &tamArq);

            tempo = (tamArq * 8 * 1024) / (taxa * 60);
            printf("\nO tempo de transmiss�o �: %.2f (min)\n\n", tempo);
        }
        else if (op==3)
        {
            printf("Informe a taxa de transmiss�o (Mbps): ");
            scanf("%f", &taxa);
            printf("Informe o tempo de transmiss�o (min): ");
            scanf("%f", &tempo);

            dados = (taxa * 60 * tempo) / (8 * 1024);
            printf("\nA quantidade de dados transmitidos �: %.2f (GB)\n\n", dados);
        }
        else if (op==4)
            printf("\nPrograma encerado!!\n\n");
        else
            printf("\nOp��o inv�lida. Escolha novamente.\n\n");
    } while (op != 4);
}