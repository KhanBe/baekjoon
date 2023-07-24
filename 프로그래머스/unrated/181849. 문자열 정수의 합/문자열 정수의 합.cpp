#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    
    for (auto n : num_str) {
        answer += n - '0';
    }
    return answer;
}