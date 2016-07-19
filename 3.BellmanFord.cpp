#include <stdio.h>  
#include <stdlib.h>  
  
  
int prev[101];; // ���������� ��ȣ�� ����  
int line[101][101]; //������� ����  
int n_distance[101];  
bool visited[101][101];  
bool visited_n[101];  
int first_s;  
  
  
int DFS(int s); //DFSŽ��  
  
//����  
int main()  
{  
  
    int n,m,s; //n�� ����, m�� ����, s�� ������ ��ȣ    
    int temp_start,temp_end,temp_w; //�Է½� �ӽ÷� ���� ����  
  
    // �ʱ�ȭ  
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
  
        //�Է�  
        scanf("%d %d %d",&n,&m,&s);//���� �Է�  
  
        for(int i=0; i<m;i++)  
        {  
            scanf("%d %d %d",&temp_start,&temp_end,&temp_w);//������ ����ġ �Է�  
            line[temp_start][temp_end] = temp_w;//������ ����ġ �ֱ�  
        }  
  
        //�������� �Ÿ� �ʱ�ȭ  
        n_distance[s] = 0;  
  
        //������ġ �ٸ� ������ ���� 
        first_s = s;  
  
        //�ִܰŸ� ���  
        for(int i=0;i<n-1;i++)  
        {    
  
            for(int c=1; c<101;c++)  
                visited_n[c] = false;  
  
            // �ʱ�ȭ  
            for(int c=1;c<101;c++)  
                for(int d=1;d<101;d++)  
                    visited[c][d] = false;  
  
            //�ʱ����� �湮�ߴٰ� ǥ������. 
            visited_n[first_s] = true;  
            DFS(s);  //DFS���� 
  
            //��� 
            for(int j=1; j<=n;j++)  
                printf(" %d %d", n_distance[j], prev[j]) ;  
            printf("\n");  
        }         
  
        bool a=false;  
  
        //���� ����Ŭ Ȯ��.  
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
  
  
int DFS(int c) //DFSŽ��  
{  
  
    for(int i=1;i<101;i++)  
    {  
        if(line[c][i] != 101)  
        {  
            if(visited[c][i] == false)  
            {  
  
                visited[c][i] = true; //�����湮ǥ��  
                if(n_distance[c] + line[c][i] < n_distance[i]) //���� ������ ��������  
                {  
  
                    prev[i] = c; // ������ ���� ������ ��������.  
                    n_distance[i] = n_distance[c] + line[c][i];// ���� �Ÿ� �ٲ�.    
                }  
  
                //���� �湮     
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