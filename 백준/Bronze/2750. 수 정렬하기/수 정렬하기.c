#include <stdio.h>

void sort(int *arr, int start, int end){
    
    if(start>=end){//엇갈리면
        return;
    }
    
    int pivot = start;    //피봇
    int i = pivot+1;    //i는 피봇 다음원소
    int j = end;    //j는 마지막 원소
    int temp;
    
    while(i<=j){//i가 더 커지면 종료
        //피봇 보다 큰 값 만날 때 까지
        while(i<=end && arr[i]<=arr[pivot]){
            ++i;
        }
        //피봇 보다 작은 값 만날 때 까지
        while(j>start && arr[j]>=arr[pivot]){
            --j;
        }
        
        //위에서 계산된 i와 j가 만나거나 엇갈리면 종료
        if(i>=j) break;
        
        //두 원소 교환
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    //피봇 정렬 완료
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    
    sort(arr, start, j-1);    //피봇 중심으로 왼쪽부분 분할
    sort(arr, j+1, end);    //피봇 중심으로 오른쪽부분 분할
}

int main(){
    
    int t;
    scanf("%d",&t);
    
    int arr[1001];
    for(int i=0;i<t;i++) scanf("%d",&arr[i]);
    
    sort(arr, 0, t-1);
    
    //출력
    for(int i=0;i<t;++i){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
