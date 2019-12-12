#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned int U32;
U32 piece[16];
U32 red, black, occupied;
FILE *board;
FILE *move;

int flag=2,spaceCut=0,spaceCount=0, plyCount=0;
int i;
char enemyMove[5];
int srcPosition, destPosition, revPosition;
char revChess;


int main(){
    
    board = fopen("board.txt","r");
    move = fopen("move.txt", "w+");
    int boardLine = 0;
    char tmp='\0', tmpp;

    while(boardLine!=12){                           //過濾到第12行
        fscanf(board,"%c",&tmp);
        if(tmp =='*'){
            boardLine++;
        };
    }
    while(1){
        fscanf(board,"%c",&tmp);
        if(tmp=='\n'){
            break;
        }
        tmpp = tmp;  
    }
    flag = tmpp - 48;                              //算出先後手
    if(flag==1){
        spaceCut = 3;
    }
    else if(flag==0){
        spaceCut = 2;
    }
    else{
        printf("Flag ERROR!!!!!!!!!!!!!!!!!");
    }
    tmp = '\0';
    while(tmp!='\n'){
        fscanf(board,"%c",&tmp);                    //去掉一行
    }
    while(spaceCount!=spaceCut){                    //跳空格
        fscanf(board,"%c",&tmp);
        if(tmp==' '){
            spaceCount++;
        }
    }
    for (i = 0; i < 5;i++){                         //抓enemyMove
        fscanf(board,"%c",&enemyMove[i]);
    }
    printf("%s",enemyMove);

    if(enemyMove[2]=='-'){                          //判斷是否為翻棋MOVE
        srcPosition = enemyMove[0] - 97 + (enemyMove[1] - 48) * 4;
        destPosition = enemyMove[3] - 97 + (enemyMove[4] - 48) * 4;
    }
    else{
        revPosition = enemyMove[0] - 97 + (enemyMove[1] - 48) * 4;
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




    system("pause");
    return 0;
}