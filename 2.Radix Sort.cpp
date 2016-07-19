#include <stdio.h>   
#include <string.h>   
      
//함수 선언   
char countingSort(char a[], char b[], int n);   
      
//메인   
int main()   
{   
    int n,k;   
    char input[200][20] = {0,}; //입력 배열   
    char output[200][20] = {0,}; // 정렬된 결과 저장 배열   
      
    char temp[200] = {0,};   
    char temp_output[200] ={0,};   
      
    //n, k 입력   
    scanf("%d %d",&n,&k);   
      
      
    //문자열 입력   
    for(int i=0; i<n;i++)   
        scanf("%s",input[i]);   
  
  
      
    int k_const = k;   
    bool did = false;   
    //각 자리수 정렬 반복   
    for(int c=0; c<k_const ; c++)   
    {   
       
        //배열들 초기화   
        for(int i=0; i<200;i++)   
            temp[i] = 0;   
        for(int i=0; i<200;i++)   
            temp_output[i] = 0;   
      
        //정렬된 결과값 다시 input에 입력.   
        if(did == true)   
            {   
            for(int i=0;i<200;i++) 
                for(int j=0;j<20;j++) 
            input[i][j] = output[i][j];  
            }   
            did = true;   
                                          
      
  
            //각 자리수의 문자만 넣은 임시배열   
            for(int i=1; i<=n;i++)   
            { 
                //0(NULL)이면 1을 넣어줌. 
                if(input[i-1][k-1] == 0) 
                    temp[i] = 1; 
                else
                  temp[i] = input[i-1][k-1];                 
            } 
  
  
            //정렬해줌. 결과는 temp_output배열에 
            countingSort(temp,temp_output,n); 
      
              
            //정렬된 결과배열 위한 변수   
            int output_num=0;   
      
            //remember_int는 이미 사용한 배열 몇번째인지 저장하기 위한 변수. 
            int remember_int[101] = {-2,};   
            int re=0;   
            //결과 출력 - 정렬된 문자들을 바탕으로 검색하여 원본 input배열 정렬 출력   
            for(int i=1; i<=n; i++)   
            {   
                for(int j=1; j<=n; j++)   
                    if(temp_output[i] != 0 || input[j-1][k-1] !=0) 
                    if(temp_output[i] == input[j-1][k-1] || (temp_output[i] == 1 &&input[j-1][k-1] == 0))   
                    {   
                            
                            
                            //har, car 등 문자가 겹쳤을 때 나오지 않는 문제 해결 + 출력-- 시작 --   
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
                                        output[output_num][ai] = input[j-1][ai];//반복해주기 위해 다른 배열에 저장.                        
                                    output_num++;   
      
                                    remember_int[re] = j;   
                                    re++;   
                                }   
      
      
      
                                //har, car 등 문자가 겹쳤을 때 나오지 않는 문제 해결 + 출력-- 끝 --   
     
                    }   
                   
            }   
      
            printf("\n");   
            k--;   
    }   
  
    return 0;   
}   
      
//계수정렬 함수.   
/**************   
변형없이 기존의 계수정렬 함수를 사용함.   
대신 main에서 배열인자를 넘겨줄 때 각 자리수의 문자만 나열한 임시 배열을 따로 만들어서 넘겨줌.   
****************/
char countingSort(char a[], char b[], int n)   
{   
    //a[] 입력배열   
    //b[] 배열을 정렬한 결과   
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