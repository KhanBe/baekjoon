#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto com : commands) {
        int firstIndex = com[0] - 1;
        int secondIndex = com[1] - 1;
        int numberIndex = com[2] - 1;
        vector<int> temp;
        for (int i = firstIndex; i <= secondIndex; i++) {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[numberIndex]);
    }
    return answer;
}