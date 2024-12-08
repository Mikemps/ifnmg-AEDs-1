import math

idade = float(input("Digite a idade do frango (d): "))
pesoAnimal = float(input("Digite o peso vivo do frango (g): "))

pesoVivo = 20+200/(0.1+4*math.exp(1-0.4*idade))
    
if pesoAnimal < pesoVivo*0.8:
    supA = 10*math.log(5+idade)+10
    print("Peso do frango abaixo do esperado, "
    f"{supA:.2f}g do suplemento A devem ser ministrados")
    
elif pesoAnimal > pesoVivo*1.2:
    supB = 0.45*idade+5
    print("Peso do frango acima do esperado, "
    f"{supB:.2f}g do suplemento B devem ser ministrados")
    
else:
    print("O frango esta saudável!")