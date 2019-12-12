#include "board.h"
using namespace std;

board::board(){}

int board::getPieceType(U32 p){ //from U32 to piecetype-i
    int i;
    for (i = 0; i < 16; i++)
    {
        if ((piece[i] != 0) & ((piece[i] | p) == piece[i]))
        {
            //printf("OK ");
            return i;
        }
    }
    printf("getIndex ERROR");
    return 111;
}
void board::initBoard(){
    piece[15] = 0xFFFFFFFF;
    // for (int i = 0; i < 16;i++){
    //     printf("%x ",piece[i]);
    // }
    // printf("\n");
    char revChess;
    int boardLine = 0;
    int srcP, destP, revP;
    U32 src, dest, rev;
    char tmp;
    FILE *board;
    char pastMove[5];
    board = fopen("board.txt", "r");
    /*if(board==NULL){
                sendFirstMove();
            }*/
    while (boardLine != (14))
    { //過濾到第14行
        fscanf(board, "%c", &tmp);
        if (tmp == '*')
        {
            boardLine++;
        }
    }
    while (1)
    {
        fscanf(board, "%c", &tmp);
        fscanf(board, "%c", &tmp);
        int i, j;
        if (tmp <= 57 & tmp >= 49)
        {

            while (tmp != ' ')
            { //skip space
                fscanf(board, "%c", &tmp);
            }
            for (i = 0; i < 5; i++)
            { //get pastMoves

                fscanf(board, "%c", &tmp);
                pastMove[i] = tmp;
            }

            if (pastMove[2] == '-')
            { //change data

                srcP = pastMove[0] - 96 + (pastMove[1] - 49) * 4;
                destP = pastMove[3] - 96 + (pastMove[4] - 49) * 4;
                src = IntToU32(srcP);
                dest = IntToU32(destP);
                for (i = 0; i < 16; i++)
                {
                    if ((piece[i] != 0) & ((piece[i] | src) == piece[i]))
                    {
                        //printf("i=%d\n",i);
                        piece[i] = piece[i] ^ src;
                        //printf("piece=%d\n", piece[i]);
                        piece[0] = piece[0] | src;
                        //printf("[0]=%d\n", piece[0]);
                        for (j = 0; j < 16; j++)
                        {
                            if ((piece[j] != 0) & ((piece[j] | dest) == piece[j]))
                            {
                                //printf("j=%d\n", j);
                                piece[j] = piece[j] ^ dest;
                            }
                        }
                        piece[i] = piece[i] | dest;
                    }
                }
            }
            else
            {
                revP = pastMove[0] - 96 + (pastMove[1] - 49) * 4;
                rev = IntToU32(revP);
                piece[15] = piece[15] ^ rev;
                revChess = pastMove[3];
                i = 0;
                switch (revChess)
                {
                case 'K':
                    i = 1;
                    break;
                case 'G':
                    i = 2;
                    break;
                case 'M':
                    i = 3;
                    break;
                case 'R':
                    i = 4;
                    break;
                case 'N':
                    i = 5;
                    break;
                case 'C':
                    i = 6;
                    break;
                case 'P':
                    i = 7;
                    break;
                case 'k':
                    i = 8;
                    break;
                case 'g':
                    i = 9;
                    break;
                case 'm':
                    i = 10;
                    break;
                case 'r':
                    i = 11;
                    break;
                case 'n':
                    i = 12;
                    break;
                case 'c':
                    i = 13;
                    break;
                case 'p':
                    i = 14;
                    break;
                }
                piece[i] = piece[i] | rev;
                numUnrevealPiece[i]--;
                //printf("i=%d,revP=%d,rev=%x,piece=%x\n",i,revP,rev,piece[i]);
            }
            while (tmp != ' ')
            { //skip space
                fscanf(board, "%c", &tmp);
            }

            for (i = 0; i < 5; i++)
            { //get pastMoves

                fscanf(board, "%c", &tmp);
                pastMove[i] = tmp;
            }

            if (pastMove[2] == '-')
            { //change data

                srcP = pastMove[0] - 96 + (pastMove[1] - 49) * 4;
                destP = pastMove[3] - 96 + (pastMove[4] - 49) * 4;
                src = IntToU32(srcP);
                dest = IntToU32(destP);
                for (i = 0; i < 16; i++)
                {
                    if ((piece[i] != 0) & ((piece[i] | src) == piece[i]))
                    {
                        //printf("i=%d\n",i);
                        piece[i] = piece[i] ^ src;
                        //printf("piece=%d\n", piece[i]);
                        piece[0] = piece[0] | src;
                        //printf("[0]=%d\n", piece[0]);
                        for (j = 0; j < 16; j++)
                        {
                            if ((piece[j] != 0) & ((piece[j] | dest) == piece[j]))
                            {
                                //printf("j=%d\n", j);
                                piece[j] = piece[j] ^ dest;
                            }
                        }
                        piece[i] = piece[i] | dest;
                    }
                }
            }
            else if (pastMove[2] == '(')
            {
                revP = pastMove[0] - 96 + (pastMove[1] - 49) * 4;
                rev = IntToU32(revP);
                piece[15] = piece[15] ^ rev;
                revChess = pastMove[3];
                i = 0;
                switch (revChess)
                {
                case 'K':
                    i = 1;
                    break;
                case 'G':
                    i = 2;
                    break;
                case 'M':
                    i = 3;
                    break;
                case 'R':
                    i = 4;
                    break;
                case 'N':
                    i = 5;
                    break;
                case 'C':
                    i = 6;
                    break;
                case 'P':
                    i = 7;
                    break;
                case 'k':
                    i = 8;
                    break;
                case 'g':
                    i = 9;
                    break;
                case 'm':
                    i = 10;
                    break;
                case 'r':
                    i = 11;
                    break;
                case 'n':
                    i = 12;
                    break;
                case 'c':
                    i = 13;
                    break;
                case 'p':
                    i = 14;
                    break;
                }
                piece[i] = piece[i] | rev;
                numUnrevealPiece[i]--;
                //printf("i=%d,revP=%d,rev=%x,piece=%x\n",i,revP,rev,piece[i]);
            }
            else
                break;
            while (tmp != '*')
            { //skip to *
                fscanf(board, "%c", &tmp);
            }
        }
        else
            break;
    }
    fclose(board);
    refreshBlack();
    refreshOccupied();
    refreshRed();
    scoreBoard();
}
void board::printBoard(){
    int a, b, p, c;
    U32 s;
    for (a = 7; a >= 0; a--)
    {
        for (b = 1; b < 5; b++)
        {
            p = 4 * a + b;
            //printf("p = %d\n",p);
            s = IntToU32(p);
            //printf("s = %x\n",s);
            for (c = 0; c < 16; c++)
            {
                if (((piece[c] | s) == piece[c]) & (piece[c] != 0))
                {

                    switch (c)
                    {
                    case 0:
                        printf("- ");
                        break;
                    case 1:
                        printf("K ");
                        break;
                    case 2:
                        printf("G ");
                        break;
                    case 3:
                        printf("M ");
                        break;
                    case 4:
                        printf("R ");
                        break;
                    case 5:
                        printf("N ");
                        break;
                    case 6:
                        printf("C ");
                        break;
                    case 7:
                        printf("P ");
                        break;
                    case 8:
                        printf("k ");
                        break;
                    case 9:
                        printf("g ");
                        break;
                    case 10:
                        printf("m ");
                        break;
                    case 11:
                        printf("r ");
                        break;
                    case 12:
                        printf("n ");
                        break;
                    case 13:
                        printf("c ");
                        break;
                    case 14:
                        printf("p ");
                        break;
                    case 15:
                        printf("X ");
                        break;
                    default:
                        printf("?");
                    }
                    //printf("s=%x c=%d piece=%x\n", s, c,piece[c]);
                }
            }
        }
        printf("\n");
    }
}
U32 board::generateCMove(U32 u32Src){ //回傳src可以到達的炮位(不分黑紅)
    int intSrc = U32ToInt(u32Src);
    int r = intSrc / 4, c = intSrc % 4;
    U32 dest = 0, dest1 = 0;
    U32 x = ((row[r] & occupied) ^ (1 << intSrc)) >> (4 * r);
    U32 y = ((column[c] & occupied) ^ (1 << intSrc)) >> c;
    //printf("r=%d,c=%d\n",r,c);
    //printf("src:%x\n",u32Src);
    //printf("x:%x,y:%x\n",x,y);
    //printf("Generate Canno:\n");
    if (x)
    {
        if (c == 0)
        {
            U32 mask = LS1B(x);
            dest = dest | LS1B(x ^= mask);
        }
        if (c == 1)
        {
            dest = dest | (((x & 12) == 12) ? 8 : 0);
        }
        if (c == 2)
        {
            dest = dest | (((x & 3) == 3) ? 1 : 0);
        }
        if (c == 3)
        {
            U32 mask1 = MS1B(x);
            dest = dest | MS1B(x ^= mask1);
        }
    }
    dest = dest << (4 * r);
    //printf("dest:%x\n",dest);
    if (y)
    {
        if (r == 0)
        {
            U32 y1 = y & 0x11111110;
            U32 mask = LS1B(y1);
            dest1 = dest1 | LS1B(y1 ^= mask);
        }
        if (r == 1)
        {
            U32 y1 = y & 0x11111100;
            U32 mask = LS1B(y1);
            dest1 = dest1 | LS1B(y1 ^= mask);
        }
        if (r == 2)
        {
            U32 y1 = y & 0x11111000;
            U32 mask = LS1B(y1);
            dest1 = dest1 | LS1B(y1 ^= mask);
            U32 y2 = y & 0x00000011;
            U32 mask1 = MS1B(y2);
            dest1 = dest1 | MS1B(y2 ^= mask1);
        }
        if (r == 3)
        {
            U32 y1 = y & 0x11110000;
            U32 mask = LS1B(y1);
            dest1 = dest1 | LS1B(y1 ^= mask);
            U32 y2 = y & 0x00000111;
            U32 mask1 = MS1B(y2);
            dest1 = dest1 | MS1B(y2 ^= mask1);
        }
        if (r == 4)
        {
            U32 y1 = y & 0x11100000;
            U32 mask = LS1B(y1);
            dest1 = dest1 | LS1B(y1 ^= mask);
            U32 y2 = y & 0x00001111;
            U32 mask1 = MS1B(y2);
            dest1 = dest1 | MS1B(y2 ^= mask1);
        }
        if (r == 5)
        {
            U32 y1 = y & 0x11000000;
            U32 mask = LS1B(y1);
            dest1 = dest1 | LS1B(y1 ^= mask);
            U32 y2 = y & 0x00011111;
            U32 mask1 = MS1B(y2);
            dest1 = dest1 | MS1B(y2 ^= mask1);
        }
        if (r == 6)
        {
            U32 y2 = y & 0x00111111;
            U32 mask1 = MS1B(y2);
            //printf("y2:%x,mask1:%x\n",y,mask1);
            dest1 = dest1 | MS1B(y2 ^= mask1);
        }
        if (r == 7)
        {
            U32 y2 = y & 0x01111111;
            U32 mask1 = MS1B(y2);
            dest1 = dest1 | MS1B(y2 ^= mask1);
        }
    }
    dest1 = dest1 << c;
    //printf("dest1:%x\n",dest1);
    return (dest | dest1);
}
void board::generateEatMove(){
    U32 dest;
    //printf("GenerateEat:\n");
    if (Myplayer.playerColor == 0)
    {
        for (int i = 1; i < 8; i++)
        {
            U32 p = piece[i];
            while (p > 0)
            {
                U32 mask = LS1B(p);
                //printf("i:%d mask:%x\n",i,mask);
                p ^= mask;
                U32 src = U32ToInt(mask);
                if (i == 1)
                {
                    dest = pMove[src] & (black ^ piece[14]);
                    //printf("%d\n",i);
                }
                else if (i == 2)
                {
                    dest = pMove[src] & (black ^ piece[8]);
                    // printf("i:%d,mask:%x,src:%d\n",i,mask,src);
                }
                else if (i == 3)
                {
                    dest = pMove[src] & (black ^ piece[8] ^ piece[9]);
                    //printf("i:%d,src:%d\n",i,src);
                }
                else if (i == 4)
                {
                    dest = pMove[src] & (piece[11] | piece[12] | piece[13] | piece[14]);
                    //printf("i:%d,src:%d\n",i,src);
                }
                else if (i == 5)
                {
                    dest = pMove[src] & (piece[12] | piece[13] | piece[14]);
                    //printf("i:%d,src:%d\n",i,src);
                }
                else if (i == 6)
                {

                    dest = generateCMove(mask) & black;
                }
                else if (i == 7)
                {
                    dest = pMove[src] & (piece[8] | piece[14]);
                }
                else
                {
                    dest = 0;
                }
                //printf("%x\n",dest);
                while (dest > 0)
                {
                    string result("\0");
                    U32 mask2 = LS1B(dest);
                    dest ^= mask2;
                    result.append(U32ToString(mask));
                    result.append(1, '-');
                    result.append(U32ToString(mask2));
                    boardMove.eatMove.push_back(result);
                    boardMove.allMove.push_back(result);
                    //cout <<result << endl;
                    //cout<<allMoves.at(0)<< endl;
                    eat = 1;
                }
            }
        }
    }
    else if (Myplayer.playerColor == 1)
    {
        for (int i = 8; i < 15; i++)
        {
            U32 p = piece[i];
            while (p > 0)
            {
                U32 mask = LS1B(p);
                p ^= mask;
                U32 src = U32ToInt(mask);
                if (i == 8)
                    dest = pMove[src] & (red ^ piece[7]);
                else if (i == 9)
                    dest = pMove[src] & (red ^ piece[1]);
                else if (i == 10)
                    dest = pMove[src] & (red ^ piece[1] ^ piece[1]);
                else if (i == 11)
                    dest = pMove[src] & (piece[4] | piece[5] | piece[6] | piece[7]);

                else if (i == 12)
                {
                    dest = pMove[src] & (piece[5] | piece[6] | piece[7]);
                    //printf("p=%llu,src=%llu,dest=%llu\n",p,src,dest);
                }

                else if (i == 13)
                {
                    dest = generateCMove(mask) & red;
                }
                else if (i == 14)
                    dest = pMove[src] & (piece[1] | piece[7]);
                else
                    dest = 0;

                while (dest > 0)
                {
                    printf("i=%d,red=%x,piece[1]=%x\n", i, red, piece[1]);
                    string result("\0");
                    U32 mask2 = LS1B(dest);
                    dest ^= mask2;
                    result.append(U32ToString(mask));
                    result.append(1, '-');
                    result.append(U32ToString(mask2));
                    boardMove.eatMove.push_back(result);
                    boardMove.allMove.push_back(result);
                    //cout << result << endl;
                    eat = 1;
                }
            }
        }
    }

    // printf("---------\n");
}
void board::generateSpeardMove(){

    U32 src, dest;
    //printf("GenerateSpeard:\n");
    for (int i = 1; i < 15; i++)
    {
        U32 p = piece[i];
        while (p)
        {
            U32 mask = LS1B(p);
            p ^= mask;
            src = U32ToInt(mask);
            dest = pMove[src] & piece[0];
            while (dest)
            {
                //printf("i=%d ",i);///////////////////
                string result("\0");
                U32 mask2 = LS1B(dest);
                dest ^= mask2;
                result.append(U32ToString(mask));
                result.append(1, '-');
                result.append(U32ToString(mask2));
                boardMove.spreadMove.push_back(result);
                boardMove.allMove.push_back(result);
                //cout << result << endl;
            }
            //printf("\n");//////////////////////////
        }
    }
}
void board::generateRevealMove(){
    U32 reveal = piece[15];
    U32 mask;
    //printf("GenerateReveal:\n");
    while (reveal > 0)
    {
        string result("\0");
        mask = LS1B(reveal);
        reveal ^= mask;
        result.append("R(");
        result.append(U32ToString(mask));
        result.append(")");
        boardMove.reveal.push_back(result);
        boardMove.allMove.push_back(result);
        //cout << result << endl;
    }
}
void board::generateAllMove(){
    generateEatMove();
    generateSpeardMove();
    generateRevealMove();
}
void board::simulateBoard(){ //產生move 產生possibility //generateAllMove() =>  move轉possibility
    //initBoard();
    // for (int i = 0; i < 16; i++){
    //     printf("%x ",piece[i]);
    // }
    //printf("\n-------------------------------------------------------------------------------------------\n");
    generateAllMove();
    string simMove;
    //cout <<"moves size="<<boardMove.allMove.size() << endl;//////////////////////////
    for (int k = 0; k < boardMove.allMove.size(); k++)
    {
        simMove = boardMove.allMove[k];
        //cout << simMove << endl;///////////////////////////
        if (simMove[2] == '-')
        {
            board simBoard;
            for (int i = 0; i < 16; i++)
            {
                simBoard.piece[i] = piece[i];
            }
            int srcP = simMove[0] - 96 + (simMove[1] - 49) * 4;
            int destP = simMove[3] - 96 + (simMove[4] - 49) * 4;
            //printf("srcP=%d,destP=%d\n",srcP,destP);
            U32 src = IntToU32(srcP);
            U32 dest = IntToU32(destP);
            for (int i = 0; i < 16; i++)
            {
                if ((simBoard.piece[i] != 0) & ((simBoard.piece[i] | src) == simBoard.piece[i]))
                {
                    //printf("i=%d\n",i);
                    simBoard.piece[i] = simBoard.piece[i] ^ src;
                    //printf("simBoard.piece[%d]=%x\n",i, simBoard.piece[i]);
                    simBoard.piece[0] = simBoard.piece[0] | src;
                    //printf("[0]=%x\n", simBoard.piece[0]);
                    for (int j = 0; j < 16; j++)
                    {
                        if ((simBoard.piece[j] != 0) & ((simBoard.piece[j] | dest) == simBoard.piece[j]))
                        {
                            //printf("j=%d\n", j);
                            simBoard.piece[j] = simBoard.piece[j] ^ dest;
                        }
                    }
                    simBoard.piece[i] = simBoard.piece[i] | dest;
                    //printf("src=%x,dest=%x,simBoard.piece[%d]=%x\n",src,dest,i, simBoard.piece[i]);
                }
            }
            //simBoard.scoreBoard();
            //cout << simMove << endl;
            //cout << "score= " << simBoard.thisScore.boardScore << endl;
            possibility.push_back(simBoard);
        }
        else
        {
            int revP = simMove[2] - 96 + (simMove[3] - 49) * 4;
            U32 rev = IntToU32(revP);
            //printf("rev=%x\n",rev);////////////////////////////////
            for (int a = 1; a < 15; a++)
            {
                if (numUnrevealPiece[a] != 0)
                { //此棋種還有位翻開的棋
                    board simBoard;
                    for (int i = 0; i < 16; i++)
                    {
                        simBoard.piece[i] = piece[i];
                    }
                    simBoard.piece[15] = simBoard.piece[15] ^ rev;
                    simBoard.piece[a] = simBoard.piece[a] | rev;
                    //simBoard.scoreBoard();
                    //cout << "score= " << simBoard.thisScore.boardScore << endl;
                    possibility.push_back(simBoard);
                }
            }
        }
        // for (int i = 0; i < 16;i++){//////////////////////////////////////
        //     printf("%x ",simBoard.piece[i]);
        // }
        // cout << endl;
    }
}
int board::pieceCount(int i){
    int count = 0;
    U32 p = piece[i];
    while (p)
    {
        p = p ^ LS1B(p);
        count++;
    }
    return count;
}
int board::scoreBoard(){
    int score = 0;
    // cout << "start score=" << thisScore.boardScore << endl;
    if (Myplayer.playerColor == 0)
    {
        for (int i = 0; i < 16; i++)
        {
            switch (i)
            {
            case 1:
                score += (7 * pieceCount(i));
                break;
            case 2:
                score += (6 * pieceCount(i));
                break;
            case 3:
                score += (5 * pieceCount(i));
                break;
            case 4:
                score += (4 * pieceCount(i));
                break;
            case 5:
                score += (3 * pieceCount(i));
                break;
            case 6:
                score += (2 * pieceCount(i));
                break;
            case 7:
                score += (1 * pieceCount(i));
                break;
            }
        }
    }
    else if (Myplayer.playerColor == 1)
    {
        for (int i = 0; i < 1; i++)
        {
            switch (i)
            {
            case 8:
                score += (7 * pieceCount(i));
                break;
            case 9:
                score += (6 * pieceCount(i));
                break;
            case 10:
                score += (5 * pieceCount(i));
                break;
            case 11:
                score += (4 * pieceCount(i));
                break;
            case 12:
                score += (3 * pieceCount(i));
                break;
            case 13:
                score += (2 * pieceCount(i));
                break;
            case 14:
                score += (1 * pieceCount(i));
                break;
            }
        }
    }
    return score;
}
const board &board::operator=(board b){
    for (int i = 0; i < 16;i++){
        piece[i] = b.piece[i];
        numUnrevealPiece[i] = b.numUnrevealPiece[i];
    }
    red = b.red;
    black = b.black;
    occupied = b.occupied;
    boardMove = b.boardMove;
    for (int i = 0; i < possibility.size();i++){
        possibility[i] = b.possibility[i];
    }
    eat = b.eat;
    Myplayer = b.Myplayer;
    return *this;
};
void board::printAll(){
    cout << "piece=";
    for (int i = 0; i < 16;i++){
        printf("%x ",piece[i]);
    }
    printf("\n");
    printf("red=%x black=%x occupied=%x\n",red,black,occupied);
    for (int i = 0; i < boardMove.allMove.size();i++){
        cout << boardMove.allMove[i]<<" ";
    }
    cout << endl;
    printBoard();
}


int board::getMyColor(){
    return Myplayer.playerColor;
}
void board::refreshRed(){
    int j;
    for (j = 1; j < 8; j++)
    {
        red = red | piece[j];
    }
}
void board::refreshBlack(){
    int j;
    for (j = 8; j < 15; j++)
    {
        black = black | piece[j];
    }
}
void board::refreshOccupied(){
    int j;
    for (j = 1; j < 16; j++)
    {
        occupied = occupied | piece[j];
    }
}
U32 board::LS1B(U32 x){
    return x & (-x);
}
U32 board::MS1B(U32 x){
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    //x |= (x >> 32);
    return (x >> 1) + 1;
}
