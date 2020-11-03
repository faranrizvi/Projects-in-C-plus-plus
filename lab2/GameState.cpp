#include <iostream>
#include <valarray>
#include <string>
#include "globals.h"
#include "GameState.h"

using namespace std;

// ECE244 Student: add you code below
GameState::GameState(){
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    winCode = 0;
    turn = true;
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            gameBoard[i][j] = Empty;
        }                                 
    }
}

int GameState::get_selectedRow(){
    return(selectedRow);
}

int GameState::get_selectedColumn(){
    return(selectedColumn);
}

void GameState::set_selectedRow(int value){
    selectedRow = value;
}

void GameState::set_selectedColumn(int value){
    selectedColumn = value;
}

bool GameState::get_moveValid(){
    return(moveValid);
}

void GameState::set_moveValid(bool value){
    moveValid = value;
}

bool GameState::get_gameOver(){
    return(gameOver);
}
