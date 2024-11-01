#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bin_search(long long left, long long right, long long n, vector<int> times) {
    long long answer = 0;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        
        for (auto t : times) sum += mid / t;
        
        if (sum < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            answer = mid;
        }
        
    }
    return answer;
    
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    return bin_search(0, times[times.size() - 1] * (long long)n, n, times);;
}