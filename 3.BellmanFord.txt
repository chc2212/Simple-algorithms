#include <stdio.h>  
#include <stdlib.h>  
  
  
int prev[101];; // 이전정점의 번호를 저장  
int line[101][101]; //인접행렬 선언  
int n_distance[101];  
bool visited[101][101];  
bool visited_n[101];  
int first_s;  
  
  
int DFS(int s); //DFS탐색  
  
//메인  
int main()  
{  
  
    int n,m,s; //n은 정점, m은 간선, s는 시작점 번호    
    int temp_start,temp_end,temp_w; //입력시 임시로 쓰는 변수  
  
    // 초기화  
    for(int i=1;i<101;i++)  
        for(int j=1;j<101;j++)  
        {  
            line[i][j] = 101;  
            visited[i][j] = false;  
  
        }  
  
        for(int i=1; i<101;i++)  
        {  
            n_distance[i] = 9999;         
            prev[i] = -1;  
        }  
  
        //입력  
        scanf("%d %d %d",&n,&m,&s);//개수 입력  
  
        for(int i=0; i<m;i++)  
        {  
            scanf("%d %d %d",&temp_start,&temp_end,&temp_w);//간선과 가중치 입력  
            line[temp_start][temp_end] = temp_w;//간선과 가중치 넣기  
        }  
  
        //시작정점 거리 초기화  
        n_distance[s] = 0;  
  
        //시작위치 다른 변수에 저장 
        first_s = s;  
  
        //최단거리 계산  
        for(int i=0;i<n-1;i++)  
        {    
  
            for(int c=1; c<101;c++)  
                visited_n[c] = false;  
  
            // 초기화  
            for(int c=1;c<101;c++)  
                for(int d=1;d<101;d++)  
                    visited[c][d] = false;  
  
            //초기정점 방문했다고 표시해줌. 
            visited_n[first_s] = true;  
            DFS(s);  //DFS실행 
  
            //출력 
            for(int j=1; j<=n;j++)  
                printf(" %d %d", n_distance[j], prev[j]) ;  
            printf("\n");  
        }         
  
        bool a=false;  
  
        //음의 사이클 확인.  
        for(int c=1;c<101;c++)  
        {  
            for(int i=1;i<101;i++)  
            {  
                if(line[c][i] != 101)  
                {  
                    if(n_distance[c] + line[c][i] < n_distance[i] && (n_distance[c] != 9999 &&  n_distance[i]!= 9999))  
                    {  
                        printf(" -1");  
                        a = true;  
                        break;  
  
                    }  
                    else
                    {  
                        ;  
                    }  
                }  
            }  
            if(a==true)  
                break;  
        }  
  
        if(a == false)  
            printf(" 1");  
  
        return 0;  
}  
  
  
int DFS(int c) //DFS탐색  
{  
  
    for(int i=1;i<101;i++)  
    {  
        if(line[c][i] != 101)  
        {  
            if(visited[c][i] == false)  
            {  
  
                visited[c][i] = true; //간선방문표시  
                if(n_distance[c] + line[c][i] < n_distance[i]) //조건 맞으면 정점수정  
                {  
  
                    prev[i] = c; // 정점과 이전 정점을 연결해줌.  
                    n_distance[i] = n_distance[c] + line[c][i];// 정점 거리 바꿈.    
                }  
  
                //정점 방문     
                if(visited_n[i] == false)  
                {  
                    visited_n[i] = true;  
                    DFS(i);  
  
                }  
            }  
        }  
    }  
    return 0;  
  
}  
  
/************************************************************** 
    Problem: 1036 
    User: 091895 
    Language: C++ 
    Result: Accepted 
    Time:24 ms 
    Memory:912 kb 
****************************************************************/