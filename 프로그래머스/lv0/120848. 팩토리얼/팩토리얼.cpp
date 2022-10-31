#include <string>
#include <vector>

using namespace std;

int facto(int n) {
    if (n == 1 || n == 0) return 1;
    return n * facto(n - 1);    
}

int solution(int n) {
    int answer = 0;
    
    int i = 0;
    while (true) {
        i++;
        if (facto(i) > n) {
            answer = i - 1;
            break;
        }
    }
    return answer;
}