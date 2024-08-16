desVol = float(input("Informe o deslocamento volumetrico(cm³): "))
rotMin = float(input("Informe a quantidade de rotações por minuto: "))
vasHid = desVol*rotMin
print(f"A vasão da bomba hidráulica é de: {vasHid:.2f}(cm³/min)")

volMax = float(input("Infrome o volume máximo do reservatório(L): "))
temNec = (volMax*1000)/vasHid
print(f"O tempo necessario para encher o reservatório é de: {temNec:.2f}(min)")