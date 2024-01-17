class xo:
    def __init__(self, board):
        self.board = board
        self.f = []

    def xoboard(self, x):
        for i in range(0, len(x), 3):
            row = x[i:i + 3]
            print(row[0], "|", row[1], "|", row[2])
            if i < len(x) - 3:
                print('---------')

    def check_winner(self, player):
        
        for i in range(0, 9, 3):
            if self.board[i] == self.board[i + 1] == self.board[i + 2] == player:
                return True

        
        for i in range(3):
            if self.board[i] == self.board[i + 3] == self.board[i + 6] == player:
                return True

       
        if self.board[0] == self.board[4] == self.board[8] == player:
            return True
        if self.board[2] == self.board[4] == self.board[6] == player:
            return True

        return False

    def values_update(self, player):
        pos = int(input(f"Player {player}, enter a position to enter a value: "))
        if pos >= 9:
            print("Value out of range")
        elif pos in self.f:
            print("Position is occupied")
            

            
           
        else:
            self.f.append(pos)
            self.board[pos] = player
            self.xoboard(self.board)
            if self.check_winner(player):
                print(f"Player {player} wins!")
                return True
            return False
        
    def is_board_full(self):
        return all(cell != ' ' for cell in self.board)        
        
        
        



initial_board = [' ' for _ in range(9)]
game = xo(initial_board)
game.xoboard(initial_board)

player = 'X'
while True:
    if game.values_update(player):
        break
    if game.is_board_full():
        print("It's a draw!")
        break
    player = 'O' if player == 'X' else 'X'
