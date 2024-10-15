percAba = 0 
percAci = 0
percIde = 0
quant_1 = 0        
quant_2 = 0
quant_3 = 0

while True:
    totGatos = int(input("Digite a quantidade de gatos: "))
    if totGatos<=0:
        print("Valor invalido!\nQuantidade mínima = 1\n")
    else:
        break

for gatos in range(1, totGatos+1):
    
    while True:
        print(19*'-', f"{gatos}º gato", 19*'-')
        circTor = float(input("Circunferência torácica (cm): "))
        distCal = float(input("Distância entre o calcâneo e a patela (cm): "))
        
        percFel = (((circTor/0.7067)-distCal)/0.9156)-distCal
        
        if circTor<=0 or distCal<=0 or percFel<=0:
            print("\nDados inválidos, informe-os novamente!\n")
        else:
            break

    if(percFel<20):
        print(f"Gato {gatos} abaixo do peso")
        print(f"P.G.C.F: {percFel:.2f}%\n")
        percAba += percFel
        quant_1 += 1
    
    elif(percFel>=27):
        print(f"Gato {gatos} acima do peso")
        print(f"P.G.C.F: {percFel:.2f}%\n")
        percAci += percFel
        quant_2 += 1
    
    else:
        print(f"Gato {gatos} com peso ideal!")
        print(f"P.G.C.F: {percFel:.2f}%\n")
        percIde += percFel
        quant_3 += 1

print(18*'-', "RELATÓRIO", 18*'-')

if (percAba>0):
    print(f"{quant_1} gato(s) abaixo do peso"
    f"\nPercentual médio de gordura é {(percAba/quant_1):.2f}%\n"+47*'-')
else:
    print("Não há gatos abaixo do peso\n"+47*'-')

if (percAci>0):
    print(f"{quant_2} gato(s) acima do peso"
    f"\nPercentual médio de gordura é {(percAci/quant_2):.2f}%\n"+47*'-')
else:
    print("Não há gatos acima do peso\n"+47*'-')

if (percIde>0):
    print(f"{quant_3} gato(s) com peso ideal!"
    f"\nPercentual médio de gordura é {(percIde/quant_3):.2f}%\n"+47*'-')
else:
    print("Não há gatos com peso ideal\n"+47*'-')
