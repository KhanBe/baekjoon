#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;//받는 콜라병
    
    while (n >= a){
        answer += (n / a) * b;
        n = ((n / a) * b) + n % a;
    }
    
    return answer;
}
