
#include <string>
#include "RedBlackTree.h"
#include <iostream>
using namespace std;

RedBlackTree::RedBlackTree()
{
}

void RedBlackTree::leftRotate(RBTNode *inputnode)
{
    root = new RBTNode;
    RBTNode *temp_parent = new RBTNode; // create a pointer temp_parent to save the current parent of inputnode
    RBTNode *temp_child = new RBTNode;  // create a pointer temp_child to save to the future child of the inputnode
    
    if (inputnode->parent != nullptr)
    {
        temp_parent = inputnode->parent;
    }
    if (inputnode->right->left != nullptr)
    {
        temp_child = inputnode->right->left;
    }
    RBTNode *right_child= inputnode->right;
    right_child->left= inputnode;
    inputnode->parent= right_child;
    right_child->parent= temp_parent;
    inputnode->right=temp_child;
    
    // if (temp_parent->left == inputnode)
    // {
    //     temp_parent->left = inputnode->parent;
    // }
    // else
    // {
    //     temp_parent->right = inputnode->parent;
    // }
    root = right_child;
}
void RedBlackTree::rightRotate(RBTNode *inputnode)
{
    root = new RBTNode;
    RBTNode *temp_parent = new RBTNode;
    RBTNode *temp_child = new RBTNode;
    if (inputnode->parent != nullptr)
    {
        temp_parent = inputnode->parent;
    }
    if (inputnode->left->right != nullptr)
    {
        temp_child = inputnode->left->right;
    }

    inputnode->parent = inputnode->left;
    inputnode->left->right = inputnode;
    inputnode->left->parent = temp_parent;
    inputnode->left = temp_child;
    temp_child->parent = inputnode;
    if (temp_parent->left == inputnode)
    {
        temp_parent->left = inputnode->parent;
    }
    else
    {
        temp_parent->right = inputnode->parent;
    }
    root = inputnode->parent;
    // delete temp_child
    if (temp_child->color == 0 && temp_child->data == 0)
    {
        delete inputnode->left;
        inputnode->left = nullptr;
    }
}

bool isLeaf(RBTNode *inputnode)
{
    return !inputnode->left && !inputnode->right;
}

void RedBlackTree::addAsLeaf(RBTNode *newnode)
{
    RBTNode *curr = root;

    while (!isLeaf(curr))
    {
        if (newnode->data > curr->data)
        {
            if (curr->right != nullptr)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = newnode;
                newnode->parent = curr;
                newnode->color = RED;
                curr = curr->right;
                return;
            }
        }
        else if (newnode->data < curr->data)
        {
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = newnode;
                newnode->parent = curr;
                newnode->color = RED;
                curr = curr->left;
                return;
            }
        }
    }
    if (newnode->data > curr->data)
    {
        curr->right = newnode;
        newnode->parent = root;
        newnode->color = RED;
    }
    else if (newnode->data < curr->data)
    {
        curr->left = newnode;
        newnode->parent = curr;
        newnode->color = RED;
        return;
    }
}

