#include "flightPath.h"
#define path 10

timeTableNode timeTable[26][path];
int visit[200]={0,};
int pathCount;


//비행기 경로를 나타내는 그래프 생성
void MakeFlightPath(GraphType *g)
{
    srand(time(NULL));
  
    

    for(int i=0;i<26;i++)
    {
        insert_vertex(g, i+'a');
    }
    int tmp;
    for (int i = 0; i < 26; i++)
    {
        int d[100] = {0,};
        for (int j = 0; j < path; j++)
        {
            tmp = rand() % 26;//0~25
            if (d[tmp] == 0&&tmp!=i)
            {
                d[tmp] = 1;
               // AddEdge(v[i],CreateEdge(v[i],v[tmp],1));
               insert_edge(g,i+'a',tmp+'a');
            }
            else
                j--;
        }
    }
}

//24시간 중에 랜덤한 출발 시각 결정 (30분단위)
void MakeTimeTable(GraphType *g)
{
  
    
    for(int i=0;i<26;i++)
    {
        GraphNode* curNode=g->adj_list[i];
        char curStart='a'+i;
        for(int j=0;j<path;j++)
        {
            timeTable[i][j].dest=curNode->vertex;
            timeTable[i][j].hour=rand()%24;
            timeTable[i][j].min=(rand()%2)*30;
          
            curNode=curNode->link;
        }
      

    }
}

void PrintTimeTable()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<path;j++)
            printf("%c to %c departure time = %dh%dm\n",i+'a',timeTable[i][j].dest,timeTable[i][j].hour,timeTable[i][j].min);
        
        
    }
}

int checkEdge(GraphType* g,char from, char to) {
    
    
    GraphNode* search = g->adj_list[from-'a'];
    
    // NULL 일 때 까지 돌기
    while (search) {
        // 찾았으면
        if (search->vertex == to)
            return 1; // 1반환
        search = search->link;
    }
 
    return -1; // 연결안되어있으면 -1 반환
}

// 경로 찾기
//비행기 시간은 1시간으로 고정이며 1시간 내로 비행기가 없을 시 다음 날 출발하는 비행기를 탑승한다.

void printPath(GraphType* g,Stack* p,char start, char end, int* finishFlag)
{
    *finishFlag=0;
    for(int i=0;i<200;i++)
    {
        visit[i]=0;
    }
    checkPath(g,p,start,end,finishFlag);
    if(*finishFlag!=1)
    {
        printf("There is no path %c to %c.\n",start,end);
    }
}
void checkPath(GraphType* g,Stack* p,char start, char end,int* finishFlag) {
    
    // 방문표시
    visit[start] = 1;
    push(p,start); // 넣기
   
    // 도착 체크하기
    if (start == end) {
        *finishFlag=1;
       int arrivalHour;
       int arrivalMin;
        for (int i = 1; i < p->top; i++)
        {
            printf("%c", p->stack[i]);//경로출력
            int temp;
            for(int j=0;j<path;j++)
            {
                
                if(timeTable[p->stack[i]-'a'][j].dest==p->stack[i+1])
                {
                    printf("(%dh%dm)",timeTable[p->stack[i]-'a'][j].hour,timeTable[p->stack[i]-'a'][j].min);
                    arrivalHour=timeTable[p->stack[i]-'a'][j].hour;
                    arrivalMin=timeTable[p->stack[i]-'a'][j].min;
                }
            }
            printf(" - ");
        }
        printf("%c",end);
        arrivalHour+=1;
        printf("(arrive at %dh%dm)",arrivalHour,arrivalMin);
        printf("\n"); //줄바꿈
        
     
        pop(p); // 도착지점 빼고 종료
 
        return; //종료
    }
 
    for (int i = 'a'; i <= 'z'; i++) {
        // 연결되어있고 방문하지 않은 곳이면 들어가기
        if (checkEdge(g,start, i) == 1 && visit[i] == 0) {
            checkPath(g,p,i, end,finishFlag); // 재귀 호출
             if(*finishFlag==1)
                 return;
            visit[i] = 0; // 빠져나오면 방문 취소
        }
    }
 
    pop(p);
    
}