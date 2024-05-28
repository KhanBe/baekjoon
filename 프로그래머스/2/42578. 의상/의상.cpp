#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    
    for (auto c : clothes) {
        um[c[1]] = um[c[1]] + 1;
    }
    
    for (auto iter : um) {
        answer *= (iter.second + 1);
        //cout << iter.first << " " << iter.second << " ";
    }
    return answer - 1;
}