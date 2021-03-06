def checker(board_list, move_squares_list, board_size):

    rows = int(board_size[0])
    columns = int(board_size[3])
    one_score = 0
    two_score = 0

    # check by rows
    for i in range(0, len(move_squares_list), columns):
        for j in range(columns):
            if board_list[move_squares_list[j + i]] == 'X':
                one_score += 1
                if one_score == columns:
                    return 1
            elif board_list[move_squares_list[j + i]] == 'O':
                two_score += 1
                if two_score == columns:
                    return 2
        one_score = 0
        two_score = 0

    # check by columns
    for i in range(0, columns):
        for j in range(0, len(move_squares_list), columns):
            if board_list[move_squares_list[j + i]] == 'X':
                one_score += 1
                if one_score == columns:
                    return 1
            elif board_list[move_squares_list[j + i]] == 'O':
                two_score += 1
                if two_score == columns:
                    return 2
        one_score = 0
        two_score = 0

    one_score = 0
    two_score = 0

    # check by top-left to bottom-right diagonal
    for i in range(0, len(move_squares_list), (1 + columns)):
        if board_list[move_squares_list[i]] == 'X':
            one_score += 1
            if one_score == columns:
                return 1
        elif board_list[move_squares_list[i]] == 'O':
            two_score += 1
            if two_score == columns:
                return 2

    one_score = 0
    two_score = 0

    # check by top-right to bottom-left diagonal
    for i in range((columns - 1), len(move_squares_list), (columns - 1)):
        if board_list[move_squares_list[i]] == 'X':
            one_score += 1
            if one_score == columns:
                return 1
        elif board_list[move_squares_list[i]] == 'O':
            two_score += 1
            if two_score == columns:
                return 2


