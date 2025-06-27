import os

map = [[ 0, 0, 0 ],
        [ 0, 0, 0 ],
        [ 0, 0, 0 ]]

player = {
    'X' : 0,
    'O' : 0
}

def show_map():
    print(f"\033[93mplayer X = {player['X']}  player O = {player['O']}\033[0m")
    print("\033[92m---------\033[0m")
    for row in map:
        row_str = " ".join(str(cell) if cell != 0 else '.' for cell in row)
        print(f"\033[94m| {row_str} |\033[0m")
    print("\033[92m---------\033[0m")


def change_map( x , y , player_game):
    if ( x < 3 and y < 3 ):
        if ( map[x][y] == 0 ):
            map[x][y] = player_game
            return True
        else:
            return False
    else:
        return False
    
    
def check_win(player_game):
    for i in range(3):
        if map[i][0] == map[i][1] == map[i][2] == player_game:
            return True
        if map[0][i] == map[1][i] == map[2][i] == player_game:
            return True
    if map[0][0] == map[1][1] == map[2][2] == player_game:
        return True
    if map[0][2] == map[1][1] == map[2][0] == player_game:
        return True
    return False


def clear_map():
    for i in range(3):
        for j in range(3):
            map[i][j] = 0
                   
   
def player_input():
    print('x = ')
    x = input()
    print('y = ')
    y = input()
    
    while x.isdigit() == False or y.isdigit() == False:
        print('You should enter numbers!')
        x = input()
        y = input()
    
    x = int(x)
    y = int(y)
    return x , y

def check_map():
    if ( any(0 in row for row in map)):
        return True
    else:
        return False
    
def main():
    while True:
        player_turn = 'X'
        while True:
            os.system('cls' if os.name == 'nt' else 'clear') 
            show_map()
            print(f"player {player_turn} please enter your move: ")
            x , y = player_input()
            if change_map(x , y , player_turn) == True:
                if check_map() == False:
                    print("The game was tied")
                    break
                if check_win(player_turn) == True:
                    print(f"player {player_turn} win!")
                    player[player_turn] += 1
                    break
                else:
                    if player_turn == 'X':
                        player_turn = 'O'
                    else:
                        player_turn = 'X'
            else:
                print('This cell is occupied! Choose another one!')
                continue
        print("do you want to continue (Y/N)")
        game_check = input()
        if (game_check == 'N'):
            break
        clear_map()


main()
        
