nome = input()
validar = True
for i in nome:
    if(i.isdigit()):
        validar = False

if(validar) and (len(nome) > 0) and (nome[0] != ' ') and (nome[0].isupper()):
    print('Nome válido\n')
else:
    print("Erro\n")