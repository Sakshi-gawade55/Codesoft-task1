#include <iostream>
#include <vector>

// Function prototypes
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool checkDraw(const std::vector<std::vector<char>>& board);
void playGame();
bool playAgain();

int main() {
    do {
        playGame();
    } while (playAgain());
    
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to make a move
bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player) {
    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = player;
        return true;
    }
    return false;
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to handle the gameplay
void playGame() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard(board);
        int row, col;

        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (makeMove(board, row, col, currentPlayer)) {
            gameWon = checkWin(board, currentPlayer);
            if (!gameWon) {
                gameDraw = checkDraw(board);
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    displayBoard(board);

    if (gameWon) {
        std::cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!" << std::endl;
    } else if (gameDraw) {
        std::cout << "The game is a draw!" << std::endl;
    }
}

// Function to ask if players want to play again
bool playAgain() {
    char response;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> response;
    return response == 'y' || response == 'Y';
}