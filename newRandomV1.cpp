#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include "board.h"

using namespace std;

int main(){
    board thisBoard;
    thisBoard.initBoard();
    for (int i = 0; i < 16; i++){    
        printf("%x ", thisBoard.piece[i]);
    }
    printf("\n");
    thisBoard.printBoard();
    thisBoard.generateEatMove();
    printf("------");
    thisBoard.generateSpeardMove();
    thisBoard.generateRevealMove();
    printf("\n");
    // if(thisBoard.eat==1){
    //     thisBoard.randomMove();
    // }
    // else{
    //     thisBoard.generateRevealMove();
    //     thisBoard.generateSpeardMove();
    //     thisBoard.randomMove();
    //}
    cout << thisBoard.allMoves.size()<<endl;
    for (int i = 0; i < thisBoard.allMoves.size();i++){
        cout << thisBoard.allMoves[i] << endl;
    }
}