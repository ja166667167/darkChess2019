#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include"player.h"
#include"U32.h"

using namespace std;
typedef unsigned int U32;

class board{
      public:
        U32 piece[16]={0};
        U32 red, black, occupied;
        vector<string> allMoves;
        int eat = 0;


        int getPieceType(U32 p){    //from U32 to piecetype-i
            int i;
            for (i = 0; i < 16;i++){
                if((piece[i]!=0)&((piece[i]|p)==piece[i])){
                    //printf("OK ");
                return i;
                }
            }
            printf("getIndex ERROR");
            return 111;
        }
        void initBoard(){
            piece[15] = 0xFFFFFFFF;
            char revChess;
            int boardLine = 0;
            int src, dest, rev,srcP,destP,revP;
            char tmp;
            FILE *board;
            char pastMove[5];
            board = fopen("board.txt","r");
            /*if(board==NULL){
                sendFirstMove();
            }*/
            while(boardLine!=(14)){                           //過濾到第14行
                fscanf(board,"%c",&tmp);
                if(tmp =='*'){
                    boardLine++;
                }
            }
            while(1){
                fscanf(board,"%c",&tmp);
                fscanf(board,"%c",&tmp);
                int i,j;
                if(tmp<=57&tmp>=49){
                    
                    while(tmp!=' '){                //skip space
                        fscanf(board,"%c",&tmp);
                    }
                    for (i = 0; i < 5;i++){         //get pastMoves
                        
                        fscanf(board,"%c",&tmp);
                        pastMove[i]=tmp;
                    }

                    if(pastMove[2]=='-'){           //change data

                        srcP = pastMove[0] - 97 + (pastMove[1] - 49) * 4;
                        destP = pastMove[3] - 97 + (pastMove[4] - 49) * 4;
                        src = pow(2, srcP);
                        dest = pow(2,destP);
                        for (i = 0; i < 16;i++){
                            if((piece[i]!=0)&((piece[i]|src)==piece[i])){
                                //printf("i=%d\n",i);                        
                                piece[i]=piece[i]^src;         
                                //printf("piece=%d\n", piece[i]);
                                piece[0] = piece[0] | src;
                                //printf("[0]=%d\n", piece[0]);
                                for (j = 0; j < 16;j++){
                                    if((piece[j]!=0)&((piece[j]|dest)==piece[j])){
                                        //printf("j=%d\n", j);
                                        piece[j] = piece[j] ^ dest;
                                        }
                                }
                                piece[i] = piece[i]|dest;                               
                            }
                        }
                    }
                    else{
                    revP = pastMove[0] - 97 + (pastMove[1] - 49) * 4;
                    rev = pow(2, revP);
                    piece[15] = piece[15] ^ rev;
                    revChess = pastMove[3];
                    i = 0;
                    switch(revChess){
                        case 'K':
                            i = 1;break;
                        case 'G':
                            i = 2;break;
                        case 'M':
                            i = 3;break;
                        case 'R':
                            i = 4;break;
                        case 'N':
                            i = 5;break;
                        case 'C':
                            i = 6;break;
                        case 'P':
                            i = 7;break;
                        case 'k':
                            i = 8;break;
                        case 'g':
                            i = 9;break;
                        case 'm':
                            i = 10; break;
                        case 'r':
                            i = 11; break;
                        case 'n':
                            i = 12; break;
                        case 'c':
                            i = 13; break;
                        case 'p':
                            i = 14; break;
                    }
                    piece[i] =piece[i]|rev;
                
                    }
                    while(tmp!=' '){                //skip space
                        fscanf(board,"%c",&tmp);
                    }

                    for (i = 0; i < 5;i++){         //get pastMoves
                        
                        fscanf(board,"%c",&tmp);
                        pastMove[i]=tmp;
                    }

                    if(pastMove[2]=='-'){           //change data

                        srcP = pastMove[0] - 97 + (pastMove[1] - 49) * 4;
                        destP = pastMove[3] - 97 + (pastMove[4] - 49) * 4;
                        src = pow(2, srcP);
                        dest = pow(2,destP);
                        for (i = 0; i < 16;i++){
                            if((piece[i]!=0)&((piece[i]|src)==piece[i])){
                                //printf("i=%d\n",i);                        
                                piece[i]=piece[i]^src;         
                                //printf("piece=%d\n", piece[i]);
                                piece[0] = piece[0] | src;
                                //printf("[0]=%d\n", piece[0]);
                                for (j = 0; j < 16;j++){
                                    if((piece[j]!=0)&((piece[j]|dest)==piece[j])){
                                        //printf("j=%d\n", j);
                                        piece[j] = piece[j] ^ dest;
                                        }
                                }
                                piece[i] = piece[i]|dest;                               
                            }
                        }
                    }
                    else if(pastMove[2]=='('){
                    revP = pastMove[0] - 97 + (pastMove[1] - 49) * 4;
                    rev = pow(2, revP);
                    piece[15] = piece[15] ^ rev;
                    revChess = pastMove[3];
                    i = 0;
                    switch(revChess){
                        case 'K':
                            i = 1;break;
                        case 'G':
                            i = 2;break;
                        case 'M':
                            i = 3;break;
                        case 'R':
                            i = 4;break;
                        case 'N':
                            i = 5;break;
                        case 'C':
                            i = 6;break;
                        case 'P':
                            i = 7;break;
                        case 'k':
                            i = 8;break;
                        case 'g':
                            i = 9;break;
                        case 'm':
                            i = 10; break;
                        case 'r':
                            i = 11; break;
                        case 'n':
                            i = 12; break;
                        case 'c':
                            i = 13; break;
                        case 'p':
                            i = 14; break;
                    }
                        piece[i] =piece[i]|rev;        
                    }
                    else
                        break;
                    while(tmp!='*'){                //skip to *
                        fscanf(board,"%c",&tmp);
                    }
                }
                else
                    break;

            }
            fclose(board);
            refreshBlack();
            refreshOccupied();
            refreshRed();
        }
        void printBoard(){
            int a,b,p,c;
            U32 s;
            for (a = 7; a >= 0;a--){
                for (b = 1; b < 5;b++){
                    p = 4*a+b;
                //printf("p = %d\n",p);
                    s=pow(2,p-1);
                    //printf("s = %x\n",s);
                    for (c = 0; c < 16;c++){
                        if(((piece[c]|s)==piece[c])&(piece[c]!=0)){
                            //printf("s=%d c=%d piece=%d\n", s, c,piece[c]);
                            switch(c){
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
                        }
                    }
                }
                printf("\n");
            }
        }

        U32 generateCMove(U32 u32Src){      //回傳src可以到達的炮位(不分黑紅)
            int intSrc = U32ToInt(u32Src);
            int r=intSrc/4, c=intSrc%4;
            U32 dest=0,dest1=0;
            U32 x = ((row[r] & occupied) ^ (1 << intSrc))>>(4 * r);
            U32 y = ((column[c] & occupied) ^ (1 << intSrc))>>c;
            //printf("r=%d,c=%d\n",r,c);
            //printf("src:%x\n",u32Src);
            //printf("x:%x,y:%x\n",x,y);
            //printf("Generate Canno:\n");
            if(x){
                if(c==0){
                    U32 mask = LS1B(x);
                    dest = dest|LS1B(x ^= mask);
                }
                if(c==1){
                    dest = dest|(((x & 12) == 12) ? 8 : 0); 
                }
                if(c==2){
                    dest = dest|(((x & 3) == 3) ? 1 : 0);
                }
                if(c==3){
                    U32 mask1 = MS1B(x);
                    dest = dest|MS1B(x ^= mask1);
                }
            }
            dest=dest << (4*r);
            //printf("dest:%x\n",dest);
            if(y){
                if(r==0){
                    U32 y1 = y & 0x11111110;
                    U32 mask = LS1B(y1);
                    dest1 = dest1 | LS1B(y1^=mask);
                }
                if(r==1){
                    U32 y1 = y & 0x11111100;
                    U32 mask = LS1B(y1);
                    dest1 = dest1 | LS1B(y1^=mask);
                }
                if(r==2){
                    U32 y1 = y & 0x11111000;
                    U32 mask = LS1B(y1);
                    dest1 = dest1 | LS1B(y1^=mask);
                    U32 y2 = y & 0x00000011;
                    U32 mask1 = MS1B(y2);
                    dest1 = dest1 | MS1B(y2^=mask1);
                }
                if(r==3){
                    U32 y1 = y & 0x11110000;
                    U32 mask = LS1B(y1);
                    dest1 = dest1 | LS1B(y1^=mask);
                    U32 y2 = y & 0x00000111;
                    U32 mask1 = MS1B(y2);
                    dest1 = dest1 | MS1B(y2^=mask1);
                }
                if(r==4){
                    U32 y1 = y & 0x11100000;
                    U32 mask = LS1B(y1);
                    dest1 = dest1 | LS1B(y1^=mask);
                    U32 y2 = y & 0x00001111;
                    U32 mask1 = MS1B(y2);
                    dest1 = dest1 | MS1B(y2^=mask1);
                }
                if(r==5){
                    U32 y1 = y & 0x11000000;
                    U32 mask = LS1B(y1);
                    dest1 = dest1 | LS1B(y1^=mask);
                    U32 y2 = y & 0x00011111;
                    U32 mask1 = MS1B(y2);
                    dest1 = dest1 | MS1B(y2^=mask1);
                }
                if(r==6){
                    U32 y2 = y & 0x00111111;
                    U32 mask1 = MS1B(y2);
                    //printf("y2:%x,mask1:%x\n",y,mask1);
                    dest1 = dest1 | MS1B(y2^=mask1);
                }
                if(r==7){
                    U32 y2 = y & 0x01111111;
                    U32 mask1 = MS1B(y2);
                    dest1 = dest1 | MS1B(y2^=mask1);
                }
            }
            dest1 = dest1<< c;
            //printf("dest1:%x\n",dest1);
            return (dest|dest1);
        }
        void generateEatMove(){   
            U32 dest;
            //printf("GenerateEat:\n");
            if(Myplayer.playerColor==0){       
                for (int i = 1; i < 8;i++){
                    U32 p = piece[i];
                    while(p>0){
                        U32 mask = LS1B(p);
                        //printf("i:%d mask:%x\n",i,mask);
                        p^=mask;
                        U32 src = U32ToInt(mask);
                        if(i==1){
                            dest = pMove[src] & (black ^ piece[14]);
                            //printf("%d\n",i);                   
                        }
                        else if(i==2){
                            dest = pMove[src] & (black ^ piece[8]);
                        // printf("i:%d,mask:%x,src:%d\n",i,mask,src);
                            
                        }
                        else if(i==3){
                            dest = pMove[src] & (black ^ piece[8]^piece[9]);
                            //printf("i:%d,src:%d\n",i,src);
                        }
                        else if(i==4){
                            dest = pMove[src] & (piece[11]|piece[12]|piece[13]|piece[14]);
                            //printf("i:%d,src:%d\n",i,src);
                        }
                        else if(i==5){
                            dest = pMove[src] & (piece[12] | piece[13] | piece[14]);
                            //printf("i:%d,src:%d\n",i,src);
                        }
                        else if(i==6){
                            
                            dest = generateCMove(mask)&black;
                        }
                        else if (i == 7){
                            dest = pMove[src] & (piece[8] | piece[14]);
                        }
                        else{
                            dest = 0;
                        }
                        //printf("%x\n",dest);
                        while(dest>0){
                            string result("\0");
                            U32 mask2 = LS1B(dest);
                            dest ^= mask2;
                            result.append(U32ToString(mask));
                            result.append(1,'-');
                            result.append(U32ToString(mask2));
                            allMoves.push_back(result);
                            //cout <<result << endl;
                            //cout<<allMoves.at(0)<< endl;
                            eat = 1;
                        }
                    }
                }
            }
            else if(Myplayer.playerColor==1){
                for (int i = 8; i < 15;i++){
                    U32 p = piece[i];
                    while(p>0){
                        U32 mask = LS1B(p);
                        p^=mask;
                        U32 src = U32ToInt(mask);
                        if(i==8)
                            dest = pMove[src] & (red ^ piece[7]);
                        else if(i==9)
                            dest = pMove[src] & (red ^ piece[1]);
                        else if(i==10)
                            dest = pMove[src] & (red ^ piece[1]^piece[1]);
                        else if(i==11)
                            dest = pMove[src] & (piece[4]|piece[5]|piece[6]|piece[7]);

                        else if(i==12){
                            dest = pMove[src] & (piece[5] | piece[6] | piece[7]);
                            //printf("p=%llu,src=%llu,dest=%llu\n",p,src,dest);
                        }

                        else if(i==13){
                            dest = generateCMove(mask)&red;
                        }
                        else if (i == 14)
                            dest = pMove[src] & (piece[1] | piece[7]);
                        else
                            dest = 0;

                        while(dest>0){
                            string result("\0");
                            U32 mask2 = LS1B(dest);
                            dest ^= mask2;
                            result.append(U32ToString(mask));
                            result.append(1,'-');
                            result.append(U32ToString(mask2));
                            allMoves.push_back(result);
                            //cout << result << endl;
                            eat = 1;
                        }
                    }
                }
            }
        }
        void generateSpeardMove(){
            int i;
            U32 src, dest;
            //printf("GenerateSpeard:\n");
            if(Myplayer.playerColor==0){       
                for (i = 1; i < 8;i++){
                    U32 p = piece[i];
                    while(p>0){
                        U32 mask = LS1B(p);
                        p^=mask;
                        src = U32ToInt(mask);
                        if(i==1){
                            dest = pMove[src] &piece[0];                 
                        }
                        else if(i==2){
                            dest = pMove[src] &piece[0];      
                        }
                        else if(i==3){
                            dest = pMove[src] &piece[0];                
                            }
                        else if(i==4){
                            dest = pMove[src] &piece[0];                
                        }
                        else if(i==5){
                            dest = pMove[src] &piece[0];                
                        }
                        else if(i==6){                    
                            dest = pMove[src] &piece[0];                
                        }
                        else if (i == 7){
                            dest = pMove[src] &piece[0];                
                        }
                        else{
                            dest = 0;
                        }
                        while(dest>0){
                            string result("\0");
                            U32 mask2 = LS1B(dest);
                            dest ^= mask2;
                            result.append(U32ToString(mask));
                            result.append(1,'-');
                            result.append(U32ToString(mask2));
                            allMoves.push_back(result);
                            //cout << result << endl;
                        }
                    }
                }
            }
            else if(Myplayer.playerColor==1){
                for (i = 8; i < 15;i++){
                    U32 p = piece[i];
                    while(p>0){
                        U32 mask = LS1B(p);
                        p^=mask;
                        src = U32ToInt(mask);
                        if(i==8){
                            dest = pMove[src] &piece[0];                 
                        }
                        else if(i==9){
                            dest = pMove[src] &piece[0];
                            
                        }
                        else if(i==10){
                            dest = pMove[src] &piece[0];                
                            }
                        else if(i==11){
                            dest = pMove[src] &piece[0];                
                        }
                        else if(i==12){
                            dest = pMove[src] &piece[0];
                            
                        }
                        else if(i==13){                    
                            dest = pMove[src] &piece[0];                
                        }
                        else if (i == 14){
                            dest = pMove[src] &piece[0];                
                        }
                        else{
                            dest = 0;
                        }
                        while(dest>0){
                            string result("\0");
                            U32 mask2 = LS1B(dest);
                            dest ^= mask2;
                            result.append(U32ToString(mask));
                            result.append(1,'-');
                            result.append(U32ToString(mask2));
                            allMoves.push_back(result);
                            //cout << result << endl;
                        }
                    }
                }
            }
        }
        void generateRevealMove(){
            U32 reveal=piece[15];
            U32 mask;
            //printf("GenerateReveal:\n");
            while(reveal>0){
                string result("\0");
                mask=LS1B(reveal);
                reveal ^=mask;
                result.append("R(");
                result.append(U32ToString(mask));
                result.append(")");
                allMoves.push_back(result);
                //cout << result << endl;
            }
        }
        void randomMove(){
            FILE *move;
            string result;
            move=fopen("move.txt","w+");
            srand(time(NULL));
            int n = rand();
            result = allMoves.at(n % allMoves.size());
            if(result[0]=='R'){
                cout << "Final Move:" << result << endl;
                fprintf(move,"1\n%c%c\n0\n",result[2],result[3]);
                fclose(move);
            }
            else{
                cout << "Final Move:" << result << endl;
                fprintf(move,"0\n%c%c\n%c%c\n",result[0],result[1],result[3],result[4]);
                fclose(move);
            }
        }


private:
    player Myplayer;
    void refreshRed(){
            int j;
            for (j = 1; j < 8;j++){
                red = red | piece[j];
            }
        }
    void refreshBlack(){
           int j;
            for (j = 8; j < 15;j++){
                black = black | piece[j];
            }
        }
    void refreshOccupied(){
            int j;
            for (j = 1; j < 16;j++){
                occupied = occupied | piece[j];
            }
        }
    U32 LS1B(U32 x){
        return x & (-x);
        }
    U32 MS1B(U32 x){
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16); 
        //x |= (x >> 32);
        return (x >>1)+1;
    }

};

