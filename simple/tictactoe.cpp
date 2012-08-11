#include <iostream>

using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
int player, choice;
char mark;

void clear() {
    cout << string(100, '\n');
}

void drawBoard() {
    clear();
    cout << "\tTic Tac Toe" << endl;
    cout << "Player 1 is X - Player 2 is O" << endl;
   
    cout << "\t   |   |   " << endl;
    cout << "\t " << square[1] << " | " << square[2] << " | " << square[3] << " " << endl;
    cout << "\t___|___|___" << endl;
    cout << "\t   |   |   " << endl;
    cout << "\t " << square[4] << " | " << square[5] << " | " << square[6] << " " << endl;
    cout << "\t___|___|___" << endl;
    cout << "\t   |   |   " << endl;
    cout << "\t " << square[7] << " | " << square[8] << " | " << square[9] << " " << endl;
    cout << "\t   |   |   " << endl;
}

int checkWin() {
    if(square[1] == square [2] && square[1] == square[3])
        return 1;
    else if(square[4] == square [5] && square[4] == square[6])
        return 1;
    else if(square[7] == square [8] && square[7] == square[9])
        return 1;
    else if(square[1] == square [4] && square[1] == square[7])
        return 1;
    else if(square[2] == square [5] && square[2] == square[8])
        return 1;
    else if(square[3] == square [6] && square[3] == square[9])
        return 1;
    else if(square[1] == square [5] && square[1] == square[9])
        return 1;
    else if(square[3] == square [5] && square[3] == square[7])
        return 1;
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' &&
            square[4] != '4' && square[5] != '5' && square[6] != '6' &&
            square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void displayResult(int result) {
    if(result == 1)
        cout << "Congratulations Player " << player << ", you won!" << endl;
    else if(result == 0)
        cout << "Game was a tie, better luck next time!" << endl;
    else
        cout << "Sorry, there was an error with this game." << endl;
}

void play() {
    player = 0;
    int result = -1;
    do {
        player++;
        drawBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        cout << "Player " << player << "'s move: ";
        cin >> choice;
        if(choice == 1 && square[1] == '1') 
            square[1] = mark;
        else if(choice == 2 && square[2] == '2')
            square[2] = mark;
        else if(choice == 3 && square[3] == '3')
            square[3] = mark;
        else if(choice == 4 && square[4] == '4')
            square[4] = mark;
        else if(choice == 5 && square[5] == '5')
            square[5] = mark;
        else if(choice == 6 && square[6] == '6')
            square[6] = mark;
        else if(choice == 7 && square[7] == '7')
            square[7] = mark;
        else if(choice == 8 && square[8] == '8')
            square[8] = mark;
        else if(choice == 9 && square[9] == '9')
            square[9] = mark;
        else {
            cout << "Invalid move!" << endl;
            player--;
            cin.ignore();
            cin.get();
        }
        result = checkWin();
    } while(result == -1);
    drawBoard();
    displayResult(result);
}

int main() {
    play();
}

