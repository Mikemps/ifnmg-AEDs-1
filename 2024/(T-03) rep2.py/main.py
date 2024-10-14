boa=0
ruim=0
moderada=0
totalPMBoa=0
totalCO2Boa=0 
totalPMRuim=0
totalCO2Ruim=0
totalPMMode=0
totalCO2Mode=0

while True:    
    estMonit = int(input("Informe o número de estações de monitoramento ambiental: "))
    
    if (estMonit<=0):
        print("\nValor inválido.\n")
    else:
        break

for estacoes in range (1, estMonit+1):
    while True:
        print(f"\n------------ {estacoes}° Estação ------------")
        pm25 = float(input("Informe o valor de PM2.5 (µg/m³): "))
        co2 = float(input("Informe o valor de CO2 (ppm): "))

        if (pm25==0 or co2==0):
            print("\nZero não é aceito como valor de entrada.\nInforme novamente!!\n")
        else:
            break

    if (pm25 < 12 and co2 < 400):
        print("Situação da estação: Boa!!")
        boa += 1
        totalPMBoa += pm25
        totalCO2Boa += co2
    
    elif (pm25 >= 35 or co2 >= 800):
        print("Situação da estação: Ruim.")
        ruim += 1
        totalPMRuim += pm25
        totalCO2Ruim += co2
    
    else:
        print("Situação da estação: Moderada!")
        moderada += 1
        totalPMMode += pm25
        totalCO2Mode += co2

print("\n------------ Resultados ------------")
if (boa > 0):
    print(f"Estacoes Boas: {boa}")
    print(f"Media PM2.5 (Boa): {totalPMBoa / boa:.2f} µg/m³")
    print(f"Media CO2 (Boa): {totalCO2Boa / boa:.2f} ppm")
    print("------------------------------------")
if (moderada > 0):
    print(f"Estacoes Moderadas: {moderada}")
    print(f"Media PM2.5 (Moderada): {totalPMMode / moderada:.2f} µg/m³")
    print(f"Media CO2 (Moderada): {totalCO2Mode / moderada:.2f} ppm")
    print("------------------------------------")
if (ruim > 0):
    print(f"Estacoes Ruins: {ruim}")
    print(f"Media PM2.5 (Ruim): {totalPMRuim / ruim:.2f} µg/m³")
    print(f"Media CO2 (Ruim): {totalCO2Ruim / ruim:.2f} ppm")
    print("------------------------------------\n")
