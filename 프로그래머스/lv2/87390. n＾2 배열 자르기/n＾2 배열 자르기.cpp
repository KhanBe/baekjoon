#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int count = right - left + 1;
    
    //x, y 가 시작되는 인덱스
    int x = left % n;
    int y = left / n;
    
    while (count > 0) {
        answer.push_back(max(x + 1, y + 1));
        //cout << max(x + 1, y + 1) << "\n";
        x++;
        if (x >= n) {
            y++;
            x = 0;
        }
        
        count--;
    }
    return answer;
}