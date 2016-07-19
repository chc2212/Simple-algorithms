#include <stdio.h> 
  
int main() 
{ 
    //변수선언 
    int n = 0; 
    int temp=0; // 값 교환을 위한 변수 
    int a[100] = {0,}; 
    int start, end; // 아직 버블정렬 되지 않은 값들의 시작과 끝 
    int complete = 0; //정렬이 완료 되었는지 체크해주는 변수 
  
    //값 입력 받기. 
    scanf("%d",&n); 
    for(int i=0; i<n; i++) 
        scanf("%d",&a[i]); 
  
    start = 0; 
    end = n-1; 
  
    while(1)  //무한루프 중간에 break;로 종료 조건 줌. 
    { 
        //☆☆☆☆오른쪽 방향정렬 + 출력 시작 
        for(int i=start; i<=end-1; i++) 
            if(a[i] > a[i+1]) 
            { 
                temp = a[i+1]; 
                a[i+1] = a[i]; 
                a[i] = temp; 
  
                complete++;//완료조건 때문에 
            } 
  
            for(int i=start; i<=end;i++) 
                printf(" %d",a[i]); 
  
            printf("\n"); 
  
            end = end-1; 
  
            //★★★★★오른쪽 방향정렬 + 출력 끝 
  
            //완료조건 검사. 
            if(complete == 0) 
                break; 
            complete = 0;// 완료조건 초기화 
  
            //☆☆☆☆왼쪽 방향정렬 + 출력 시작 
            for(int i=end-1; i>=start; i--) 
                if(a[i] > a[i+1]) 
                { 
                    temp = a[i+1]; 
                    a[i+1] = a[i]; 
                    a[i] = temp; 
  
                    complete++; //완료조건 때문에 
                } 
  
                for(int i=start; i<=end;i++) 
                    printf(" %d",a[i]); 
  
                printf("\n"); 
  
                start = start +1; 
  
                //★★★★★왼쪽 방향정렬 + 출력 끝 
  
                //완료조건 검사. 
                if(complete == 0) 
                    break; 
                complete = 0;// 완료조건 초기화 
  
    } 
  
    //최종 값 출력 
    for(int i=0; i<n; i++) 
        printf(" %d",a[i]); 
  
    return 0; 
} 
/************************************************************** 
    Problem: 1031 
    User: 091895 
    Language: C++ 
    Result: Accepted 
    Time:0 ms 
    Memory:864 kb 
****************************************************************/