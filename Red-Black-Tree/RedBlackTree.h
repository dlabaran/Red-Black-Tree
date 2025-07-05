#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <string>
#include <iostream>
using namespace std;
#define RED 1;
#define BLACK 0;

struct RBTNode{
    int data;
    unsigned short int color;
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;

};
class RedBlackTree{
    public:
        RedBlackTree();
        void Insert(int input);
        bool Contains(int target);
        void rightRotate(RBTNode *inputnode);
        void leftRotate(RBTNode *inputnode);   
        int GetMin();
        int GetMax();
        int Size();
        void addAsLeaf(RBTNode *leaf);
        void rotateAndRecolor(RBTNode *inputnode);
        string ToInfixString() const {return ToInfixString(root);};
        string ToPrefixString() const { return ToPrefixString(root);};
        string ToPostfixString() const { return ToPostfixString(root);};

    private:
        unsigned long long int numItems= 0;
        RBTNode *root= nullptr;
        string ToInfixString(RBTNode *inputnode) const;
        string ToPrefixString(RBTNode *inputnode) const;
        string ToPostfixString(RBTNode *inputnode) const;
};






#endif