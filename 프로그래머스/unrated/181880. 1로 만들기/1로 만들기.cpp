#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    for (auto num : num_list) {
        while (1 < num) {
            if (num % 2 != 0) num--;
            num /= 2;
            
            answer++;
        }
    }
    return answer;
}