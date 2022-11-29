#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int long long temp_num = num;
    
    while (answer < 500) {
        if (temp_num == 1) return answer;
            
        if (temp_num % 2 == 0) temp_num /= 2;
        else {
            temp_num *= 3;
            temp_num++;
        }
        answer++;
    }
    return -1;
}