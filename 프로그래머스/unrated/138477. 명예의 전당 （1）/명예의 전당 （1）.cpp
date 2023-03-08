#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> rank;
    
    for (auto s : score) {
        rank.push_back(s);
        sort(rank.begin(), rank.end(), compare);
        
        if (k < rank.size()) {
            rank.erase(rank.end() - 1);
        }
        //cout << rank[rank.size() - 1] << " ";
        answer.push_back(rank[rank.size() - 1]);
    }
    return answer;
}