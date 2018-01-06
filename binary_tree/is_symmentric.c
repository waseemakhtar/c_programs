// C program to check if a given Binary Tree is symmetric or not
/*
For example, this binary tree is symmetric:

     1
   /   \
  2     2
 / \   / \
3   4 4   3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
*/   
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// A Binary Tree Node
struct Node
{
    int key;
    struct Node* left, *right;
};

// Utility function to create new Node
struct Node* newNode(int key)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}

// Returns true if trees with roots as root1 and root2 are mirror
bool isMirror(struct Node *root1, struct Node *root2)
{
    // If both trees are emptu, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;

    // For two trees to be mirror images, the following three
    // conditions must be true
    // 1 - Their root node's key must be same
    // 2 - left subtree of left tree and right subtree
    //      of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree
    //      of right tree have to be mirror images
    if (root1 && root2 && root1->key == root2->key)
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);

    // if neither of above conditions is true then root1
    // and root2 are not mirror images
    return false;
}

// Returns true if a tree is symmetric i.e. mirror image of itself
bool isSymmetric(struct Node* root)
{
    // Check if tre is mirror of itself
    return isMirror(root, root);
}

// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    struct Node *root   = newNode(1);
    root->left          = newNode(2);
    root->right         = newNode(2);
    root->left->left    = newNode(3);
    root->left->right   = newNode(4);
    root->right->left   = newNode(4);
    root->right->right  = newNode(3);

    printf("The given tree is %s\n",
      isSymmetric(root)?"symmetric":"not symmetric");

    root                = newNode(1);
    root->left          = newNode(2);
    root->right         = newNode(2);
    root->left->left    = newNode(3);
    root->left->right   = newNode(4);
    root->right->left   = newNode(4);
    root->right->right  = newNode(4);

    printf("The given tree is %s\n",
      isSymmetric(root)?"symmetric":"not symmetric");

    return 0;
}
