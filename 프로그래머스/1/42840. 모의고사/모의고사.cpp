#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    unordered_map<int, int> st;
    st.insert({1, 0});
    st.insert({2, 0});
    st.insert({3, 0});
    
    for (int i = 0; i< answers.size(); i++) {
        if (answers[i] == arr1[i % arr1.size()]) st[1]++;
        if (answers[i] == arr2[i % arr2.size()]) st[2]++;
        if (answers[i] == arr3[i % arr3.size()]) st[3]++;
    }
    vector<pair<int, int>> v(st.begin(), st.end());
    sort(v.begin(), v.end(), cmp);
    
    answer.push_back(v[0].first);
    if (v[0].second == v[1].second) answer.push_back(v[1].first);
    if (v[0].second == v[2].second) answer.push_back(v[2].first);
    
    sort(answer.begin(), answer.end());
    //for (auto a : v) cout << a.first << " " << a.second << "\n";
    return answer;
}