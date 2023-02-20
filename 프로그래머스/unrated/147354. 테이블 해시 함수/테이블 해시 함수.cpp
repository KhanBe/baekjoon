#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int column;

//xor, or, and 연산과
//compare 재정의 부분을 다룰줄 알면 쉬워진다.
bool compare(vector<int> v1, vector<int> v2) {
    if (v1[column] == v2[column]) return v1[0] > v2[0];
    return v1[column] < v2[column];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col - 1;
    
    sort(data.begin(), data.end(), compare);
    
    for (int i = row_begin - 1; i <= row_end - 1; i++) {
        int S_i = 0;
        
        for (int j = 0; j < data[i].size(); j++) {
            S_i += data[i][j] % (i + 1);
        }
        answer ^= S_i;
    }
    
    return answer;
}