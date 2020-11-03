//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file
#include <iostream>
#include "globals.h"
#include "GameState.h"
using namespace std;

void playMove(GameState& game_state) {
    
    //Check if the move is taken or not  
    
    if (game_state.get_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn()) == Empty){
        game_state.set_moveValid(true);
        
        //If move is empty, set the values of the game board from the selected row and column
        
        if (game_state.get_turn() == true){
            game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X);
        }
        else {
            game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
        }

        //win code values
        //win code value is different depending on the type of win
        //win code 1 to 3 are the horizontal wins
        //win code 4 to 6 are the vertical wins
        //win code 7 and 8 are the diagonals wins
        
        if(game_state.get_gameBoard(0,0) == game_state.get_gameBoard(0,1) && game_state.get_gameBoard(0,1) == game_state.get_gameBoard(0,2) && game_state.get_gameBoard(0,2) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(1);
        }
        else if(game_state.get_gameBoard(1,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(1,2) && game_state.get_gameBoard(1,2) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(2);
        }
        else if(game_state.get_gameBoard(2,0) == game_state.get_gameBoard(2,1) && game_state.get_gameBoard(2,1) == game_state.get_gameBoard(2,2)&& game_state.get_gameBoard(2,2) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(3);
        }
        else if(game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,0) && game_state.get_gameBoard(1,0) == game_state.get_gameBoard(2,0) && game_state.get_gameBoard(2,0) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(4);
        }
        else if(game_state.get_gameBoard(0,1) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,1) && game_state.get_gameBoard(0,1) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(5);
        }
        else if(game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,2) && game_state.get_gameBoard(1,2) == game_state.get_gameBoard(2,2) && game_state.get_gameBoard(2,2) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(6);
        }
        else if(game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,2) && game_state.get_gameBoard(2,2) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(7); 
        }
        else if(game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,0) && game_state.get_gameBoard(2,0) != Empty){
            game_state.set_gameOver(true);
            game_state.set_winCode(8);
        }
        
        //if there is no win, the win code is set to 0 and the game is not over
        
        else{
            game_state.set_winCode(0);
            game_state.set_gameOver(false);
        }
        
        //the move is valid and X already went, now it is O's turn
        
        if (game_state.get_turn() == true){ 
            game_state.set_turn(false);
        }
        
        //the move is valid and O already went, now it is X's turn
        
        else if(game_state.get_turn() == false){
            game_state.set_turn(true);
        }
    }
    
    //move is occupied by either an X or O
    //win code remains 0 and the turn doesn't switch
    
    else{
        game_state.set_moveValid(false);
        game_state.set_winCode(0);
        game_state.set_gameOver(false);
        game_state.set_turn(game_state.get_turn());
    }
    
    //checks for a tie and edge cases
    
    if((game_state.get_gameBoard(0,0) != Empty) && (game_state.get_gameBoard(0,1) != Empty) &&
       (game_state.get_gameBoard(0,2) != Empty) && (game_state.get_gameBoard(1,0) != Empty) &&
       (game_state.get_gameBoard(1,1) != Empty) && (game_state.get_gameBoard(1,2) != Empty) &&
       (game_state.get_gameBoard(2,0) != Empty) && (game_state.get_gameBoard(2,1) != Empty) &&
       (game_state.get_gameBoard(2,2) != Empty)){
        if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(0,2) == X) &&
            (game_state.get_gameBoard(1,1) == X) && (game_state.get_gameBoard(2,0) == X) &&
            (game_state.get_gameBoard(2,2) == X)) && ((game_state.get_gameBoard(0,1) == O) && 
            (game_state.get_gameBoard(1,2) == O) && (game_state.get_gameBoard(2,1) == O) &&
            (game_state.get_gameBoard(1,0) == O))){
                game_state.set_gameOver(true);
                game_state.set_winCode(8);
        }
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(0,1) == X) &&
                 (game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,2) == X) &&
                 (game_state.get_gameBoard(2,2) == X)) && ((game_state.get_gameBoard(1,0) == O) && 
                 (game_state.get_gameBoard(1,1) == O) && (game_state.get_gameBoard(2,0) == O) &&
                 (game_state.get_gameBoard(2,1) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(6);
        }
        
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(0,1) == X) &&
                 (game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(2,1) == X)) && ((game_state.get_gameBoard(1,0) == O) && 
                 (game_state.get_gameBoard(1,2) == O) && (game_state.get_gameBoard(2,0) == O) &&
                 (game_state.get_gameBoard(2,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(5);
        }
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(0,1) == X) &&
                 (game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,0) == X) &&
                 (game_state.get_gameBoard(2,0) == X)) && ((game_state.get_gameBoard(1,1) == O) && 
                 (game_state.get_gameBoard(1,2) == O) && (game_state.get_gameBoard(2,1) == O) &&
                 (game_state.get_gameBoard(2,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(4);
        }
        
        else if(((game_state.get_gameBoard(0,1) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(1,0) == X) && (game_state.get_gameBoard(1,2) == X) &&
                 (game_state.get_gameBoard(2,1) == X)) && ((game_state.get_gameBoard(0,0) == O) && 
                 (game_state.get_gameBoard(0,2) == O) && (game_state.get_gameBoard(2,0) == O) &&
                 (game_state.get_gameBoard(2,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(5);
        }
        
        else if(((game_state.get_gameBoard(0,1) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(2,1) == X) && (game_state.get_gameBoard(2,0) == X) &&
                 (game_state.get_gameBoard(2,2) == X)) && ((game_state.get_gameBoard(0,0) == O) && 
                 (game_state.get_gameBoard(1,0) == O) && (game_state.get_gameBoard(0,2) == O) &&
                 (game_state.get_gameBoard(1,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(5);
        }
        
        else if(((game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,2) == X) &&
                 (game_state.get_gameBoard(2,2) == X) && (game_state.get_gameBoard(2,1) == X) &&
                 (game_state.get_gameBoard(2,0) == X)) && ((game_state.get_gameBoard(0,0) == O) && 
                 (game_state.get_gameBoard(0,1) == O) && (game_state.get_gameBoard(1,0) == O) &&
                 (game_state.get_gameBoard(1,1) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(6);
        }
        
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(1,0) == X) &&
                 (game_state.get_gameBoard(2,0) == X) && (game_state.get_gameBoard(2,1) == X) &&
                 (game_state.get_gameBoard(2,2) == X)) && ((game_state.get_gameBoard(0,1) == O) && 
                 (game_state.get_gameBoard(0,2) == O) && (game_state.get_gameBoard(1,1) == O) &&
                 (game_state.get_gameBoard(1,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(4);
        }
        
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(1,0) == X) &&
                 (game_state.get_gameBoard(2,0) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(1,2) == X)) && ((game_state.get_gameBoard(0,1) == O) && 
                 (game_state.get_gameBoard(0,2) == O) && (game_state.get_gameBoard(2,1) == O) &&
                 (game_state.get_gameBoard(2,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(4);
        }
        
        else if(((game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,2) == X) &&
                 (game_state.get_gameBoard(2,2) == X) && (game_state.get_gameBoard(1,0) == X) &&
                 (game_state.get_gameBoard(1,1) == X)) && ((game_state.get_gameBoard(0,0) == O) && 
                 (game_state.get_gameBoard(0,1) == O) && (game_state.get_gameBoard(2,1) == O) &&
                 (game_state.get_gameBoard(2,0) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(6);
        }
        
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(1,0) == X) &&
                 (game_state.get_gameBoard(2,0) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(0,2) == X)) && ((game_state.get_gameBoard(0,1) == O) && 
                 (game_state.get_gameBoard(1,2) == O) && (game_state.get_gameBoard(2,1) == O) &&
                 (game_state.get_gameBoard(2,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(8);
        }
        
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(1,0) == X) &&
                 (game_state.get_gameBoard(2,0) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(2,2) == X)) && ((game_state.get_gameBoard(0,1) == O) && 
                 (game_state.get_gameBoard(0,2) == O) && (game_state.get_gameBoard(1,2) == O) &&
                 (game_state.get_gameBoard(2,1) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(7);
        }
        
        else if(((game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,2) == X) &&
                 (game_state.get_gameBoard(2,2) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(0,0) == X)) && ((game_state.get_gameBoard(0,1) == O) && 
                 (game_state.get_gameBoard(1,0) == O) && (game_state.get_gameBoard(2,1) == O) &&
                 (game_state.get_gameBoard(2,0) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(7);
        }
        
        else if(((game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,2) == X) &&
                 (game_state.get_gameBoard(2,2) == X) && (game_state.get_gameBoard(2,0) == X) &&
                 (game_state.get_gameBoard(1,1) == X)) && ((game_state.get_gameBoard(0,0) == O) && 
                 (game_state.get_gameBoard(0,1) == O) && (game_state.get_gameBoard(1,0) == O) &&
                 (game_state.get_gameBoard(2,1) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(8);
        }
        
        else if(((game_state.get_gameBoard(2,0) == X) && (game_state.get_gameBoard(2,1) == X) &&
                 (game_state.get_gameBoard(2,2) == X) && (game_state.get_gameBoard(0,0) == X) &&
                 (game_state.get_gameBoard(1,1) == X)) && ((game_state.get_gameBoard(0,1) == O) && 
                 (game_state.get_gameBoard(0,2) == O) && (game_state.get_gameBoard(1,2) == O) &&
                 (game_state.get_gameBoard(1,0) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(7);
        }
        
        else if(((game_state.get_gameBoard(2,0) == X) && (game_state.get_gameBoard(2,1) == X) &&
                 (game_state.get_gameBoard(2,2) == X) && (game_state.get_gameBoard(0,2) == X) &&
                 (game_state.get_gameBoard(1,1) == X)) && ((game_state.get_gameBoard(0,0) == O) && 
                 (game_state.get_gameBoard(0,1) == O) && (game_state.get_gameBoard(1,2) == O) &&
                 (game_state.get_gameBoard(1,0) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(8);
        }
        
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(0,1) == X) &&
                 (game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(2,2) == X)) && ((game_state.get_gameBoard(1,0) == O) && 
                 (game_state.get_gameBoard(2,0) == O) && (game_state.get_gameBoard(2,1) == O) &&
                 (game_state.get_gameBoard(1,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(7);
        }
        
        else if(((game_state.get_gameBoard(0,0) == X) && (game_state.get_gameBoard(0,1) == X) &&
                 (game_state.get_gameBoard(0,2) == X) && (game_state.get_gameBoard(1,1) == X) &&
                 (game_state.get_gameBoard(2,0) == X)) && ((game_state.get_gameBoard(1,0) == O) && 
                 (game_state.get_gameBoard(2,1) == O) && (game_state.get_gameBoard(1,2) == O) &&
                 (game_state.get_gameBoard(2,2) == O))){
                    game_state.set_gameOver(true);
                    game_state.set_winCode(8);
        }
        else{
            game_state.set_gameOver(true);
            game_state.set_winCode(0);
        }
    }
}