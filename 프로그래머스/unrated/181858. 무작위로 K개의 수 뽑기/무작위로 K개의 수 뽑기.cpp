#include <string>
#include <vector>
#include <array>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    array<int, 100001> visited = {0,};
    
    for (int i = 0; i < arr.size(); i++) {
        if (answer.size() >= k) break;
        
        if (!visited[arr[i]]) {
            visited[arr[i]] = true;
            answer.push_back(arr[i]);
        }
    }
    
    while (answer.size() < k) answer.push_back(-1);
    return answer;
}