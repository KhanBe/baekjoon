#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(int mid, int k, vector<int> & stones) {
    int count = 0;
    
    for (int i =0;i <stones.size(); i++) {
        if (stones[i] <= mid) count++;
        else count = 0;
        
        if (k <= count) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int start = 1;
    int end = *max_element(stones.begin(), stones.end());
    int mid = 0;
    
    while (start <= end) {
        mid = (start + end) / 2;
        
        if (binary_search(mid, k, stones)) start = mid + 1;
        else end = mid - 1;
    }
    
    
    
    return start;
}