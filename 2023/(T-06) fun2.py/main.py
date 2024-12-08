def cargaHorariaTotal(disciplinas, nomePesquisa, index=0):
    if index >= len(disciplinas):  
        return 0
    cargaHorariaDocente = 0
    if disciplinas[index]['docente'] is not None and nomePesquisa == disciplinas[index]['docente']['nome']:
        cargaHorariaDocente = disciplinas[index]['carga_horaria']
    return cargaHorariaDocente + cargaHorariaTotal(disciplinas, nomePesquisa, index + 1)  


def pesquisa(docentes, nome, index=0):
    if index >= len(docentes):  
        return None
    if docentes[index]['nome'] == nome:
        return docentes[index]  
    return pesquisa(docentes, nome, index + 1)  


disciplinas = []
docentes = []

try:
    with open('arquivo.txt', 'r') as file:
        linhas = file.readlines()

        for linha in linhas:
            dados = linha.strip().split(',')
            if len(dados) == 4:  
                identificador, nomeDocente, areaAtuacao, departamento = dados
                docente = {
                    'identificador': int(identificador),
                    'nome': nomeDocente,
                    'areaAtuacao': areaAtuacao,
                    'departamento': departamento
                }
                docentes.append(docente)

        for linha in linhas:
            dados = linha.strip().split(',')
            if len(dados) == 5: 
                identificador, nome, ementa, nomeDocente, cargaHoraria = dados
                docente_responsavel = pesquisa(docentes, nomeDocente)  
                if docente_responsavel:  
                    disciplina = {
                        'identificador': int(identificador),
                        'nome': nome,
                        'ementa': ementa, 
                        'docente': docente_responsavel, 
                        'carga_horaria': int(cargaHoraria)
                    }
                    disciplinas.append(disciplina)
                else:
                    print(f"Erro: Docente '{nomeDocente}' não encontrado para a disciplina '{nome}'.")
except FileNotFoundError:
    print("Nenhum arquivo encontrado. Cadastre novas disciplinas e docentes.")                    
except Exception as e:
    print(f"Erro: {e}")

while True:
    print("[1] Inserir nova disciplina")
    print("[2] Inserir novo docente")
    print("[3] Exibir lista de disciplinas")
    print("[4] Exibir lista de docentes")
    print("[5] Pesquisar docente pelo nome")
    print("[6] Sair")

    op = input("Escolha uma opção: ")

    if op == '1':
        if len(docentes) == 0:
            print("\nErro: Nenhum docente cadastrado.\n")
            continue

        print("Docentes disponíveis:")
        for i, docente in enumerate(docentes):
            print(f"{i + 1}. {docente['nome']}")

        escolhaDocente = int(input("Escolha o docente responsável pela disciplina: ")) - 1
        if 0 <= escolhaDocente < len(docentes):
            nomeDisciplina = input("Nome da disciplina: ")
            ementa = input("Ementa da disciplina: ")
            cargaHoraria = int(input("Carga horária da disciplina: "))
            identificador = len(disciplinas) + 1  

            disciplina = {
                'identificador': identificador,
                'nome': nomeDisciplina,
                'ementa': ementa,
                'docente': docentes[escolhaDocente], 
                'carga_horaria': cargaHoraria
            }
            disciplinas.append(disciplina)
        else:
            print("Escolha de docente inválida.")

    elif op == '2':
        nomeDocente = input("Nome do docente: ")
        areaAtuacao = input("Área de atuação do docente: ")
        departamento = input("Departamento do docente: ")

        identificador = len(docentes) + 1 
        docente = {
            'identificador': identificador,
            'nome': nomeDocente,
            'areaAtuacao': areaAtuacao,
            'departamento': departamento
        }
        docentes.append(docente)

    elif op == '3':
        print("\n---------- Disciplinas ----------")
        for disciplina in disciplinas:
            print(f"Nome: {disciplina['nome']}")
            print(f"Ementa: {disciplina['ementa']}")
            print(f"Docente: {disciplina['docente']['nome']}") 
            print(f"Carga horária: {disciplina['carga_horaria']} Horas")
            print("--------------------------------") 

    elif op == '4':
        print("\n---------- Docentes ----------")
        for docente in docentes:
            print(f"Nome: {docente['nome']}")
            print(f"Área de atuação: {docente['areaAtuacao']}")
            print(f"Departamento: {docente['departamento']}")
            print("------------------------------")

    elif op == '5':
        nomePesquisa = input("Digite o nome do docente: ")
        docenteEncontrado = pesquisa(docentes, nomePesquisa)
        if docenteEncontrado:
            print("\n-------------------------------")
            print(f"Docente: {docenteEncontrado['nome']}")
            print(f"Área de atuação: {docenteEncontrado['areaAtuacao']}")
            print(f"Departamento: {docenteEncontrado['departamento']}")
            print(f"Carga horária total: {cargaHorariaTotal(disciplinas, docenteEncontrado['nome'])} Horas")
            print("-------------------------------\n")
        else:
            print("\nDocente não encontrado.\n")

    elif op == '6':
        salvar = input("Deseja salvar as alterações? (S/N): ")
        if salvar.lower() == 's':
            with open('arquivo.txt', 'w') as file:
                for disciplina in disciplinas:
                    if disciplina['docente']:  
                        file.write(
                            f"{disciplina['identificador']},{disciplina['nome']},{disciplina['ementa']},{disciplina['docente']['nome']},{disciplina['carga_horaria']}\n"
                        )
                for docente in docentes:
                    file.write(
                        f"{docente['identificador']},{docente['nome']},{docente['areaAtuacao']},{docente['departamento']}\n"
                    )

            print("\nAlterações salvas.\n")
        break
    else:
        print("\nOpção inválida. Escolha novamente.")