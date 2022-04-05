#include <stdio.h>

int main(){
    int testCase,n;
    scanf("%d",&testCase);
    
    for(int i=0;i<testCase;i++){
        scanf("%d",&n);
        
        double score[n];
        double sum=0;
        for(int j=0;j<n;j++){
            scanf("%lf",&score[j]);
            sum += score[j];
        }
        double avg = sum/(double)n;
        
        double count = 0;
        for(int j=0;j<n;j++){
            if(score[j] > avg) count++;
        }
        printf("%.3f%%\n",count/(double)n*100);
    }
}