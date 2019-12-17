#include"ABV1.h"

int const depthLimit = 10;

int depthCount = 0;
int nodeCount = 0;

int maxNode(treeNode *thisNode,int alpha,int beta){
    cout << "In MaxNode " ;/////////////////////////////////////////
    cout << "depth=" << depthCount << endl;////////////////////////
    int m;
    
    if(depthLimit==depthCount){

        cout << "score="<<thisNode->nodeBoard.scoreBoard() << endl;
        depthCount--;
        return thisNode->nodeBoard.scoreBoard();
        
    }
    else{
        m = alpha;
        thisNode->nodeBoard.simulateBoard();

        thisNode->nodeBoard.possibility[0].printAll();

        for (int i = 0; i < thisNode->nodeBoard.possibility.size();i++){
            
            nodeCount++;
            treeNode *nextNode = new treeNode(thisNode->nodeBoard.possibility[i]);
            printf("max new Board i=%d\n",i);/////////////////////////////////////////
           // nextNode->nodeBoard.printAll();//////////////////////
            //cout << "OK" << endl;
            thisNode->children.push_back(nextNode);
            //cout << "OK" << endl;
            nextNode->parent = thisNode;
            //cout << "OK" << endl;
            depthCount++;
            int t = minNode(nextNode,m,beta);

            if(t>m){
                m = t;
            }
            if(m>=beta){
                cout << "beta cut,Max m=" << m << endl;//////////////////////////////////////
                return m;
            }
        }
    }
    cout << "Max m=" << m << endl;//////////////////////////////////////
    return m;
}
int minNode(treeNode *thisNode,int alpha,int beta){
    cout << "In MinNode ";/////////////////////////////////////////////
    cout << "depth=" << depthCount << endl;/////////////////////////////
    int m;
    //thisNode->nodeBoard.printBoard();
    if(depthLimit==depthCount){

        cout <<"score="<< thisNode->nodeBoard.scoreBoard() << endl;
        depthCount--;
        return thisNode->nodeBoard.scoreBoard();
    }
    else{
        
        m = beta;
        thisNode->nodeBoard.simulateBoard();
        //thisNode->nodeBoard.printBoard();

        for (int i = 0; i < thisNode->nodeBoard.possibility.size();i++){

            nodeCount++;
            treeNode *nextNode = new treeNode(thisNode->nodeBoard.possibility[i]);
            printf("min new Board i=%d\n",i);/////////////////////////////////////////
            //nextNode->nodeBoard.printAll();//////////////////////

            thisNode->children.push_back(nextNode);
            //cout << "OK" << endl;
            nextNode->parent = thisNode;
            //cout << "OK" << endl;

            depthCount++;
            int t = maxNode(nextNode,alpha,m);

            if(t<m){
                m = t;
            }
            if(m<=alpha){
                cout << "alpha cut,Min m=" << m << endl;//////////////////////////////////////
                return m;
            }
        }
    }
    cout << "Min m=" << m << endl;//////////////////////////////////////
    return m;

}
int getNodeCount(){
    return nodeCount;
}

