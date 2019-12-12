#ifndef boardh
#define boardh

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include"player.h"
#include"U32.h"
#include"move.h"

class board{
    public:
        board();
        U32 piece[16]={0};
        U32 red, black, occupied;
        Move boardMove;
        vector<board> possibility;
        int eat = 0;

        int getPieceType(U32);
        void initBoard();
        void printBoard();
        U32 generateCMove(U32);
        void generateEatMove();
        void generateSpeardMove();
        void generateRevealMove();
        void generateAllMove();
        void simulateBoard();
        int pieceCount(int);
        int scoreBoard();
        const board &operator=(board);
        void printAll();

    private:
        player Myplayer;
        int numUnrevealPiece[16] = {0,1,2,2,2,2,2,5,1,2,2,2,2,2,5,0};
        U32 const column[4] = {0x11111111, 0x22222222, 0x44444444, 0x88888888};
        U32 const row[8] = {0x0000000f, 0x000000f0, 0x00000f00, 0x0000f000, 0x000f0000, 0x00f00000, 0x0f000000, 0xf0000000};
        U32 const pMove[32] ={0x00000012, 0x00000025, 0x0000004a, 0x00000084, 0x00000121, 0x00000252, 0x000004a4, 0x00000848, 0x00001210,
        0x00002520, 0x00004a40, 0x00008480, 0x00012100, 0x00025200, 0x0004a400, 0x00084800, 0x00121000, 0x00252000, 0x004a4000, 0x00848000,
        0x01210000, 0x02520000, 0x04a40000, 0x08480000, 0x12100000, 0x25200000, 0x4a400000, 0x84800000, 0x21000000, 0x52000000, 0xa4000000, 0x48000000};

        
        int getMyColor();
        void refreshRed();
        void refreshBlack();
        void refreshOccupied();
        U32 LS1B(U32);
        U32 MS1B(U32);
};

#endif