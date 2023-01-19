#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
//비행기 경로를 나타내는 그래프 생성
typedef struct{
    char dest;
    int hour;
    int min;
}timeTableNode;

//비행경로 생성
void MakeFlightPath(GraphType *g);


//24시간 중에 랜덤한 출발 시각 결정 (30분단위)
void MakeTimeTable(GraphType *g);
void PrintTimeTable();
int checkEdge(GraphType* g,char from, char to);

void printPath(GraphType* g,Stack* p,char start, char end,int* finishFlag);

//비행기 시간은 1시간으로 고정이며 1시간 내로 비행기가 없을 시 다음 날 출발하는 비행기를 탑승한다.
void checkPath(GraphType* g,Stack* p,char start, char end,int* finishFlag);
