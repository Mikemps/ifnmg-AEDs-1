#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    float idade, pesoAnimal, pesoVivo, supA, supB;
    
    printf("Digite a idade do frango (d): ");
    scanf("%f", &idade);
    
    printf("Digite o peso vivo do frango (g): ");
    scanf("%f", &pesoAnimal);
    
    pesoVivo = 20+200/(0.1+4*exp(1-0.4*idade));
    
    if (pesoAnimal < pesoVivo*0.8) 
    {
        supA = 10*log(5+idade)+10;
        printf("Peso do frango abaixo do esperado, "
        "%.2fg do suplemento A devem ser ministrados", supA);
    } 
    else if (pesoAnimal > pesoVivo*1.2) 
    {
        supB = 0.45*idade+5;
        printf("Peso do frango acima do esperado, "
        "%.2fg do suplemento B devem ser ministrados", supB);
    }
    else {
        printf("O frango esta saudavel!");
    }
}