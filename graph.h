#pragma once

#include <stdio.h>
#include <stdlib.h>



typedef struct GraphNode {
    char vertex;
    struct GraphNode* link;
}GraphNode;
#define MAX_VERTICES 26
typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;
// 그래프 초기화
void init(GraphType* g);
// 정점 삽입 연산
void insert_vertex(GraphType* g, char v);
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, char u, char v);
void print_adj_list(GraphType* g);