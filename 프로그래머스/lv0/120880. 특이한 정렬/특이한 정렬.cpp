
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    // 괄호 < : 오름차순기준
    // 괄호 > : 내림차순기준
    
    //second값 비교시 다르면 second(value)기준 오름차순
    if (a.second != b.second) return a.second < b.second;
    //second값 비교시 같으면 first(key)기준 내림차순
    return a.first > b.first;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    map<int, int> mp;
    
    //map값 넣기
    for (auto  num : numlist) {
        mp.insert({num, abs(n - num)});
    }
    
    vector<pair<int, int>> vec(mp.begin(), mp.end());
    
    sort(vec.begin(), vec.end(), comp);
    
    for (auto v : vec) answer.push_back(v.first);
    
    return answer;
}