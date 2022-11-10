#include <string>
#include <vector>

using namespace std;

bool have_three(int n) {
    while (n > 0) {
        if (n % 10 == 3) return true;
        
        n /= 10;
    }
    return false;
}

int solution(int n) {
    int answer = 0;
    vector<int> v;
    
    int count = 1;
    while (v.size() != 100) {
        if (count % 3 == 0 || have_three(count)) {
            count++;
            continue;
        }
        v.push_back(count);
        count++;
    }
    return v[n - 1];
}