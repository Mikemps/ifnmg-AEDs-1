#include <stdio.h>
#include <locale.h>

float calcularIQA(float pm25, float co2) {
    return (pm25 / 10) + (co2 / 1000);
}

const char* categorizarIQA(float iqa) {
    if (iqa < 1) {
        return "Boa!!";
    } else if (iqa >= 1 && iqa < 2) {
        return "Moderada!";
    } else {
        return "Ruim.";
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    float pm25, co2, iqa;
    char op;
    do {
        printf("Informe o valor de PM2.5 (µg/m³): ");
        scanf("%f", &pm25);
        printf("Informe o valor de CO2 (ppm): ");
        scanf("%f", &co2);

        iqa = calcularIQA(pm25, co2);
        
        printf("\n------ Análise ------\n");
        printf("IQA: %.2f\n", iqa);
        printf("Categoria: %s\n", categorizarIQA(iqa));
        printf("---------------------\n\n");

        printf("Deseja realizar outra análise? (s/n): ");
        scanf(" %s", &op);
    } while (op == 's' || op == 'S');
}
