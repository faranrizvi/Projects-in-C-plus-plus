//
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file


#include <iostream>
#include <string>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function prototype for playMove
void playMove(GameState&);
char convert(int);
char result;

// The main function
int main() {

    /**********************************************************************************/
    /* Create an initialized game state object                                        */
    /**********************************************************************************/
    GameState game_state;

    // Read two integers from the user that represent the row and column
    // the player would like to place an X or an O in
    // You can assume there will be no formatting errors in the input
    int row;
    int col;
    int i;
    int j;
    int newLoc;
    
    while (!(game_state.get_gameOver())) {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
            cout << "Invalid board coordinates " << row << " " << col << endl << endl;
           continue;
        }
            
        game_state.set_selectedColumn(col);
        game_state.set_selectedRow(row);
        
        cout << "Selected row " << game_state.get_selectedRow() << " " << "and column " << game_state.get_selectedColumn() << endl;
        
        playMove(game_state);
        
        cout << "Game state after playMove: " << endl; 
   
        cout << "Board:" << endl;
         
        for(i = 0; i < boardSize; i++){
            cout << "   ";
            for(j = 0; j < boardSize; j++){
                
                if((i == (game_state.get_selectedRow())) && (j == (game_state.get_selectedColumn()))){
                    
                    if(game_state.get_turn() == true){
                        newLoc = game_state.get_gameBoard(i,j);
                        result = convert(newLoc);
                        cout << " " << result;
                    }
                    else{
                        newLoc = game_state.get_gameBoard(i,j);
                        result = convert(newLoc);
                        cout << " " << result;
                    }
                }
                else{
                    newLoc = game_state.get_gameBoard(i,j);
                    result = convert(newLoc);
                    cout << " " << result;
                }
            }
            cout << endl;
        }
        
        
        if(game_state.get_moveValid() == true){
            cout << "moveValid: true" << endl;
        }
        else{
            cout << "moveValid: false" << endl;
        }
        
        if(game_state.get_gameOver() == false){
            cout << "gameOver: false" << endl;
        }
        else{
            cout << "gameOver: true" <<  endl;
        }
        /*
        for(i = 0; i < 9; i++){
            if(i == game_state.get_winCode()){
                cout << "winCode: " << i << endl << endl;
            }
        }
        */
        
        cout << "winCode: " << game_state.get_winCode() << endl << endl;
    }
    return 0;
}

char convert(int var){
    if(var == O){
        result = (char) var;
        result = 'O';
    }
    else if(var == X){
        result = (char) var;
        result = 'X';
    }
    else{
        result = (char) var;
        result = 'B';
    }
    return(result);
}