#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#include "stack.h"
#include "RBT.h"
#include "graph.h"
#include "flightPath.h"
#include "reservation.h"
#define INPUT_COUNT 10
#define DELETE_COUNT 5



typedef struct{
    char name[10];
    char source;
    char dest;
   // int date;
    int id;
}Person;

int main() {
    int* finishFlag=malloc(sizeof(int));//경로가 있는지 없는지를 확인하는 변수, 매개변수로 넘겨서 경로가 있다면 1을 대입한다.
    
    Person person[100];
    GraphType* g= (GraphType*)malloc(sizeof(GraphType));
    init(g);
    // 정점 삽입 
    MakeFlightPath(g);//비행경로 생성
    print_adj_list(g);//비행경로 출력
    MakeTimeTable(g);//비행경로 각각에 대한 시간표 출력
    PrintTimeTable();

    Stack* p=(Stack*)malloc(sizeof(Stack));
    RBT *rbt = (RBT *)malloc(sizeof(RBT));
    rbt->nil = (Node *)malloc(sizeof(Node));
    rbt->nil->color = BLACK;
    rbt->nil->key = -1;
    rbt->nil->left = rbt->nil;
    rbt->nil->right = rbt->nil;
    rbt->nil->parent = rbt->nil;
    rbt->root = rbt->nil;
    //이름과 시작지와 도착지를 INPUT_COUNT만큼 입력받는다.
    for(int i=0;i<INPUT_COUNT;i++)
    {
        printf("Enter name, source, destination :");
       
       scanf("%s %c %c",person[i].name,&person[i].source,&person[i].dest);
        person[i].id=i+1;
       
        printf("\n");
        
        s_init(p);//스택 초기화
       
        printPath(g,p,person[i].source,person[i].dest,finishFlag);
        
        
        if(*finishFlag==1)//비행경로가 존재한다면 예약후 레드블랙트리를 출력한다.
        {
            reserveAndPrint(rbt,person[i].id);
            printf("%s's reservation %c to %c is completed.\n\n",person[i].name,person[i].source,person[i].dest);
        }
         
    }
    
    //삭제하려는 ID를 입력받고 존재한다면 삭제한다.
    for(int i=0;i<DELETE_COUNT;i++)
    {
        int deleteKey;
        printf("Enter delete ID :");
        scanf("%d",&deleteKey);

        deleteAndPrint(rbt,deleteKey);
    }
    s_init(p);
  
    free(g);
    free(finishFlag);
    
    return 0;
}