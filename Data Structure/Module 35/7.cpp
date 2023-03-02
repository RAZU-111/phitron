#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node* Left;
    node* Right;
};

class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    node* CreateNewNode(int value)
    {
        node* NewNode = new node;
        NewNode->value = value;
        NewNode->Left = NULL;
        NewNode->Right = NULL;
        return NewNode;
    }
    void Insert(int value)
    {
        node* a = CreateNewNode(value);
        if(root==NULL)
        {
            root = a;
            return;
        }
        node* cur = root;
        node* pre = NULL;
        while(cur!=NULL)
        {
            if(a->value > cur->value)
            {
                pre = cur;
                cur = cur->Right;
            }
            else
            {
                pre = cur;
                cur = cur->Left;
            }
        }
        if(a->value > pre->value)
        {
            pre->Right = a;
        }
        else
        {
            pre->Left = a;
        }
    }
    bool Search(int value)
    {
        if(root==NULL)
        {
            return false;
        }
        node* cur = root;
        while(cur!=NULL)
        {
            if(cur->value < value)
            {
                cur = cur->Right;
            }
            else if(cur->value > value)
            {
                cur = cur->Left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    BST bst;
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(25);
    bst.Insert(50);
    bst.Insert(8);
    bst.Insert(9);
    cout<<bst.Search(10)<<"\n"; //1
    cout<<bst.Search(9)<<"\n"; //1
    cout<<bst.Search(20)<<"\n"; //1
    cout<<bst.Search(60)<<"\n"; //0
    return 0;
}