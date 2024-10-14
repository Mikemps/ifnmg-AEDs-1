def calcularIQA(pm25, co2):
    return (pm25 / 10) + (co2 / 1000)

def categorizarIQA(iqa):
    if iqa<1:
        return "Boa!!"
    elif iqa>=1 and iqa<2:
        return "Moderada!"
    else:
        return "Ruim."

while True:
    pm25 = float(input("Informe o valor de PM2.5 (µg/m³): "))
    co2 = float(input("Informe o valor de CO2 (ppm): "))

    iqa = calcularIQA(pm25, co2)

    print("\n------ Análise ------")
    print(f"IQA: {iqa:.2f}")
    print(f"Categoria: {categorizarIQA(iqa)}")
    print("---------------------\n")

    op = input("Deseja realizar outra análise? (s/n): ")
    if op!='s' and op!='S':
        break
    