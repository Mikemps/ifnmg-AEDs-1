#include <stdio.h>     

int main()    //Micael Pereira, Mateus Martins 
{   
    int totGatos, gatos, quant_1=0, quant_2=0, quant_3=0;
    float circTor, distCal, percFel, mediAba=0, mediAci=0, medIdea=0;

    do{
        printf("Digite a quantidade de gatos: ");
        scanf("%i", &totGatos);
        
        if (totGatos<=0){
            printf("Valor invalido!\nQuantidade mínima = 1\n\n");
        }
    }while(totGatos<=0);
    
    for (gatos=1; gatos<=totGatos; gatos++)
    {
        do{
            printf("------------------- %iº gato -------------------\n", gatos);
            printf("Circunferência torácica (cm): ");
            scanf("%f", &circTor);
            
            printf("Distância entre o calcâneo e a patela (cm): ");
            scanf("%f", &distCal);
            
            percFel = (((circTor/0.7067)-distCal)/0.9156)-distCal;
            
            if(circTor<=0 || distCal<=0 || percFel<=0){
                printf("\nDados inválidos, informe-os novamente!\n\n");
            }
        }while(circTor<=0 || distCal<=0 || percFel<=0);
        
        if(percFel<20){
            printf("Gato %i abaixo do peso\n", gatos);
            printf("P.G.C.F: %.2f\n\n", percFel);
            mediAba += percFel;
            quant_1 += 1;
        }
        else if(percFel>=27){
            printf("Gato %i acima do peso\n", gatos);
            printf("P.G.C.F: %.2f\n\n", percFel);
            mediAci += percFel;
            quant_2 += 1;
        }
        else{
            printf("Gato %i com peso ideal!\n", gatos);
            printf("P.G.C.F: %.2f\n\n", percFel);
            medIdea += percFel;
            quant_3 += 1;
        }
    }
    printf("------------------ RELATÓRIO ------------------");
    if (mediAba>0){
        printf("\n%i gato(s) abaixo do peso\
        \nPercentual médio de gordura é %.2f\
        \n-----------------------------------------------"
        , quant_1, (mediAba/quant_1));
    }
    else{
        printf("\nNão a gatos abaixo do peso\
        \n-----------------------------------------------");
    }
    if (mediAci>0){
        printf("\n%i gato(s) acima do peso\
        \nPercentual médio de gordura é %.2f\
        \n-----------------------------------------------"
        , quant_2, (mediAci/quant_2));
    }
    else{
        printf("\nNão a gatos acima do peso\
        \n-----------------------------------------------");
    }
    if (medIdea>0){
        printf("\n%i gato(s) com peso ideal!\
        \nPercentual médio de gordura é %.2f\
        \n-----------------------------------------------"
        , quant_3, (medIdea/quant_3));
    }
    else{
        printf("\nNão a gatos com peso ideal!\
        \n-----------------------------------------------");
    }
}
