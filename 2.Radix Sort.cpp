#include <stdio.h>   
#include <string.h>   
      
//�Լ� ����   
char countingSort(char a[], char b[], int n);   
      
//����   
int main()   
{   
    int n,k;   
    char input[200][20] = {0,}; //�Է� �迭   
    char output[200][20] = {0,}; // ���ĵ� ��� ���� �迭   
      
    char temp[200] = {0,};   
    char temp_output[200] ={0,};   
      
    //n, k �Է�   
    scanf("%d %d",&n,&k);   
      
      
    //���ڿ� �Է�   
    for(int i=0; i<n;i++)   
        scanf("%s",input[i]);   
  
  
      
    int k_const = k;   
    bool did = false;   
    //�� �ڸ��� ���� �ݺ�   
    for(int c=0; c<k_const ; c++)   
    {   
       
        //�迭�� �ʱ�ȭ   
        for(int i=0; i<200;i++)   
            temp[i] = 0;   
        for(int i=0; i<200;i++)   
            temp_output[i] = 0;   
      
        //���ĵ� ����� �ٽ� input�� �Է�.   
        if(did == true)   
            {   
            for(int i=0;i<200;i++) 
                for(int j=0;j<20;j++) 
            input[i][j] = output[i][j];  
            }   
            did = true;   
                                          
      
  
            //�� �ڸ����� ���ڸ� ���� �ӽù迭   
            for(int i=1; i<=n;i++)   
            { 
                //0(NULL)�̸� 1�� �־���. 
                if(input[i-1][k-1] == 0) 
                    temp[i] = 1; 
                else
                  temp[i] = input[i-1][k-1];                 
            } 
  
  
            //��������. ����� temp_output�迭�� 
            countingSort(temp,temp_output,n); 
      
              
            //���ĵ� ����迭 ���� ����   
            int output_num=0;   
      
            //remember_int�� �̹� ����� �迭 ���°���� �����ϱ� ���� ����. 
            int remember_int[101] = {-2,};   
            int re=0;   
            //��� ��� - ���ĵ� ���ڵ��� �������� �˻��Ͽ� ���� input�迭 ���� ���   
            for(int i=1; i<=n; i++)   
            {   
                for(int j=1; j<=n; j++)   
                    if(temp_output[i] != 0 || input[j-1][k-1] !=0) 
                    if(temp_output[i] == input[j-1][k-1] || (temp_output[i] == 1 &&input[j-1][k-1] == 0))   
                    {   
                            
                            
                            //har, car �� ���ڰ� ������ �� ������ �ʴ� ���� �ذ� + ���-- ���� --   
                            bool t=false;   
                            for(int d=0; d<101;d++)   
                                if(remember_int[d] == j)   
                                {   
                                    t = true;   
                                }   
                                if(t==true)   
                                    continue;    
  
      
                                if(input[j-1][0]!=0)   
                                {   
                                      
                                    printf(" %s",input[j-1]);  
  
                                    for(int ai=0;ai<20;ai++) 
                                        output[output_num][ai] = input[j-1][ai];//�ݺ����ֱ� ���� �ٸ� �迭�� ����.                        
                                    output_num++;   
      
                                    remember_int[re] = j;   
                                    re++;   
                                }   
      
      
      
                                //har, car �� ���ڰ� ������ �� ������ �ʴ� ���� �ذ� + ���-- �� --   
     
                    }   
                   
            }   
      
            printf("\n");   
            k--;   
    }   
  
    return 0;   
}   
      
//������� �Լ�.   
/**************   
�������� ������ ������� �Լ��� �����.   
��� main���� �迭���ڸ� �Ѱ��� �� �� �ڸ����� ���ڸ� ������ �ӽ� �迭�� ���� ���� �Ѱ���.   
****************/
char countingSort(char a[], char b[], int n)   
{   
    //a[] �Է¹迭   
    //b[] �迭�� ������ ���   
    int alpa_num = 130;   
    int c[1000] = {0,};   
      
    for(int i=1; i<=alpa_num; i++)   
        c[i] = 0;   
    for(int j=1; j<=n; j++)   
        c[a[j]]++;   
    for(int i=1; i<=alpa_num; i++)   
        c[i] = c[i] + c[i-1];   
      
    for(int j=n; j>=1; j--)   
    {   
        b[c[a[j]]] = a[j];   
        c[a[j]]--;   
    }   
      
    return *b;   
      
}   
  
/************************************************************** 
    Problem: 1034 
    User: 091895 
    Language: C++ 
    Result: Accepted 
    Time:12 ms 
    Memory:864 kb 
****************************************************************/