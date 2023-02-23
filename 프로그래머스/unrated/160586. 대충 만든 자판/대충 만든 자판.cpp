#include <string>
#include <vector>
#include <array>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    array<int, 100> alpha = {0,};
    
    //배열에 최소 터치값 담기
    for (auto k : keymap) {
        for (int i = k.length() - 1; i >= 0; i--) {
            if (alpha[k[i]] == 0) alpha[k[i]] = i + 1;
            else if (alpha[k[i]] > i + 1) alpha[k[i]] = i + 1;
        }
    }
    
    for (auto target : targets) {
        int touch = 0;
        for (auto t : target) {
            touch += alpha[t];
        }
        if (touch == 0) touch = -1;
        answer.push_back(touch);
    }
    //for (auto a : alpha) cout << a << " ";
    
    return answer;
}