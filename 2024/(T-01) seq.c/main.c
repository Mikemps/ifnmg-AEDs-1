#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    float desVol, rotMin, vasHid, volMax, temNec;

    printf("Informe o deslocamento volumetrico(cm³): ");
    scanf("%f", &desVol);

    printf("Informe a quantidade de rotações por minuto: ");
    scanf("%f", &rotMin);

    vasHid = desVol*rotMin;
    printf("A vasão da bomba hidráulica é de: %.2f(cm³/min)", vasHid);

    printf("\n\nInforme o volume máximo do reservatório(L): ");
    scanf("%f", &volMax);

    temNec = (volMax*1000)/vasHid;
    printf("O tempo necessario para encher o reservatório é de: %.2f(min)", temNec);
}