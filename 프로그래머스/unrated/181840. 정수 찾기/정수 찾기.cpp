#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    for (auto nl : num_list) {
        if (nl == n) return 1;
    }
    return 0;
}