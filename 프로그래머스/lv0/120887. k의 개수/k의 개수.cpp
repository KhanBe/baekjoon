#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for (int a = i; a <= j; a++) {
        int temp = a;
        while (temp > 0) {
            if (temp % 10 == k) answer++;
            
            temp /= 10;
        }
    }
    return answer;
}