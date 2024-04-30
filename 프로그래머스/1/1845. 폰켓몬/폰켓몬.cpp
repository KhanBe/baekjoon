#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size() / 2;
    
    map<int, int> m;
    for (auto n : nums) {
        m.insert({n, 1});
    }
    if (m.size() < answer) answer = m.size();
    return answer;
}