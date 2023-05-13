#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    
    for (auto n : number) answer += n - '0';

    return answer % 9;
}