#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int pawn = 1;

int hexboard[3][3];

const int start_pos[3][3] = {
    pawn, pawn, pawn, 0, 0, 0, -pawn, -pawn, -pawn
};

void start() {
    int a,b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            hexboard[a][b] = start_pos[a][b];
        }
    }
}

void board_rep() {
    int x,y;
    string piece;
    for (x = 2; x >= 0; x--) {
        cout << endl;
        for (y = 0; y < 3; y++) {
           switch (hexboard[x][y]) {
               case 0:
               piece = "-";
               break;
               case pawn:
               piece = "W";
               break;
               case -pawn:
               piece = "B";
               break;
           } 
           cout << " " << piece << " ";
        }
    }
    cout << endl << endl;
}

int main (void) {
    cout << "Welcome! It's time to play text-based HexaPawn 1.0" << endl << "Created by OneCalledSyn" << endl << endl;
    cout << "Please enter your move in a four character sequence as follows: " << endl << "Initial file, initial rank, ending file, ending rank" << endl;
    cout << "The bottom left square is a1, and the top right square is c3." << endl;
    cout << "Helpful commands: 'new' asks for a new game, 'exit'/'leave'/'abort'/'quit'/'close' all close the game, 'view' displays the board" << endl;
    
    string player_input;
    
    int ply = 0;
    
    start();
    
    while (true) {
        getline (cin, player_input);
        if (player_input.substr(0,4) == "exit" || player_input.substr(0,4) == "quit" || player_input.substr(0,5) == "leave" || 
        player_input.substr(0,5) == "abort" || player_input.substr(0,5) == "close") {
            break;
        }
        if (player_input.substr(0,3) == "new") {
            ply = 0;
            cout << endl << "New game!" << endl << "White to play: " << endl;
            start();
            board_rep();
        }
        if (player_input.substr(0,4) == "view") {
            board_rep();
        }
        if (player_input.substr(0,1) >= "a" && player_input.substr(0,1) <= "c" && player_input.substr(1,1) >= "1" && 
        player_input.substr(1,1) <= "3" && player_input.substr(2,1) >= "a" && player_input.substr(2,1) <= "c" && player_input.substr(3,1) >= "1" && 
        player_input.substr(3,1) <= "3") {
            int e,f,g,h;
            
            e = player_input[0] - 'a';
            f = player_input[1] - '1';
            g = player_input[2] - 'a';
            h = player_input[3] - '1';
            
            hexboard[h][g] = hexboard[f][e];
            hexboard[f][e] = 0;
           
            ply++;
            
            if ((ply % 2) == 0) {
                cout << endl << "White to play: " << endl;
                board_rep();
            }
            else {
                cout << endl << "Black to play: " << endl;
                board_rep();
            }
        }
        //else {
            //cout << "That is not a valid move!";
        //}
    }
}