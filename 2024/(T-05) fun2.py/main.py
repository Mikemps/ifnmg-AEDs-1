def calcular_pgcf(gato):
    return (((gato['CT'] / 0.7067) - gato['DCP']) / 0.9156) - gato['DCP']

def classificar_pgcf(pgcf):
    if pgcf < 20:
        return "Abaixo do peso"
    elif 20 <= pgcf < 27:
        return "Peso ideal"
    else:
        return "Acima do peso"

def preencher_gatos(num_gatos):
    gatos = []
    for i in range(num_gatos):
        print(f"\n------------------ Gato {i+1} ------------------")
        nome = input("Nome do gato: ")
        endereco = input("Endereço: ")
        ct = float(input("Circunferência Torácica (cm): "))
        dcp = float(input("Distância Calcâneo-Patela (cm): "))
        gatos.append({'nome': nome, 'endereco': endereco, 'CT': ct, 'DCP': dcp})
    return gatos

def exibir_gato(gato):
    print("\n--------------------------------------------")
    print(f"Nome: {gato['nome']}")
    print(f"Endereço: {gato['endereco']}")
    print(f"Circunferência Torácica: {gato['CT']:.2f} cm")
    print(f"Distância Calcâneo-Patela: {gato['DCP']:.2f} cm")
    pgcf = calcular_pgcf(gato)
    print(f"PGCF: {pgcf:.2f}")
    print(f"Classificação: {classificar_pgcf(pgcf)}")
    print("--------------------------------------------")


def encontrar_gato_por_nome(gatos, nome):
    if len(gatos) == 0:
        return -1
    if gatos[0]['nome'] == nome:
        return 0
    resultado = encontrar_gato_por_nome(gatos[1:], nome)
    if resultado == -1:
        return -1 
    else:
        return resultado + 1

gatos = []
while True:
    print("\n------------------- Menu -------------------")
    print("[1] Inserir novo conjunto de gatos")
    print("[2] Buscar e exibir dados de gatos por nome")
    print("[3] Finalizar")
    opcao = int(input("Escolha uma opção: "))

    if opcao == 1:
        num_gatos = int(input("Quantos gatos deseja cadastrar? "))
        gatos = preencher_gatos(num_gatos)
    elif opcao == 2 and gatos:
        nome_buscado = input("Informe o nome do gato que deseja buscar: ")
        if encontrar_gato_por_nome(gatos, nome_buscado) != -1:
            exibir_gato(gatos[encontrar_gato_por_nome(gatos, nome_buscado)])
        else:
            print("\nGato não encontrado.")
    elif opcao == 3:
        print("\nPrograma encerrado!!\n")
        break
    else:
        print("\nOpção inválida. Escolha novamente.")