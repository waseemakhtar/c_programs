
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define true    1
#define false   0
/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

/* Function to find if given tree is a valid/not valid Binary Search Tree
 *
 * Recursively traverses the tree and returns
 * true:
 *  - if data in left subtree is less root data
 *  'and'
 *  - if data in right subtree is greater than root data
 * false:
 *  otherwise
*/
int isBST(struct TreeNode* root, int min, int max)
{
    if(root == NULL) return true;

    return ((root->val > min) && (root->val < max) &&
        isBST(root->left, min, root->val) &&
        isBST(root->right, root->val, max));
}

/* Wrapper function to call isBST with max and min values
*/
int isValidBST(struct TreeNode* root)
{
    return(isBST(root, INT_MIN, INT_MAX));
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TreeNode* newNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)
                                malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct TreeNode *root = newNode(14);
    root->left = newNode(10);
    root->right = newNode(16);
    root->left->left = newNode(9);
    root->left->right = newNode(13);
    root->right->left = newNode(15);
    root->right->right = newNode(17);

    printf("First tree is %s BST\n",
      (isValidBST(root) == true)?"a valid":"not a valid");

    root = newNode(14);
    root->left = newNode(10);
    root->right = newNode(16);
    root->left->left = newNode(100);
    root->left->right = newNode(13);
    root->right->left = newNode(15);
    root->right->right = newNode(17);
    printf("Second tree is %s BST\n",
      (isValidBST(root) == true)?"a valid":"not a valid");

    return 0;
}
