def calcular_iqa(pm25, co2):
    return (pm25 / 10.0) + (co2 / 1000.0)

def categorizar_iqa(iqa):
    if iqa < 1.0:
        return "Boa"
    elif 1.0 <= iqa < 2.0:
        return "Moderada"
    else:
        return "Ruim"

#def main(): <-----
while True:
    
    pm25 = float(input("Entre com o valor de PM2.5 (µg/m³): "))
    co2 = float(input("Entre com o valor de CO2 (ppm): "))
    
    iqa = calcular_iqa(pm25, co2)
    print(f"IQA: {iqa:.2f}")
    print(f"Categoria: {categorizar_iqa(iqa)}")
    
    opcao = input("Deseja repetir o codigo? (s/n): ")
    if opcao != 's' and opcao != 'S':
        break
    '''
    Aqui vc precisa colocar uma perguta para o usuario com as 
    opções de finalisar o programa ou repetir e depois um if 
    condicional com um "break" para finalizar o codigo

    EX:
    
    
    '''  
#if _name_ == "_main_": <------
#    main()     <-------