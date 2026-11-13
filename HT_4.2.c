#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int val)
{
    TreeNode* newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool Mirror(TreeNode *t1, TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;

    if (t1 == NULL || t2 == NULL)
        return false;

    return (t1->val == t2->val) &&
           Mirror(t1->left, t2->right) &&
           Mirror(t1->right, t2->left);
}

bool Symmetric(TreeNode  *root)
{
    if (root == NULL)
        return true;

    return Mirror(root->left, root->right);
}

void freeTree(TreeNode *root)
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    printf("\n       1\n      / \\\n     2   2\n    / \\ / \\\n   3  4 4  3\n");

    TreeNode *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(2);
    root1->left->left = createNode(3);
    root1->left->right = createNode(4);
    root1->right->left = createNode(4);
    root1->right->right = createNode(3);

    if (Symmetric(root1))
        printf("Result: Tree is symmetric.\n");
    else
        printf("Result: Tree is not symmetric.\n");

    printf("Real tree is symmetric.\n\n");
    freeTree(root1);


    printf("\n\n");

    printf("\n       1\n      / \\\n     2   2\n      \\   \\\n       3   3\n\n");

    TreeNode *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->right = createNode(3);
    root2->right->right = createNode(3);

    if (Symmetric(root2))
        printf("Result: Tree is symmetric.\n");
    else
        printf("Result: Tree is not symmetric.\n");

    printf("Real tree is not symmetric.\n\n");
    freeTree(root2);

    return 0;
}
