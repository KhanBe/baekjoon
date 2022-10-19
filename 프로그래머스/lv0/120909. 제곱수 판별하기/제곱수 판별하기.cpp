#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int temp = sqrt(n);
    
    if ((double)sqrt(n) == (double)temp) answer = 1;
    else answer = 2;
    return answer;
}