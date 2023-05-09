#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = n % 2 == 1 ? 1 : 0;
    for (;i <= n; i += 2)  {
        if (n % 2 == 1) answer += i;
        else answer += i * i;
        cout << i << " ";
    }
    return answer;
}