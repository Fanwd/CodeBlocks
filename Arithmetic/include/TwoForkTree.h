#ifndef TWOFORKTREE_H_INCLUDED
#define TWOFORKTREE_H_INCLUDED

#include "Global.h"

typedef struct _tree_node{
    int data;
    struct _tree_node *lChild;
    struct _tree_node *rChild;
} TreeNode;

void TwoForkTreeTest();
void TwoForkTreeCreate(TreeNode**);
void TwoForkTreePre(TreeNode*);
void TwoForkTreeMid(TreeNode*);
void TwoForkTreePost(TreeNode*);
int TwoForkTreeDeep(TreeNode*);
void TwoForkTreeDestroy(TreeNode*);

#endif // TWOFORKTREE_H_INCLUDED
