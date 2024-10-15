#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    float condTer, tempInt, tempBul, umidRel, convInt, convExt, tempOrv, C1, espeIso;
    
    printf("Digite o valor da condutividade termica (W/(m.K)): ");
    scanf("%f", &condTer);
    
    printf("Digite o valor da temperatura interna (°C): ");
    scanf("%f", &tempInt);
    
    printf("Digite o valor da temperatura de buldo seco (°C): ");
    scanf("%f", &tempBul);
    
    printf("Digite o valor da umidade relativa (%%): ");
    scanf("%f", &umidRel);
    
    printf("Digite o valor da convecção interna (W/(m².°C)): ");
    scanf("%f", &convInt);
    
    printf("Digite o valor da convecção externa (W/(m².°C)): ");
    scanf("%f", &convExt);
    
    tempOrv = (109.8 + tempBul) * pow((umidRel / 100), 0.1247) -109.8;
    C1 = (tempOrv - tempInt) / (tempBul - tempOrv);
    espeIso = condTer * (C1*(1/convInt) - (1/convExt)) * 1000;
    
    //printf("tempOrv: %.2f\n", tempOrv);
    //printf("C1: %.2f\n", C1);
    
    printf("Espessura do isolamento: %.2f mm", espeIso);
}