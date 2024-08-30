while True:
    op = float(input("[1] Calcular taxa de transmissão (Mbps)\
                    \n[2] Calcular o tempo de transmissão (min)\
                    \n[3] Calcular dados transmitidos (GB)\
                    \n[4] Sair\
                    \nOpção: "))
    
    if op==1:
        tamArq = float(input("Informe o tamanho do arquivo (GB): "))
        tempo = float(input("Informe o tempo de transmissão (min): "))
        taxa = (tamArq * 1024 * 8) / (tempo * 60)
        print(f"\nA taxa de transmissao é: {taxa:.2f} Mbps\n")

    elif op==2:
        taxa = float(input("Informe a taxa de transmissão (Mbps): "))
        tamArq = float(input("Informe o tamanho do arquivo (GB): "))
        tempo = (tamArq * 8 * 1024) / (taxa * 60)
        print(f"\nO tempo de transmissao é: {tempo:.2f} (min)\n")

    elif(op==3):
        taxa = float(input("Informe a taxa de transmissão (Mbps): "))
        tempo = float(input("Informe o tempo de transmissão (min): "))
        dados = (taxa * 60 * tempo) / (8 * 1024)
        print(f"\nA quantidade de dados transmitidos é: {dados:.2f} (GB)\n")

    elif(op==4):
        print("\nPrograma encerado!!\n")
        break

    else:
        print("\nOpção invalida. Escolha novamente.\n")