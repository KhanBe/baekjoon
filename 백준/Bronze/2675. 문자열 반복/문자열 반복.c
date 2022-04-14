#include <stdio.h>
#include <string.h>

int main(){
    int c,n;
    
    scanf("%d",&c);//케이스
    
    for(int i=0;i<c;i++){
        char arr[21];
        scanf("%d %s",&n,arr);//문자열
        
        for(int j=0;j<strlen(arr);j++){
            for(int k=0;k<n;k++)
                printf("%c",arr[j]);
        }
        printf("\n");
    }
}