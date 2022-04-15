#include <stdio.h>

int rec(int n);

int main(){
    int n;
    scanf("%d",&n);
    
    printf("%d",rec(n));
}

int rec(int n){
    if(n < 1) return 1;
    
    return n * rec(n-1);
}
