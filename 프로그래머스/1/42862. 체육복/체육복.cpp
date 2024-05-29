#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    vector<int> lv(n + 2);
    vector<int> rv(n + 2);
    for (auto l : lost) lv[l] = true;
    for (auto r : reserve) rv[r] = true;

    
    for (int i = 1; i <= n; i++) {
        if (lv[i]) { //잃어버렸으면
            if (rv[i]) {//내가 여분있으면
                rv[i] = false;
                lv[i] = false;
                answer++;
            }
            else if (rv[i - 1]) {
                rv[i - 1] = false;
                lv[i] = false;
                answer++;
            }
            else if (rv[i + 1] && !lv[i + 1]) { //다음번호가 여분있고 잃어버리지 않았다면
                rv[i + 1] = false;
                lv[i] = false;
                answer++;
            }
        }
    }
    return answer;
}