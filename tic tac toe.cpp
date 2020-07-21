#include <iostream>
#include <cctype>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <ctime>
#include <conio.h>

using namespace std;

static int moves = 0;
bool win = false;
int board[9] = { -1, -1, -1, -1, -1, -1, -1, -1 , -1};
wchar_t token;
char winner = '-';

int smartMove(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            if (((board[1] == board[2])&&(board[1]!=-1) ) || ((board[3] == board[6])&&(board[3]!=-1)) || ((board[4] == board[8])&&(board[4]!=-1))) return 0;
        }
        else if (v[i] == 1) {
            if (((board[0] == board[2])&&board[0]!=-1) || ((board[4] == board[7])&&board[4]!=-1)) return 1;
        }
        else if (v[i] == 2) {
            if (((board[0] == board[1])&&board[0]!=-1) || ((board[5] == board[8])&&board[5]!=-1) || ((board[4] == board[6])&&board[4]!=-1)) return 2;
        }
        else if (v[i] == 3) {
            if (((board[0] == board[6])&&board[0]!=-1) || ((board[4] == board[5])&&board[4]!=-1)) return 3;
        }
        else if (v[i] == 4) {
            if (((board[1] == board[7])&&board[1]!=-1) || ((board[3] == board[5])&&board[3]!=-1)) return 4;
        }
        else if (v[i] == 5) {
            if (((board[2] == board[8])&&board[2]!=-1) || ((board[3] == board[4])&&board[3]!=-1)) return 5;
           
        }
        else if (v[i] == 6) {
            if (((board[0] == board[3])&&board[0]!=-1) || ((board[7] == board[8])&&board[7]!=-1) || ((board[2] == board[4])&&board[2]!=-1)) return 6;
        }
        else if (v[i] == 7) {
            if (((board[6] == board[8])&&board[6]!=-1) || ((board[1] == board[4])&&board[1]!=-1)) return 7;
        }
        else{
            if (((board[6] == board[7])&&board[6]!=-1) || ((board[2] == board[5])&&board[2]!=-1) || ((board[4] == board[0])&&board[4]!=-1)) return 8;
            return v[rand() % v.size()];
        }

    }
}

