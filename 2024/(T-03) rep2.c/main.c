#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int estMonit, boa=0, ruim=0, moderada=0;
    float pm25, co2, totalPMBoa=0, totalCO2Boa=0, totalPMRuim=0, totalCO2Ruim=0, totalPMMode=0, totalCO2Mode=0;
    do{
        printf("Informe o n�mero de esta��es de monitoramento ambiental: ");
        scanf("%i", &estMonit);
        
        if (estMonit<=0)
            printf("\nValor inv�lido.\n\n");
    }while(estMonit<=0);
 
    for (int estacoes=1; estacoes<=estMonit; estacoes++){
        do{
            printf("\n------------ %i� Esta��o ------------", estacoes);
            printf("\nInforme o valor de PM2.5 (�g/m�): ");
            scanf("%f", &pm25);
            printf("Informe o valor de CO2 (ppm): ");
            scanf("%f", &co2);

            if (pm25==0 || co2==0)
                printf("\nZero n�o � aceito como valor de entrada.\nInforme novamente!!\n");
        } while (pm25==0 || co2==0);

        if (pm25 < 12 && co2 < 400){
            printf("Situa��o da esta��o: Boa!!\n");
            boa++;
            totalPMBoa += pm25;
            totalCO2Boa += co2;
        }
        else if (pm25 >= 35 || co2 >= 800){
            printf("Situa��o da esta��o: Ruim.\n");
            ruim++;
            totalPMRuim += pm25;
            totalCO2Ruim += co2;
        }
        else{
            printf("Situa��o da esta��o: Moderada!\n");
            moderada++;
            totalPMMode += pm25;
            totalCO2Mode += co2;
        }
    }
    printf("\n------------ Resultados ------------");
    if (boa > 0) {
        printf("\nEstacoes Boas: %d\n", boa);
        printf("Media PM2.5 (Boa): %.2f �g/m�\n", totalPMBoa / boa);
        printf("Media CO2 (Boa): %.2f ppm\n", totalCO2Boa / boa);
    }
    if (moderada > 0) {
        printf("\nEstacoes Moderadas: %d\n", moderada);
        printf("Media PM2.5 (Moderada): %.2f �g/m�\n", totalPMMode / moderada);
        printf("Media CO2 (Moderada): %.2f ppm\n", totalCO2Mode / moderada);
    }
    if (ruim > 0) {
        printf("\nEstacoes Ruins: %d\n", ruim);
        printf("Media PM2.5 (Ruim): %.2f �g/m�\n", totalPMRuim / ruim);
        printf("Media CO2 (Ruim): %.2f ppm\n", totalCO2Ruim / ruim);
    }
    printf("------------------------------------\n\n");
}