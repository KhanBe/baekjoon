#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int mul = 1;
    int sum = 0;
    
    for (auto num : num_list) {
        mul *= num;
        sum += num;
    }
    return mul < sum * sum ? 1 : 0;
}