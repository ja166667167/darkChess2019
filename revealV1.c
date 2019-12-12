#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned int U32;
U32 piece[16];
U32 red, black, occupied;
FILE *board;
FILE *move;

int boardLine = 0,flag=2,spaceCut=0,spaceCount=0, plyCount=1;
int i;
char enemyMove[5];
int srcPosition, destPosition, revPosition;
char revChess;
int myColor;

void refreshRed(U32*r){
    int j;
    for (j = 1; j < 8;j++){
        *r = *r | piece[j];
    }
}
void refreshBlack(U32*b){
    int j;
    for (j = 8; j < 15;j++){
       *b = *b | piece[j];

    }
}
void refreshOccupied(U32*o){
    int j;
    for (j = 1; j < 16;j++){
        *o = *o | piece[j];
    }
}

void generateMove(){

}

int main(){
    board = fopen("board.txt","r");

    boardLine = 0;
    char tmp='\0', tmpp;

    while(boardLine!=12){                           //過濾到第12行
        fscanf(board,"%c",&tmp);
        if(tmp =='*'){
            boardLine++;
        }
    }
    while(1){
        fscanf(board,"%c",&tmp);
        if(tmp=='\n'){
            break;
        }
        tmpp = tmp;  
    }
    flag = tmpp - 48;                              //算出先後手
    if(flag==1){                                    //先first==1
        spaceCut = 2;
    }
    else if(flag==0){                               //後first==0
        spaceCut = 1;
       while(boardLine!=14){                        //過濾到第14行 抓對手顏色
            fscanf(board,"%c",&tmp);
            if(tmp =='*'){
                boardLine++;
            }
        }
        for (i = 0; i < 7;i++){                     //去掉7個字元
            fscanf(board,"%c",&tmp);
        }
        fscanf(board,"%c",&tmp);
        if(tmp>=65&tmp<=90)                         //若為大寫則我方為黑(myColor=1)
            myColor = 1;
        else
            myColor = 0;
    }
    else{
        printf("Flag ERROR!!!!!!!!!!!!!!!!!");
    }
    fclose(board);

    while(1){                                      //LOOP------------

        board = fopen("board.txt","r");
        boardLine = 0;
        while(boardLine!=(plyCount+13)){
            fscanf(board,"%c",&tmp);
            if(tmp=='*'){
                boardLine++;
            }
        }
        fscanf(board,"%c",&tmp);                    //去掉*後的空格
        fscanf(board,"%c",&tmp);                    //取空格後的值
        if(tmp!=plyCount+48){                       //檢查檔案是否更新
            break;
        }
        spaceCount = 0;
         while(spaceCount!=spaceCut){                    //跳空格
        fscanf(board,"%c",&tmp);
        if(tmp==' '){
            spaceCount++;
        }
        
        }
        for (i = 0; i < 5;i++){                         //抓enemyMove
            fscanf(board,"%c",&enemyMove[i]);
        }
        printf("%s\n",enemyMove);

//-----------------Board Change-------------------

        if(enemyMove[2]=='-'){                          //判斷是否為翻棋MOVE
            srcPosition = enemyMove[0] - 97 + (enemyMove[1] - 49) * 4;
            destPosition = enemyMove[3] - 97 + (enemyMove[4] - 49) * 4;
            int srcTmp;
            for (i = 0; i < 16;i++){
                if(srcPosition == piece[i]){
                    srcTmp = i;
                    piece[0]=piece[0]&piece[i];
                }
            }
            for (i = 0; i < 16;i++){
                if((destPosition&piece[i])==piece[i]){
                    if(i==0){
                        piece[srcTmp] = destPosition;
                        piece[0] = piece[0] ^ destPosition;
                    }
                    else{
                        piece[i] = '\0';
                        piece[srcTmp] = destPosition;
                    }
                }
            }
        }
        else{
            revPosition = enemyMove[0] - 97 + (enemyMove[1] - 49) * 4;
            piece[15] = piece[15] ^ revPosition;
            revChess = enemyMove[3];
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
            piece[i] = revPosition;
        }
        for (i = 0; i < 16;i++){
            printf("%d ", piece[i]);
        }
        
        refreshBlack(&black);
        refreshRed(&red);
        refreshOccupied(&occupied);
        generateMove();

        plyCount++;
    }

FILE *fptr;

    fptr = fopen("move.txt","w+");
    fprintf(fptr,"1\nb4\n0\n");
    fclose(fptr);

    return 0;



}