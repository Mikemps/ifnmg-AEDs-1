condTer = float(input("Digite o valor da condutividade termica (W/(m.K)): "))
tempInt = float(input("Digite o valor da temperatura interna (°C): "))
tempBul = float(input("Digite o valor da temperatura de buldo seco (°C): "))
umidRel = float(input("Digite o valor da umidade relativa (%): "))
convInt = float(input("Digite o valor da convecção interna (W/(m².°C)): "))
convExt = float(input("Digite o valor da convecção externa (W/(m².°C)): "))

tempOrv =  (109.8 + tempBul) * (umidRel / 100)**0.1247 -109.8
C1 = (tempOrv - tempInt) / (tempBul - tempOrv)
espeIso = condTer * (C1*(1/convInt) - (1/convExt)) * 1000

#print(f"tempOrv: {tempOrv:.2f}")
#print(f"C1: {C1:.2f}")

print(f"Espessura do isolamento: {espeIso:.2f}", "mm")
