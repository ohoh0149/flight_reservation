#include "graph.h"



// 그래프 초기화
void init(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, char v) {
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr, "정점의 개수 초과");
        return;
    }
    g->n++;
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, char u, char v) {
    GraphNode* node;
    if (u-'a' >= g->n || v-'a' >= g->n) {
        fprintf(stderr, "정점 번호 오류");
        return;
    }
    if (g->adj_list[u-'a'] == NULL) { // insert_first
        node = (GraphNode*)malloc(sizeof(GraphNode));
        node->vertex = v;
        node->link = g->adj_list[u-'a'];
        g->adj_list[u-'a'] = node;
    }
    else { //insert_last
        node = g->adj_list[u-'a'];
        while (node->link != NULL)
            node = node->link;
        node->link = (GraphNode*)malloc(sizeof(GraphNode));
        node->link->vertex = v;
        node->link->link = NULL;
    }
}
void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("vertex %c's adj_list", i+'a');
        while (p != NULL) {
            printf("-> %c", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}