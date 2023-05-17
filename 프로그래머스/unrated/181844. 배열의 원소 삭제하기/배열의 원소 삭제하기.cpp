#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    vector<bool> visited(1001);
    
    for (auto a : arr) visited[a] = true;
    for (auto dl : delete_list) visited[dl] = false;
    
    for (auto a : arr) {
        if (visited[a]) answer.push_back(a);
    }
    return answer;
}