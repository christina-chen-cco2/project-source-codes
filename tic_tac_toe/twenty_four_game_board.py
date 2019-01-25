def board(board_size):
    pipes = int(board_size[0])
    hyphens = int(board_size[3])
    string_board = ''
    for i in range(pipes):
        string_board = string_board + rows(hyphens) + '\n'
        string_board = string_board + columns(hyphens) + '\n'
    string_board = string_board + rows(hyphens)
    return string_board


def rows(hyphens=1):
    string_row = ''
    for i in range(hyphens):
        string_row = string_row + ' ---'
    return string_row


def columns(hyphens=1):
    string_column = ''
    for i in range(hyphens + 1):
        string_column = string_column + '|   '
    return string_column
