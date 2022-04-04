#include <vector>

using namespace std;

long long sum(vector<int> &a) {
	long long ans = 0;
    for (auto n : a) ans += n;
	return ans;
}
