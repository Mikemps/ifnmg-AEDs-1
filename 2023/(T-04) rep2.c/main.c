#include <stdio.h>
#include <math.h>

int main()
{
    int opcao;
    float vazaoMa, compTub, aumeMax, tranMax=0, tempAmb, tempFlu, resiTer=0, diamExt, condTer, espeIso=0;
    
    while(1){
        printf("------------- Calculadora de Isolamento -------------");
        if(tranMax==0)
            printf("\n[1]Transferencia de calor máxima admissível");
        if(tranMax!=0)
            printf("\n[1]Transferencia de calor máxima admissível: %.2f", tranMax);
        if(tranMax!=0 && resiTer==0)
            printf("\n[2]Resistência térmica necessária");
        if(resiTer!=0)
            printf("\n[2]Resistência térmica necessária: %.2f", resiTer);
        if(resiTer!=0 && espeIso==0)
            printf("\n[3]Espessura recomendada para o isolamento");
        if(espeIso!=0)
            printf("\n[3]Espessura recomendada para o isolamento: %.4f", espeIso);
        printf("\n[4]Sair\
        \n-----------------------------------------------------");
        printf("\nOpção: ");
        scanf("%i", &opcao);
        
        if(opcao==4){
            printf("Calculadora encerrada!");
            break;
        }
        else if(opcao==1){
            printf("Digite o valor da vazão massiva(kg/s): ");
            scanf("%f", &vazaoMa);
            printf("Digite o comprimento da tubulação: ");
            scanf("%f", &compTub);
            printf("Digite o aumento de temperatura máximo admissível: ");
            scanf("%f", &aumeMax);
            tranMax = vazaoMa*4190*aumeMax/compTub;
            printf("\nTransferencia de calor máxima admissivel: %.2f\n\n", tranMax);
            resiTer = 0;
            espeIso = 0;
        }
        else if(opcao==2 && tranMax!=0){
            printf("Digite a temperatura do ar ambiente: ");
            scanf("%f", &tempAmb);
            printf("Digite a temperatura do fluido no interior: ");
            scanf("%f", &tempFlu);
            resiTer = (tempAmb-tempFlu)/tranMax;
            printf("\nResistência térmica necessária: %.2f\n\n", resiTer);
            espeIso = 0;
        }
        else if(opcao==3 && resiTer!=0){
            printf("Digite o diametro externo da tubulação: ");
            scanf("%f", &diamExt);
            printf("Digite a condutividade termica: ");
            scanf("%f", &condTer);
            espeIso = diamExt/2*pow(2.7183 ,(2*M_PI*condTer*resiTer)- 1);
            printf("\nEspessura recomendada para o isolamento: %.4f\n\n", espeIso);
        }
        else{
            printf("Escolha invalida!\n\n");
        }
    }
}
