#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> mp;
    
    for (auto t : tangerine) mp[t]++;
    
    //꼭 map을 vector로 바꾸고 정렬가능함
    vector<pair<int, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), compare);
    
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        count += vec[i].second;
        if (k <= count) {
            answer = i + 1;
            break;
        }
    }
    
    //출력
    //for (auto v : vec) cout << v.first << " : " << v.second << "\n";
    return answer;
}