#include <stdio.h>

int rec(int n);

int main(){
    int n;
    scanf("%d",&n);
    
    printf("%d",rec(n));
}

int rec(int n){
    if(n <= 0) return 0;
    else if(n == 1 || n == 2) return 1;
    return rec(n-1) + rec(n-2);
}