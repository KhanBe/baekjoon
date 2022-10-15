#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int t) {
    int answer = n;
    
    answer *= pow(2, t);
    
    return answer;
}