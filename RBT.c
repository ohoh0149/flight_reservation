#include "RBT.h"



void random_fillingA(int A[], int n)
{
    int d[100] = {0};
    int tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = rand() % 50;
        if (d[tmp] == 0)
        {
            d[tmp] = 1;
            A[i] = tmp;
        }
        else
            i--;
    }
}

int abs(int n) { return n > 0 ? n : -n; }

Node *minimum(Node *T)

{

    while (T->left->key != -1)
        T = T->left;

    Node *rt = (Node *)malloc(sizeof(Node));

    rt = T;

    return rt;
}

Node *maximum(Node *T)

{

    while (T->right->key != -1)
        T = T->right;

    Node *rt = (Node *)malloc(sizeof(Node));

    rt = T;

    return rt;
}

Node *successor(Node *T)
{
    if (T->right->key != -1)
        return minimum(T->right);
    Node *y = (Node *)malloc(sizeof(Node));
    y = T->parent;
    while (y->key != -1 && T == y->right)
    {
        T = y;
        y = y->parent;
    }
    return y;
}

Node *predecessor(Node *T)
{
    if (T->left->key != -1)
        return maximum(T->left);

    Node *y = (Node *)malloc(sizeof(Node));
    y = T->parent;
    while (y->key != -1 && T == y->left)
    {
        T = y;
        y = y->parent;
    }

    return y;
}
void treeMap(Node *T, int map[][100][2], int i, int j, int len)

{

    if (T->key != -1)

    {

        if (map[i][j][RED] == -1 && map[i][j][BLACK] == -1)

        {

            if (T->color == RED)
                map[i][j][RED] = T->key;

            else
                map[i][j][BLACK] = T->key;
        }

        else

        {

            if (T->color == RED)
                map[i][j + 1][RED] = T->key;

            else
                map[i][j + 1][BLACK] = T->key;
        }

        treeMap(T->left, map, i + 1, j - len, len - 3);

        treeMap(T->right, map, i + 1, j + len, len - 3);
    }
}

void print_bst1(RBT *T)

{

    int map[50][100][2];
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                map[i][j][k] = -1;
            }
        }
    }

    int i = 0;
    int j = 49;
    int len = 16;
    treeMap(T->root, map, i, j, len);
    int flag = 0;
    for (i = 0; i < 50; i++)
    {
        for (int k = 0; k < 100; k++)
        {
            if (map[i][k][RED] != -1 || map[i][k][BLACK] != -1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            for (j = 0; j < 100; j++)
            {
                if (map[i][j][RED] == -1 && map[i][j][BLACK] == -1)
                    printf(" ");
                else
                {
                    if (map[i][j][BLACK] != -1)
                        printf("%dB", map[i][j][BLACK]);
                    else
                        printf("%dR", map[i][j][RED]);
                }
            }
        }
        else
            break;

        printf("\n");

        flag = 0;
    }
}
Node *make_node(RBT *T, int val)

{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = val;
    node->color = BLACK;
    node->left = T->nil;
    node->right = T->nil;
    node->parent = T->nil;
    return node;
}

void left_rotate(RBT *T, Node *x)

{
    Node *y = (Node *)malloc(sizeof(Node));
    y = x->right;
    x->right = y->left;
    if (y->left != T->nil)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == T->nil)
        T->root = y;

    else if (x == x->parent->left)
        x->parent->left = y;

    else
        x->parent->right = y;

    y->left = x;

    x->parent = y;
}

void right_rotate(RBT *T, Node *x)

{

    Node *y = (Node *)malloc(sizeof(Node));

    y = x->left;

    x->left = y->right;

    if (y->right != T->nil)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == T->nil)
        T->root = y;

    else if (x == x->parent->right)
        x->parent->right = y;

    else
        x->parent->left = y;

    y->right = x;

    x->parent = y;
}

void RB_insert_fixup(RBT *T, Node *z)

