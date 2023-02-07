#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

//비교
bool compare (pair<int, int> &m1, pair<int, int> &m2) {
    return m1.second > m2.second;    
}

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size(), 0);

    vector<pair<int, int>> scoring;
    
    for (int i = 0; i< score.size(); i++) {
        scoring.push_back({i + 1, score[i][0] + score[i][1]});
    }
    
    sort(scoring.begin(), scoring.end(), compare);
    
    //for (auto s : scoring) cout << s.first << " : " << s.second << "\n";
    
    int before_score = 0;
    int equal_score = 0;
    for (int i = 0; i < scoring.size(); i++) {
        
        //이전 점수와 동일하면 equal_score 증가
        if (before_score == scoring[i].second) equal_score++;
        else equal_score = 0;
        
        before_score = scoring[i].second;
        
        //증가된 equal_score를 빼줘서 공동 등수를 만든다
        answer[scoring[i].first - 1] = i + 1 - equal_score; 
    }
    return answer;
}