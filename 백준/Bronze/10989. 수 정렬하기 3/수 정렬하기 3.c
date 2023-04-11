#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    
    int num[10001] = {0,};
    
    int n;
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        num[n]++;
    }
    for(int i=1;i<10001;i++){
        if(num[i] == 0) continue;
        else{
            for(int j=0;j<num[i];j++) printf("%d\n",i);
        }
    }
}
