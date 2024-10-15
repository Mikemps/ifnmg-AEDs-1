tranMax = 0
resiTer = 0
espeIso = 0
while True: 
    print("------------- Calculadora de Isolamento -------------");
    if tranMax==0:
        print("[1]Transferencia de calor máxima admissível")
    if tranMax!=0:
        print(f"[1]Transferencia de calor máxima admissível: {tranMax:.2f}")
    if tranMax!=0 and resiTer==0:
        print("[2]Resistência térmica necessária")
    if resiTer!=0:
        print(f"[2]Resistência térmica necessária: {resiTer:.2f}")
    if resiTer!=0 and espeIso==0:
        print("[3]Espessura recomendada para o isolamento")
    if espeIso!=0:
        print(f"[3]Espessura recomendada para o isolamento: {espeIso:.4f}")
    print("[4]Sair\n"+53*'-')
    opcao = int(input("Opção: "))
    
    if opcao==4: 
        print("Calculadora encerrada!")
        break
    elif opcao==1:
        vazaoMa = float(input("Digite o valor da vazão massiva(kg/s): "))
        compTub = float(input("Digite o comprimento da tubulação: "))
        aumeMax = float(input("Digite o aumento de temperatura máximo admissível: "))
        tranMax = vazaoMa*4190*aumeMax/compTub
        print(f"\nTransferencia de calor máxima admissivel: {tranMax:.2f}\n")
        resiTer = 0
        espeIso = 0
    elif opcao==2 and tranMax!=0:
        tempAmb = float(input("Digite a temperatura do ar ambiente: "))
        tempFlu = float(input("Digite a temperatura do fluido no interior: "))
        resiTer = (tempAmb-tempFlu)/tranMax
        print(f"\nResistência térmica necessária: {resiTer:.2f}\n")
        espeIso = 0
    elif opcao==3 and resiTer!=0:
        import math
        diamExt = float(input("Digite o diametro externo da tubulação: "))
        condTer = float(input("Digite a condutividade termica: "))
        espeIso = diamExt/2*(2.7183**(2*math.pi*condTer*resiTer)- 1)
        print(f"\nEspessura recomendada para o isolamento: {espeIso:.4f}\n")
    else:
        print("Escolha invalida!\n")