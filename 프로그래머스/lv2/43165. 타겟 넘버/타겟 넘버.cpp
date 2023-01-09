#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int depth, int target, int cal) {
    if (depth == numbers.size()) {
        if (cal == target) answer++;
        return ;
    }
    dfs(numbers, depth + 1, target, cal + numbers[depth]);
    dfs(numbers, depth + 1, target, cal - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 1, target, numbers[0]);
    dfs(numbers, 1, target, -numbers[0]);
    return answer;
}