// this is to rotate and recolor when certain condition are satisfied.
void RedBlackTree::rotateAndRecolor(RBTNode *leaf) //
{
    if (leaf->parent == nullptr)
    {
        leaf->color = BLACK;
        return;
    }
    if (leaf->parent->color == 0) // if the parent of the leaf node is black, theres no need for recolor, so return
    {
        return;
    }
    if (leaf->parent != nullptr)
    {
        if (leaf->parent->parent != nullptr)
        {
            RBTNode *left_uncle = leaf->parent->parent->left;
            RBTNode *right_uncle = leaf->parent->parent->right;
            if (leaf->parent->color == 1) // if the parent is not black, rotate and recolor is done based on the state of the tree.
            {
                // the parent is uncle, is black or null; perform a suitable rotation and recolor appropriately.;
                // if (leaf == leaf->parent->parent->left->left)//  right_uncle->color == 0) // if left-left, perform right rotate on the grandparent;
                // {
                leftRotate(leaf->parent->parent);
                leaf->parent->color = BLACK;
                leaf->parent->left->color = RED;
                // }
                // else if (leaf == leaf->parent->parent->right->right)// left_uncle->color == 0) // if right- right, then perform left rotate on the grandparent.
                // {
                //     leftRotate(leaf->parent->parent);
                //     leaf->parent->color = BLACK;
                //     leaf->parent->left->color = RED;
                // }
                // else if (leaf == leaf->parent->parent->left->right && right_uncle->color == 0) // if left-right , left rotate on the parent, then right rotate on the grandparent.
                // {
                //     leftRotate(leaf->parent);
                //     rightRotate(leaf->parent->parent);
                //     leaf->left->color = RED;
                //     leaf->right->color = RED;
                // }
                // else if (leaf == leaf->parent->parent->right->left && left_uncle->color == 0) // if right-left. rightrotate on the parent, left rotate on the grandparent.
                // {
                //     rightRotate(leaf->parent);
                //     leftRotate(leaf->parent->parent);
                //     leaf->left->color = RED;
                //     leaf->right->color = RED;
                // }
                // else if (leaf->parent->parent->left == leaf->parent && right_uncle->color == 1)
                // {
                //     leaf->parent->color = BLACK;
                //     right_uncle->color = BLACK;
                //     leaf->parent->parent->color = RED;
                // }
                // else if (leaf->parent->parent->right == leaf->parent && left_uncle->color == 1)
                // {
                //     leaf->parent->color = BLACK;
                //     left_uncle->color = BLACK;
                //     leaf->parent->parent->color = RED;
                // }

                // if the uncle is red
                // color both the parent and the uncle black
                // then color the grandparent red

                // recolor

                rotateAndRecolor(leaf->parent->parent);
            }
            // the function is repeated recursive with the grandparent acting as the leaf on each recursive. ends when the parent is BLACK.
        }
    }
}
void RedBlackTree::Insert(int input) // if the root is empty, insert a newnode as the root
{
    RBTNode *newnode = new RBTNode;
    newnode->data = input;
    if (root == nullptr)
    {
        root = new RBTNode;
        root->color = BLACK;
        root->data = input;
        return;
    }
    addAsLeaf(newnode); // is the root is not empty add the newnode as the leaf.

    // rotateAndRecolor(newnode);
    if (newnode->parent->parent != nullptr)
    {
        //leftRotate(newnode->parent->parent);
    }

    // numItems++;
}

bool RedBlackTree::Contains(int target) // checks to see if the tree has a node with data same as the input integer.
{
    RBTNode *curr = root;
    while (curr)
    {
        if (target > curr->data)
        {
            curr = curr->right;
        }
        else if (target < curr->data)
        {
            curr = curr->left;
        }
        else if (target == curr->data)
        {
            return true;
        }
    }
    return false;
}

int RedBlackTree::GetMin() //  returns the minimum value by reaching the leftmost leaf of the tree.
{
    RBTNode *curr = root;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr->data;
}
int RedBlackTree::GetMax() // returns the minimum value by reaching the rightmost leaf of the tree.
{
    RBTNode *curr = root;
    while (curr->right)
    {
        curr = curr->right;
    }
    return curr->data;
}

int RedBlackTree::Size() // returns the number of nodes in the tree;
{
    return numItems;
}
string giveColor(int color)
{
    if (color == 1)
    {
        return " R";
    }
    else
    {
        return " B";
    }
}
string RedBlackTree::ToInfixString(RBTNode *inputnode) const
{
    if (inputnode == nullptr)
    {
        return "";
    }
    string infix;
    infix += ToInfixString(inputnode->left);
    int data = inputnode->data;
    string color = giveColor(inputnode->color);
    infix += color + to_string(data) + " ";
    infix += ToInfixString(inputnode->right);
    return infix;
}
string RedBlackTree::ToPrefixString(RBTNode *inputnode) const
{
    if (inputnode == nullptr)
    {
        return "";
    }
    string prefix;
    int data = inputnode->data;
    string color = giveColor(inputnode->color);
    prefix += color + to_string(data) + " ";
    prefix += ToInfixString(inputnode->left);
    prefix += ToInfixString(inputnode->right);
    return prefix;
}

string RedBlackTree::ToPostfixString(RBTNode *inputnode) const
{
    if (inputnode == nullptr)
    {
        return "";
    }
    string postfix;
    postfix += ToInfixString(inputnode->left);
    postfix += ToInfixString(inputnode->right);
    int data = inputnode->data;
    string color = giveColor(inputnode->color);
    postfix += color + to_string(data) + " ";

    return postfix;
}
