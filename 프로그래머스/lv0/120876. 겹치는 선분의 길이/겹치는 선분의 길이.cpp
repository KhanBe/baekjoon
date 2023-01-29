#include <string>
#include <vector>
#include <array>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    array<int, 201> arr = {0,};
    
    
    for (auto l : lines) {
        for (int i = l[0]; i < l[1]; i++) {
            arr[i + 100]++;
        }
    }
    
    for (auto a : arr) {
        if (a > 1) answer++;
    }
    return answer;
}