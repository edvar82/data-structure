numero = input()
sinal = True 
ponto = False
validar = True
inicio = True
cont_ponto = 0
tam = len(numero)

for i in numero:
    if(not i.isdigit()):
        if(i != '-' and i != '+' and i != '.' and i != ','):
            validar = False

for i in range(len(numero)):
    if(i == 0):
        if(numero[i] == '.' or numero[i] == ','):
            inicio = False

    if(i > 0):

        if(numero[i] == '+' or numero[i] == '-'):
            sinal = False

        if(numero[i] == '.' or numero[i] == ','):
            ponto = True
            cont_ponto += 1

if(sinal) and (validar) and (inicio) and (cont_ponto <= 1) and (len(numero) > 1) and (not numero[tam-1] == '.') and (not numero[tam-1] == ',') and (not numero[1] == '.') and (not numero[1] == ','):
    if(ponto):
        print("Número real")
    elif(not ponto and numero[0] == '-'):
        print("Número inteiro")
    else:
        print("Número natural")
else:
    print("Error")

a = input()
numero = []

numero = list(a)

for i in numero:
    if(i == '.'):
        numero.remove(i)

                                      