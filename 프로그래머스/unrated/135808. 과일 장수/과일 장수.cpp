#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int i1, int i2) {
    return i1 > i2;    
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), compare);
    
    //for (auto s : score) cout << s << " ";
    //cout << "\n";
    
    int count = m;
    int min = 10;
    for (int i = 0; i < score.size(); i++) {
        if (min > score[i]) min = score[i];
        
        count--;
        if (count == 0) {
            answer += min * m;
            //cout << m << " : " << min << "\n";
            count = m;
            min = 10;
        }
    }

    
    return answer;
}