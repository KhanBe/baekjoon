#include <string>
#include <array>

using namespace std;

int solution(int n) {
    // n이 홀수일 때에는 경우의 수가 0이고
    // n = 2 일때 3
    // n = 4 일때 11
    // n = 6 일때 41
    // n = 8 일때 153
    // 결국 n값은 = ([(n - 2)의 값] X 4) - [(n - 4) 값]이 된다.
	array<long, 50001> memoi = {1, 0, 3, 0, 11};
    
	int answer = 0;

	for (int i = 6; i <= n; i++) {
        if (i % 2 == 1) memoi[i] = 0;
        else {
            memoi[i] = ((memoi[i - 2] * 4) % 1000000007) + 1000000007 - (memoi[i - 4] % 1000000007);
            memoi[i] %= 1000000007;
        }
	}
	
	return memoi[n];
}