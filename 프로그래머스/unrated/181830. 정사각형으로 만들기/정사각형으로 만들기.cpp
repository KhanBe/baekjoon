#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    
    int row = arr[0].size();
    int column = arr.size();
    
    int max = row > column ? row : column;
    
    answer.resize(max);
    for (int i = 0; i < max; i++) {
        answer[i].resize(max);
    }
    
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            answer[i][j] = arr[i][j];
        }
    }
    return answer;
}