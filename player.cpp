#include"player.h"

        int getFirstColor(){         //紅先0黑先1
            FILE *board;
            board = fopen("board.txt","r");
            int boardLine = 0;
            int count=0;
            char tmp = '\0';
            while(boardLine!=14){                           //過濾到第12行
                fscanf(board,"%c",&tmp);
                if(tmp =='*'){
                    boardLine++;
                }
            }
            while(count!=8){
                fscanf(board,"%c",&tmp);
                count++;
            }
            //printf("%c\n",tmp);
            if(tmp>=65&tmp<=90){
                return 0;
            }
            else if(tmp>=97&tmp<=122){
                return 1;
            }
            else{
                printf("getFirstColor Error\n");
                return 2;
            }
        }
        int getFirst(){       //me first=1, not me first=0 ????????????????????????????????????????????
            int boardLine = 0,count=0;
            char tmp='\0';
            FILE *board;
            board = fopen("board.txt","r");
            //printf("GetFirst():");
            while(boardLine!=14){                           //過濾到第14行????????????????????????????????????????????  
                fscanf(board,"%c",&tmp);
                //printf("%d",boardLine);
                if(tmp =='*'){
                    boardLine++;    
                }
            }
            //printf("\n");
            while(1){           
                while(tmp!=32){           
                    fscanf(board,"%c",&tmp);
                }
                fscanf(board,"%c",&tmp);
                    
                if(tmp<=57&tmp>=49){
                    while(tmp!=32){
                        fscanf(board,"%c",&tmp);
                        }           
                    count = 1;         
                    while (tmp != '\n'){
                        fscanf(board, "%c", &tmp);
                        count++;
                        //printf("%d\n",count);
                    }
                    //printf("\n");
                }
                else{
                    break;
                }
            }
            
            fclose(board);
            if(count==7){
                return 0;
            }
            if(count==13){
                return 1;
            }
            else
                printf("getFirst ERROR");
                return 2;
        }
        int getMyColor(){               //紅0 黑1
            int firstColor = getFirstColor();
            int mefirst = getFirst();
            //printf("first color:%d\n",firstColor);
            //printf("first:%d\n",mefirst);
            //printf("??????\n");
            if(mefirst==1){
                //printf("one");
                return firstColor;
            }
            else if(mefirst==0){
                //printf("two");
                return !firstColor;
            }
            else{
                printf("MYCOLOR ERROR");
                return 2;
            }
        }
        int playerColor = getMyColor();
        int first = getFirst();
