#include <stdio.h> 
  
int main() 
{ 
    //�������� 
    int n = 0; 
    int temp=0; // �� ��ȯ�� ���� ���� 
    int a[100] = {0,}; 
    int start, end; // ���� �������� ���� ���� ������ ���۰� �� 
    int complete = 0; //������ �Ϸ� �Ǿ����� üũ���ִ� ���� 
  
    //�� �Է� �ޱ�. 
    scanf("%d",&n); 
    for(int i=0; i<n; i++) 
        scanf("%d",&a[i]); 
  
    start = 0; 
    end = n-1; 
  
    while(1)  //���ѷ��� �߰��� break;�� ���� ���� ��. 
    { 
        //�١١١ٿ����� �������� + ��� ���� 
        for(int i=start; i<=end-1; i++) 
            if(a[i] > a[i+1]) 
            { 
                temp = a[i+1]; 
                a[i+1] = a[i]; 
                a[i] = temp; 
  
                complete++;//�Ϸ����� ������ 
            } 
  
            for(int i=start; i<=end;i++) 
                printf(" %d",a[i]); 
  
            printf("\n"); 
  
            end = end-1; 
  
            //�ڡڡڡڡڿ����� �������� + ��� �� 
  
            //�Ϸ����� �˻�. 
            if(complete == 0) 
                break; 
            complete = 0;// �Ϸ����� �ʱ�ȭ 
  
            //�١١١ٿ��� �������� + ��� ���� 
            for(int i=end-1; i>=start; i--) 
                if(a[i] > a[i+1]) 
                { 
                    temp = a[i+1]; 
                    a[i+1] = a[i]; 
                    a[i] = temp; 
  
                    complete++; //�Ϸ����� ������ 
                } 
  
                for(int i=start; i<=end;i++) 
                    printf(" %d",a[i]); 
  
                printf("\n"); 
  
                start = start +1; 
  
                //�ڡڡڡڡڿ��� �������� + ��� �� 
  
                //�Ϸ����� �˻�. 
                if(complete == 0) 
                    break; 
                complete = 0;// �Ϸ����� �ʱ�ȭ 
  
    } 
  
    //���� �� ��� 
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