#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int n = common.size() - 1;
    
    if (common[n] - common[n - 1] == common[n - 1] - common[n - 2])
        answer = common[n] + common[n] - common[n - 1 ];
    else 
        answer = common[n] * (common[n] / common[n - 1]);
    
    return answer;
}