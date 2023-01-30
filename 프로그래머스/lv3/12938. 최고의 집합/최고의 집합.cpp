#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int div = s / n;//4
    int mod = n - s % n;// 2 - 1

    if (!div) {//-1 일경우
        answer.push_back(-1);
        return answer;
    }

    for (int i = 0; i < mod; i++)
        answer.push_back(div);

    for (int i = mod; i < n; i++)
        answer.push_back(div + 1);

    return answer;
}