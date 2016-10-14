#include "TwoForkTree.h"

void TwoForkTreeCreate(TreeNode **t)
{
    int data = -1;
    scanf("%d", &data);
    if(data == -1)
    {
        *t = NULL;
        return;
    }
    *t = (TreeNode*)malloc(sizeof(TreeNode));
    (*t)->data = data;
    printf("Please input %d¡®s lChild\n", data);
    TwoForkTreeCreate(&(*t)->lChild);
    printf("Please input %d's rChild\n", data);
    TwoForkTreeCreate(&(*t)->rChild);
}

void TwoForkTreePre(TreeNode *t)
{
    if(t == NULL)
    {
        return;
    }
    printf("%d ", t->data);
    TwoForkTreePre(t->lChild);
    TwoForkTreePre(t->rChild);
}

void TwoForkTreeMid(TreeNode *t)
{
    if(t == NULL)
    {
        return;
    }
    TwoForkTreeMid(t->lChild);
    printf("%d ", t->data);
    TwoForkTreeMid(t->rChild);
}

void TwoForkTreePost(TreeNode *t)
{
    if(t == NULL)
    {
        return;
    }
    TwoForkTreePost(t->lChild);
    TwoForkTreePost(t->rChild);
    printf("%d ", t->data);
}

int TwoForkTreeDeep(TreeNode *t)
{
    int deep = 0;
    int lDeep = 0;
    int rDeep = 0;
    if(t != NULL)
    {
        lDeep = TwoForkTreeDeep(t->lChild);
        rDeep = TwoForkTreeDeep(t->rChild);
        deep = lDeep>rDeep?lDeep:rDeep + 1;
    }
    return deep;
}

void TwoForkTreeDestroy(TreeNode *t)
{
    if(t == NULL)
    {
        return;
    }
    TwoForkTreeDestroy(t->lChild);
    TwoForkTreeDestroy(t->rChild);
    free(t);
    t = NULL;
}

void TwoForkTreeTest()
{
    int ret = -1;

    TreeNode *t = NULL;
    TwoForkTreeCreate(&t);
    printf("Pre Order:");
    TwoForkTreePre(t);
    putchar('\n');
    printf("Mid Order:");
    TwoForkTreeMid(t);
    putchar('\n');
    TwoForkTreePost(t);
    putchar('\n');
    printf("Tree Deep:");
    ret = TwoForkTreeDeep(t);
    printf("%d\n", ret);
    printf("Destroy\n");
    TwoForkTreeDestroy(t);
}
