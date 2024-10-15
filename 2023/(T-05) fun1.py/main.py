def texto(Maquina):
    print("\n"+47*'-')
    print(f"Número de registro: {Maquina['registro']}")
    print(f"Tipo: {Maquina['tipo']}")
    print(f"Modelo: {Maquina['modelo']}")
    print(f"Fabricante: {Maquina['fabricante']}")
    print(f"Aluguel diário: R${Maquina['diaAluguel']:.2f}")

def calculoAluguel(Maquina, dias):
    return dias * Maquina['diaAluguel']

def preencheMaquina(tam):
    maquinas = []
    for i in range(tam):
        Maquina = {}
        print("\n"+47*'-')
        Maquina['registro'] = int(input("Digite o número de registro: "))
        Maquina['tipo'] = input("Digite o tipo da máquina: ")
        Maquina['modelo'] = input("Digite o modelo da máquina: ")
        Maquina['fabricante'] = input("Digite o fabricante: ")
        Maquina['diaAluguel'] = float(input("Digite o valor diário do aluguel: R$"))
        
        maquinas.append(Maquina)
    return maquinas

def listaMaquinario(maquinas, tipo=''):
    contando = 0
    for Maquina in maquinas:
        if not tipo or Maquina['tipo'] == tipo:
            texto(Maquina)
            contando += 1
    return contando

def busca(maquinas, registro):
    for i, Maquina in enumerate(maquinas):
        if registro == Maquina['registro']:
            return i
    return -1

while True:
    quantMaquina = int(input("Digite a quantidade de máquinas: "))
    maquinas = preencheMaquina(quantMaquina)
    
    while True:
        print("\n"+47*'-')
        print("[1] - Entrar com um conjunto novo de máquinas."
              "\n[2] - Listar maquinas por tipo. "
              "\n[3] - Pesquisar maquina por registro."
              "\n[4] - Sair\n"+47*'-')
        op = int(input("Escolha a sua opção: "))
        
        if op == 1:
            break
        elif op == 2:
            tipo = input("Digite o tipo de máquina: ")
            numMaquina = listaMaquinario(maquinas, tipo)
            print(f"\n{numMaquina} máquina(s) encontrada(s).")
        elif op == 3:
            registro = int(input("Digite o registro da máquina: "))
            pesquisa = busca(maquinas, registro)
            if pesquisa == -1:
                print("Não encontrado!")
            else:
                texto(maquinas[pesquisa])
                dias = int(input("\nDigite a quantidade de dias: "))
                aluguel = calculoAluguel(maquinas[pesquisa], dias)
                print(f"Valor total do contrato de aluguel, R$ {aluguel:.2f}")
        elif op == 4:
            print("Programa encerrado!")
            exit(0)
        
        else:
            print("Opção inexistente!")