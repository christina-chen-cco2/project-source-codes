import twenty_four_game_board, twenty_six_check_tic_tac_toe_solution


def draw_game(one_name, two_name, board_size):

    board_string = twenty_four_game_board.board(board_size)
    board_list = list(board_string)
    move_squares = 0
    move_squares_list = []
    checker = -1
    move = ''
    row = -1
    column = -1
    turn_done = False
    filled_squares = 0

    while move_squares != -1:
        move_squares = board_string.find('  |', move_squares + 1)
        move_squares_list.append(move_squares)
    move_squares_list.remove(-1)

    while checker != 1 and checker != 2 and filled_squares != len(move_squares_list):
            # Player X's turn
            turn_done = False
            move = input('\n' + one_name + '\'s move: ')
            row = int(move[0])
            column = int(move[3])
            while turn_done == False:
                if board_list[move_squares_list[int(board_size[3]) * (row - 1) + column - 1]] == 'O':
                    print('That\'s ' + two_name + '\'s spot.\n')
                    move = input(one_name + '\'s move: ')
                    row = int(move[0])
                    column = int(move[3])
                elif board_list[move_squares_list[int(board_size[3]) * (row - 1) + column - 1]] == 'X':
                    print('You already took that spot.\n')
                    move = input(one_name + '\'s move: ')
                    row = int(move[0])
                    column = int(move[3])
                else:
                    turn_done = True
            board_list[move_squares_list[int(board_size[3]) * (row - 1) + column - 1]] = 'X'
            filled_squares += 1
            board_string = ''.join(board_list)
            print(board_string)
            checker = twenty_six_check_tic_tac_toe_solution.checker(board_list, move_squares_list, board_size)

            if checker != 1 and filled_squares != len(move_squares_list):
                # Player O's turn
                turn_done = False
                move = input('\n' + two_name + '\'s move: ')
                row = int(move[0])
                column = int(move[3])
                while turn_done == False:
                    if board_list[move_squares_list[int(board_size[3]) * (row - 1) + column - 1]] == 'X':
                        print('That\'s ' + one_name + '\'s spot.\n')
                        move = input(two_name + '\'s move: ')
                        row = int(move[0])
                        column = int(move[3])
                    elif board_list[move_squares_list[int(board_size[3]) * (row - 1) + column - 1]] == 'O':
                        print('You already took that spot.\n')
                        move = input(two_name + '\'s move: ')
                        row = int(move[0])
                        column = int(move[3])
                    else:
                        turn_done = True
                board_list[move_squares_list[int(board_size[3]) * (row - 1) + column - 1]] = 'O'
                filled_squares += 1
                board_string = ''.join(board_list)
                print(board_string)
                checker = twenty_six_check_tic_tac_toe_solution.checker(board_list, move_squares_list, board_size)

    if checker == 1:
        print('\n' + one_name + ' wins.')
    elif checker == 2:
        print('\n' + two_name + ' wins.')
    else:
        print('\nNo moves left: ' + one_name + ' and ' + two_name + ' are tied.')

    print('Thank you for playing tic-tac-toe.')
    
