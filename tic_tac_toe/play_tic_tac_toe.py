import twenty_seven_tic_tac_toe_draw

board_size = input('\nWelcome to tic-tac-toe.\nPlease enter size of board as \'row, column\' (ex. 3, 3): ')

while int(board_size[0]) < 3 or int(board_size[3]) < 3 or int(board_size[0]) != int(board_size[3]):
    board_size = input('\nSmallest board size allowed is 3, 3. Number of rows and number of columns must be the same.'
                       '\nPlease re-enter size of board: ')

one_name = input('\nPlayer X\'s name: ')
two_name = input('Player O\'s name: ')
answer = input('\nPlease enter your moves as \'row, column\' (ex. 2, 3). Press any key to start the game.')

twenty_seven_tic_tac_toe_draw.draw_game(one_name, two_name, board_size)

