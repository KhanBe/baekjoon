#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    sort(indices.begin(), indices.end());
    
    int idx = 0;
    for (int i = 0; i < my_string.length(); i++) {
        
        if (indices[idx] == i) idx++;

        else answer += my_string[i];
    }
    
    return answer;
}