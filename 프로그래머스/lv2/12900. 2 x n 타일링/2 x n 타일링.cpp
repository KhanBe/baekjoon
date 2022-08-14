#include <string>
#include <array>

using namespace std;

int solution(int n) {
    array<int, 60001> memori = {0, 1, 2,};
    
    int answer = 0;

    for (int i = 3; i <= n; i++){
        memori[i] = memori[i - 1] + memori[i - 2];
        memori[i] %= 1000000007;
    }
    
    return memori[n];
}