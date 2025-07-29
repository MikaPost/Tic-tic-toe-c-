#include <iostream>

using namespace std;

<<<<<<< HEAD
char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

void print_board() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

bool check_win(char symbol) {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;

    for (int j = 0; j < 3; j++)
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
            return true;

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return true;

    return false;
}

bool board_full() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '-')
                return false;
    return true;
}

void player_turn(char symbol) {
    int row, col;
    while (true) {
        cout << "Player " << symbol << " - Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;

        if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {
            if (board[row - 1][col - 1] == '-') {
                board[row - 1][col - 1] = symbol;
                break;
            }
            else {
                cout << "That spot is already taken. Try again.\n";
            }
        }
        else {
            cout << "Invalid input. Try again.\n";
        }
    }
}

void reset_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '-';
}

void start_game() {
    reset_board();
    cout << "=== Start Game ===\n";
    char current_player = 'X';

    while (true) {
        print_board();
        player_turn(current_player);

        if (check_win(current_player)) {
            print_board();
            cout << "Player " << current_player << " wins!\n";
            break;
        }
        else if (board_full()) {
            print_board();
            cout << "It's a draw!\n";
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

int main() {
    int choice;
=======
class TicTacToe {
private:
    char board[3][3];
    char current_player;

    void reset_board() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = '-';
    }

    void print_board() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j];
                if (j < 2) cout << " |";
            }
            cout << "\n";
            if (i < 2)
                cout << "---+---+---\n";
        }
        cout << "\n";
    }

    bool check_win(char symbol) {
        for (int i = 0; i < 3; i++)
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
                return true;

        for (int j = 0; j < 3; j++)
            if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
                return true;

        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
            return true;

        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
            return true;

        return false;
    }

    bool board_full() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == '-')
                    return false;
        return true;
    }

    void player_turn() {
        int row, col;
        while (true) {
            cout << "Player " << current_player << " - Enter row (1-3): ";
            cin >> row;
            cout << "Enter column (1-3): ";
            cin >> col;

            if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {
                if (board[row - 1][col - 1] == '-') {
                    board[row - 1][col - 1] = current_player;
                    break;
                }
                else {
                    cout << "That spot is already taken. Try again.\n";
                }
            }
            else {
                cout << "Invalid input. Try again.\n";
            }
        }
    }

    void switch_player() {
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

public:
    TicTacToe() {
        current_player = 'X';
        reset_board();
    }

    void start() {
        reset_board();
        current_player = 'X';
        cout << "=== Start Game ===\n";

        while (true) {
            print_board();
            player_turn();

            if (check_win(current_player)) {
                print_board();
                cout << "Player " << current_player << " wins!\n";
                break;
            }
            else if (board_full()) {
                print_board();
                cout << "It's a draw!\n";
                break;
            }

            switch_player();
        }
    }
};

int main() {
    int choice;
    TicTacToe game;
>>>>>>> b3f2ef4 (oopДобавьте файлы проекта.)

    while (true) {
        cout << "=== TIC-TAC-TOE ===\n";
        cout << "1. Start game\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
<<<<<<< HEAD
            start_game();
=======
            game.start();
>>>>>>> b3f2ef4 (oopДобавьте файлы проекта.)
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    cout << "\nGoodbye!\n";
    return 0;
}
