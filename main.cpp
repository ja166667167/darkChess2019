#include<istream>
#include<cstdio>
#include"ABV1.h"
using namespace std;

int main(){
    treeNode *root=new treeNode();
    root->nodeBoard.initBoard();
    cout << "Original board:" << endl;
    root->nodeBoard.printAll();
    int result =0;
    result = maxNode(root, -100, 100);
    printf("retrun =%d",result);
    return 0;
}