void printGame()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    
    wstring b[5] = { L" 1 │ 2 │ 3 ", L"───┼───┼───" , L" 4 │ 5 │ 6 ", L"───┼───┼───", L" 7 │ 8 │ 9 " };

    if (moves == 0) {
        wcout << L" 1 │ 2 │ 3 " << endl;
        wcout << L"───┼───┼───" << endl;
        wcout << L" 4 │ 5 │ 6 " << endl;
        wcout << L"───┼───┼───" << endl;
        wcout << L" 7 │ 8 │ 9 " << endl;
    }
    else {
        for (int i = 0; i < 5; ++i)
        {
            if (i == 0) {
                if (board[0] == 0) b[i][1] = L'O';
                else if (board[0] == 1) b[i][1] = L'X';
                if (board[1] == 0) b[i][5] = L'O';
                else if (board[1] == 1) b[i][5] = L'X';
                if (board[2] == 0) b[i][9] = L'O';
                else if (board[2] == 1) b[i][9] = L'X';
                
                wcout << b[i] << endl;
            }
            else if (i == 2) {
                if (board[3] == 0) b[i][1] = L'O';
                else if (board[3] == 1) b[i][1] = L'X';
                if (board[4] == 0) b[i][5] = L'O';
                else if (board[4] == 1) b[i][5] = L'X';
                if (board[5] == 0) b[i][9] = L'O';
                else if (board[5] == 1) b[i][9] = L'X';

                wcout << b[i] << endl;
            }
            else if (i == 4) {
                if (board[6] == 0) b[i][1] = L'O';
                else if (board[6] == 1) b[i][1] = L'X';
                if (board[7] == 0) b[i][5] = L'O';
                else if (board[7] == 1) b[i][5] = L'X';
                if (board[8] == 0) b[i][9] = L'O';
                else if (board[8] == 1) b[i][9] = L'X';

                wcout << b[i] << endl;
            }
            else wcout << b[i] << endl;
        }
    }
}
void check_win()
{
    int x;
    if (token == 'O') x = 0;
    else x = 1;
    int t;

    for (int i = 0; i < 7; i+=3)
    {
        if (board[i] != -1 && board[i + 1] == board[i] && board[i + 2] == board[i]) {
            win = true;
            t = i;
            break;
        }
    }
    if (win) {
        if (board[t] == x) winner = 'P';
        else winner = 'C';
    }
    if (!win)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (board[i] != -1 && board[i + 3] == board[i] && board[i + 6] == board[i]) {
                win = true;
                t = i;
                break;
            }
        }
    }
    if (win) {
        if (board[t] == x) winner = 'P';
        else winner = 'C';
    }
    if (!win)
    {
        if (board[0] != -1 && board[4] == board[0] && board[0] == board[8]) {
            win = true;
            t = 0;
        }
        else if(board[2] != -1 && board[4] == board[2] && board[6] == board[2]) {
            win = true;
            t = 2;
        }
    }
    if (win) {
        if (board[t] == x) winner = 'P';
        else winner = 'C';
    }


}
void printRules(void)
{
    wcout << endl<<"WELCOME!"<<endl<<"The rules of the game are simple."<<endl;
    wcout << "Each block on the board is numbered; you just have to enter the number on which you want to place your token." << endl;
    wcout << "The board will look as follows:- " << endl;
    printGame();
    wcout << "Just enter the number of your chosen block when prompted with \"Your move\"" << endl;
    system("pause");
}
char choose_token()
{
    wcout << endl << "----------------------------------" << endl;
    wcout << "what do you want to be, X or O?" << endl;
    wcout << "Your choice: ";
    wchar_t c='-';
    do {
        wcin >> c;
        if (c == '0') { // in case the user enters 0 instead of O
            c = 'O';
        }
        c = toupper(c);
    } while (c != 'X' && c != 'O');

    wcout <<endl<< "----------------------------------" << endl;
    
    return c;
}
void changeBoard(int m)
{
    if (token == 'O') {
        board[m - 1] = 0;
    }
    else {
        board[m - 1] = 1;
    }
}
void computerMove() {
 
    vector<int> validMoves;

    for (int i = 0; i < 9; ++i) {
        if (board[i] == -1) validMoves.push_back(i);
    }
   // int CompMove = rand() % validMoves.size();
    int CompMove = smartMove(validMoves);
    wcout << "Computer's move: " << CompMove + 1 << endl;
    if (token == 'O') board[CompMove] = 1;
    else board[CompMove] = 0;
    
}
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void resetVals(void)
{
    ::moves = 0;
    ::win = false;
    for (int i = 0; i < 9; ++i)
    {
        ::board[i] = -1;
    }
    ::winner = '-';
}
void play(void)
{
    resetVals();
    ::token = choose_token();
    printGame();
    int m = -1; 

    while (!win)
    {
       
        vector<int> validMoves;

        for (int i = 0; i < 9; ++i) {
            if (board[i] == -1) validMoves.push_back(i);
        }
        while (true) {
            wcout << "Your move: ";
            if (!(cin >> m)) {
                wcout << "\nPlease enter numbers only!" << endl;
                clearInput();
                continue;
            }
            int f = 0;
            for (int i = 0; i < validMoves.size(); ++i) {
                if (m - 1 == validMoves[i]) {
                    f = 1; break;
                }
            }
            if (f == 1) {
                 break;
            }
            wcout << "Not a valid move!" << endl;
        }
        ++moves;
        changeBoard(m);
        printGame();
        check_win();
        if(win) break;
        if (moves == 5) break;
        computerMove();
        printGame();
        check_win();
        wcout << endl;
        wcout << "------------------------------------------------------" << endl;
    }
    if (winner == 'P')
        wcout << "Congratulations! You won!" << endl;
    else if (winner == 'C') wcout << "You lost! Better luck next time!" << endl;
    else wcout << "It's a draw!" << endl;

}
int main()
{
    printRules();
    srand(time(NULL));
    char playagain='y';
    while (playagain=='y') {
        play();
        wcout << endl << endl << "DO YOU WANT TO PLAY AGAIN? (y/n):";
        cin >> playagain;
        playagain = tolower(playagain);
       
        while (playagain != 'y' && playagain != 'n')
        {
            wcout << "Enter 'y' or 'n' only: ";
            cin >> playagain;
        }
        if (playagain == 'n') wcout << endl << "Thanks for playing!" << endl;
    }
  
}
