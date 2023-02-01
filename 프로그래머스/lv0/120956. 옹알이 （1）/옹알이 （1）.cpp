#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> words = {"aya", "ye", "woo", "ma"};
    
    //이 문제는 각 words를 찾아서 지우기만하면 문제가 생긴다. ex) "wyeoo" > "ye" 삭제 > "woo" > "woo" 삭제
    //그래서 찾아서 '.' 으로 치환해준다. ex) "wyeoo" > "ye" 삭제 > "w.oo" > "woo"삭제 불가능
    for (auto bab : babbling) {
        for (auto w : words) {
            if (bab.find(w) != string::npos) {//찾으면
                bab.replace(bab.find(w), w.length(), ".");
            } 
        }
        //cout << bab << "\n";
        bool can = true;
        for (auto b : bab) {
            if (b != '.') can = false;
        }
        if (can) answer++;
    }
    return answer;
}