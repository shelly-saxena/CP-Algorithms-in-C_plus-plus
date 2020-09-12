#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Given a Binary Search Tree (BST)
//    We will perform basic operations on BST
//    1. Insert node in BST
//    2. Delete node from BST
//
//    For reference, consider the BST given below
//
//
//                          root ->   60
//                                   /  \
//                                  /    \
//                                _/      \_
//                               /          \
//                             _/            \_
//                            /                \
//                           /                  \
//                         30                   100
//                        /  \                  /  \
//                       /    \                /    \
//                      /      \              /      \
//                     5       50            80      120
//                    /\       /\           /        / \
//                   /  \     /  \         /        /   \
//                  1   25   40  55       65       110  130
//
//
//

class Binary_Search_Tree_Node
{
public:
    ll data;
    Binary_Search_Tree_Node *left=NULL;
    Binary_Search_Tree_Node *right=NULL;
};
typedef Binary_Search_Tree_Node bst;
//*********************************************************************************************
bst* insert_in_bst(bst *root,bst *temp)
{
    if(root==NULL)  // base case
    {
        root=temp;
        return root;
    }
    if(root->data > temp->data)  // left case
    {
        if(root->left==NULL)
        {
            root->left=temp;
            return root;
        }
        root->left=insert_in_bst(root->left,temp);
    }
    else // right case
    {
        if(root->right==NULL)
        {
            root->right=temp;
            return root;
        }
        root->right=insert_in_bst(root->right,temp);
    }
    return root;
}
//*********************************************************************************************
//*********************************************************************************************

ll find_in_order_successor(bst *root)  // use when we have two children of node to be deleted
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return (root->data);
}

bst* delete_from_bst(bst *root,ll val)
{
    if(root==NULL)
    {
        cout<<val<<" is not present in given BST\n";
        return root;
    }
    if(root->data > val)  // left case
    {
        root->left=delete_from_bst(root->left,val);
    }
    else if(root->data < val)  // right case
    {
        root->right=delete_from_bst(root->right,val);
    }
    else  // value found
    {
        if(root->left==NULL)  // case of one child or  no child
        {
            bst *temp=new(bst);
            temp=root->right;
            delete(root);
            cout<<"Value deleted from BST\n";
            return temp;
        }
        else if(root->right==NULL)  // case of one child or  no child
        {
            bst *temp=new(bst);
            temp=root->left;
            delete(root);
            cout<<"Value deleted from BST\n";
            return temp;
        }
        else   // case of two children , we will find in_order successor
        {
            ll in_order_successor_value=find_in_order_successor(root->right);
            root->data=in_order_successor_value;
            //cout<<"In_order successor value = "<<in_order_successor_value<<"\n";
            root->right=delete_from_bst(root->right,in_order_successor_value);
            return root;
        }
    }
}
//*********************************************************************************************

void preorder_traversal(bst *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(bst *root)
{
    if(root==NULL) return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    bst *root=NULL;
    ll nodes=14;
    vector <ll> input_nodes;
    in.pb(60);     in.pb(30);     in.pb(100);    in.pb(5);     in.pb(50);     in.pb(80);     in.pb(120);    in.pb(1);
    in.pb(25);     in.pb(40);     in.pb(55);     in.pb(65);    in.pb(110);    in.pb(130);
    for(int i=0;i<in.size();i++)
    {
        bst *temp=new(bst);
        temp->data=in[i];
        root=insert_in_bst(root,temp);
    }
    cout<<"Pre-Order Tree traversal\n";
    preorder_traversal(root);
    cout<<"\n\nIn-Order Tree traversal\n";
    inorder_traversal(root);
    cout<<"\n";
    //**************************************************************************************
    ll node;
    cout<<"\nDelete 2 from BST\n";
    node=2;
    root=delete_from_bst(root,node);
    cout<<"\nDelete 80 from BST\n";

    node=80;
    root=delete_from_bst(root,node);
    cout<<"\nIn-Order Tree traversal\n";
    inorder_traversal(root);

    cout<<"\n\nDelete 60 from BST\n";
    node=60;
    root=delete_from_bst(root,node);
    cout<<"\nIn-Order Tree traversal\n";
    inorder_traversal(root);
    cout<<"\n\n";
    //**************************************************************************************
    return 0;
}
