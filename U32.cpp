#include"U32.h"


U32 const column[4] = {0x11111111, 0x22222222, 0x44444444, 0x88888888};
U32 const row[8] = {0x0000000f, 0x000000f0, 0x00000f00, 0x0000f000, 0x000f0000, 0x00f00000, 0x0f000000, 0xf0000000};
U32 const pMove[32] ={0x00000012, 0x00000025, 0x0000004a, 0x00000084, 0x00000121, 0x00000252, 0x000004a4, 0x00000848, 0x00001210,
 0x00002520, 0x00004a40, 0x00008480, 0x00012100, 0x00025200, 0x0004a400, 0x00084800, 0x00121000, 0x00252000, 0x004a4000, 0x00848000,
0x01210000, 0x02520000, 0x04a40000, 0x08480000, 0x12100000, 0x25200000, 0x4a400000, 0x84800000, 0x21000000, 0x52000000, 0xa4000000, 0x48000000};

string U32ToString(U32 p){
    int i, j;
    string zero("00");
    string outPut;
    if(p==0x0){
        return zero;
    }
    else
        for (i = 0; i < 4;i++){
            if((column[i]|p)==column[i]){
                switch(i){
                    case 0:
                        outPut.append(1,'a');
                        break;
                    case 1:
                        outPut.append(1,'b');
                        break;
                    case 2:
                        outPut.append(1,'c');
                        break;
                    case 3:
                        outPut.append(1,'d');
                        break;
                }
            }
        }
        for (j = 0; j < 8;j++){
            if((row[j]|p)==row[j]){
                switch(j){
                    case 0:
                        outPut.append(1, '1');break;
                    case 1:
                        outPut.append(1, '2');break;
                    case 2:
                        outPut.append(1, '3');break;
                    case 3:
                        outPut.append(1, '4');break;
                    case 4:
                        outPut.append(1, '5');break;
                    case 5:
                        outPut.append(1, '6');break;
                    case 6:
                        outPut.append(1, '7');break;
                    case 7:
                        outPut.append(1, '8');break;
                }
            }
        }
    return outPut;
}
int U32ToInt(U32 p){        //0~31
    int i=0;
    while(1){
        if(p!=1){
            i++;
            p= p >> 1;
        }
        else if(p==0){
            return 0;
        }
        else
            return i;
    }
}
U32 IntToU32(int p){
    if(p==0){
        return 0;
    }
    U32 result = 0;
    result = 1 << (p-1);
    return result;
}
