#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    //map은 기본적으로 key를 기준으로 정렬되어있음 오름차순
    map<int, int> mp;
    for (int i = 0; i < emergency.size(); i++) {
        mp.insert({emergency[i], i + 1});
    }
    
    for (auto m : mp) {
        answer.push_back(emergency.size() - m.second + 1);
    }
    return answer;
}