{

    Node *y = (Node *)malloc(sizeof(Node));

    while (z->parent->color == RED)

    {

        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if (y->color == RED)

            {

                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }

            else// y->color black

            {

                if (z == z->parent->right)
                {

                    z = z->parent;
                    left_rotate(T, z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(T, z->parent->parent);
            }
        }

        else // right

        {

            y = z->parent->parent->left;

            if (y->color == RED)

            {

                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }

            else

            {

                if (z == z->parent->left)

                {
                    z = z->parent;
                    right_rotate(T, z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(T, z->parent->parent);
            }
        }
    }

    T->root->color = BLACK;
}

int tree_insert(RBT *T, int key) //삽입 성공시 1, 실패시 0 반환

{
    Node *z = make_node(T, key);
    Node *y = T->nil;

    Node *x = T->root;

    while (x != T->nil)

    {

        y = x;

        if (z->key < x->key)
            x = x->left;

        else if (z->key == x->key)

        {
            printf("                                        ");
            printf("The node is already inserted\n");
            return 0;
        }

        else
            x = x->right;
    }

    z->parent = y;

    if (y == T->nil)
        T->root = z;

    else if (z->key < y->key)
        y->left = z;

    else
        y->right = z;

    z->left = T->nil;

    z->right = T->nil;

    z->color = RED;

    RB_insert_fixup(T, z);

    return 1;
}

void transplant(RBT *T, Node *u, Node *v)

{

    if (u->parent == T->nil)
        T->root = v;

    else if (u == u->parent->left)
        u->parent->left = v;

    else
        u->parent->right = v;

    v->parent = u->parent;
}

void RB_delete_fixup(RBT *T, Node *x)

{

    Node *w = (Node *)malloc(sizeof(Node));

    while (x != T->root && x->color == BLACK)

    {

        if (x == x->parent->left)

        {

            w = x->parent->right;

            if (w->color == RED)

            {

                w->color = BLACK;

                w->parent->color = RED;

                left_rotate(T, x->parent);

                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK) //

            {

                w->color = RED;

                x = x->parent;
            }

            else

            {

                if (w->right->color == BLACK)

                {

                    w->left->color = BLACK;

                    w->color = RED;

                    right_rotate(T, w);

                    w = x->parent->right;
                }

                w->color = x->parent->color;

                x->parent->color = BLACK;

                w->right->color = BLACK;

                left_rotate(T, x->parent);

                x = T->root;
            }
        }

        else

        {

            w = x->parent->left;

            if (w->color == RED)

            {

                w->color = BLACK;

                w->parent->color = RED;

                right_rotate(T, x->parent);

                w = x->parent->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK)

            {

                w->color = RED;

                x = x->parent;
            }

            else

            {

                if (w->left->color == BLACK)

                {

                    w->right->color = BLACK;

                    w->color = RED;

                    left_rotate(T, w);

                    w = x->parent->left;
                }

                w->color = x->parent->color;

                x->parent->color = BLACK;

                w->left->color = BLACK;

                right_rotate(T, x->parent);

                x = T->root;
            }
        }
    }

    x->color = BLACK;
}

Node *tree_searchr(Node *T, int k) // k가 key값인 노드 찾아 반환

{

    Node *rt = (Node *)malloc(sizeof(Node));

    if (k == T->key)

    {

        rt = T;

        return rt;
    }

    else if (k < T->key)

    {

        if (T->left->key == -1)

        {

            rt = T;

            return rt;
        }

        else
            return tree_searchr(T->left, k);
    }

    else

    {

        if (T->right->key == -1)

        {

            rt = T;

            return rt;
        }

        else
            return tree_searchr(T->right, k);
    }
}

void tree_delete(RBT *T, int key)

{

    Node *z = tree_searchr(T->root, key);
    Node *y = (Node *)malloc(sizeof(Node));

    Node *x = (Node *)malloc(sizeof(Node)); // y의 원래위치로 이동할 노드(FIXUP)

    y = z;

    int y_original_color = y->color;

    if (z->left == T->nil)
    {
        x = z->right;
        transplant(T, z, z->right);
    }

    else if (z->right == T->nil)
    {
        x = z->left;
        transplant(T, z, z->left);
    }

    else
    {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z)
            x->parent = y;

        else
        {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK)
        RB_delete_fixup(T, x);
}

