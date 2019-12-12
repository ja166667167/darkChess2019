#ifndef treeNodeh
#define treeNodeh

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include"board.h"

using namespace std;

class treeNode{
    public:
        treeNode(board);
        treeNode();
        virtual ~treeNode(){}
        board nodeBoard;
        treeNode *parent;
        vector<treeNode *> children;
};

#endif