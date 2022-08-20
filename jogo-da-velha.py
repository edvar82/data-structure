import random
blank = ' '
chars = ['O', 'X']

def createBoard():
    matriz = []

    for i in range(3):
        line = []
        for j in range(3):
            line.append(' ')

        matriz.append(line)
    return matriz

def showBoard(board):
    for i in range(3):
        print(("|").join(board[i]))
        if(i<2):
            print('------')

def getInput(mensagem):
    try:
        number = int(input(mensagem))
        if(number >= 1 and number <= 3):
            return number - 1
        else:
            print('Valor inválido')
            return getInput(mensagem)
    except:
        print('Valor inválido')
        return getInput(mensagem)

def getComputerMove(board):
    while True:
        line = random.randint(0,2)
        column = random.randint(0,2)
        if(board[line][column] == blank):
            return line, column

def verifyMovement(board, line, column):
    if(board[line][column] == ' '):
        return True
    else:
        return False

def verifyWinner(board):

    #line
    for i in range(3):
        if(board[i][0] == board[i][1] and board[i][1] == board[i][2] and board[i][0] != blank):
            return board[i][0]
    
    #column
    for i in range(3):
        if(board[0][i] == board[1][i] and board[1][i] == board[2][i] and board[0][i] != blank):
            return board[0][i]

    #diagonal principal
    if(board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[0][0] != blank):
        return board[0][0]

    #diagonal secundaria
    if(board[0][2] == board[1][1] and board[1][1] == board[2][0] and board[0][2] != blank):
        return board[0][2]

    #return false caso tenha algum blank
    for i in range(3):
        for j in range(3):
            if(board[i][j] == blank):
                return False

    #return empate no final
    return 'EMPATE'

def makeMoviment(board, line, column, player):
    board[line][column] = chars[player]

player = 0
board = createBoard()
winner = verifyWinner(board)
choice = input('Digite (1) para o computador começar ou (2) para você começar: ')

if (choice != '1' and choice != '2'):
    print('[ERRO] Valor inválido')
else:
    if(choice == '1'):
        print("\nComputador começa\n\n")
    else:
        print("\nVocê começa\n\n")

    while(not winner):
        showBoard(board)
        if(int(choice) % 2 == 1):
            print("\nLance do computador: \n")
            line, column = getComputerMove(board)
            computer = 1
            makeMoviment(board, line, column, computer)
        else:
            print("\nSua vez de jogar:\n")
            i = getInput('Linha: ')
            j = getInput('Coluna: ')

            if(verifyMovement(board, i, j)):
                makeMoviment(board, i, j, player)
            else:
                break
        choice = int(choice) + 1
        winner = verifyWinner(board)

    print('\n============================\n')
    showBoard(board)
    print("\nO jogo acabou!\n")
    if(winner == 'EMPATE'):
        print('Empate!')
    elif(type(winner) == str):
        print("O ganhador foi: " + winner)
    else:
        print("[ERRO] - MOVIMENTO INVALIDO")
    print('============================')