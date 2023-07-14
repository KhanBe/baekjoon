#include <string>
#include <vector>
#include <array>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    array<int, 31> arr = {0,};
    
    for (auto sa : strArr) {
        arr[sa.length()]++;
        
        answer = arr[sa.length()] > answer ? arr[sa.length()] : answer;
    }
    return answer;
}