#ifndef RBT_H
#define RBT_H


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BLACK 0
#define RED 1
typedef struct _node
{
    int key;
    int color;
    struct _node *left;
    struct _node *right;
    struct _node *parent;
} Node;

typedef struct rbt
{
    Node *root;
    Node *nil;
} RBT;

void random_fillingA(int A[], int n);
Node *minimum(Node *T);
Node *maximum(Node *T);
Node *successor(Node *T);
Node *predecessor(Node *T);
void treeMap(Node *T, int map[][100][2], int i, int j, int len);
void print_bst1(RBT *T);
Node *make_node(RBT *T, int val);
void left_rotate(RBT *T, Node *x);
void right_rotate(RBT *T, Node *x);
void RB_insert_fixup(RBT *T, Node *z);
int tree_insert(RBT *T, int key); //삽입 성공시 1, 실패시 0 반환
void transplant(RBT *T, Node *u, Node *v);
void RB_delete_fixup(RBT *T, Node *x);
Node *tree_searchr(Node *T, int k); // k가 key값인 노드 찾아 반환
void tree_delete(RBT *T, int key);





#endif