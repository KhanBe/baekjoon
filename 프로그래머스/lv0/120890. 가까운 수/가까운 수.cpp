#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int min = 1000000;
    
    sort(array.begin(), array.end());
    
    for (int i = 0; i < array.size(); i++) {
        if (min > abs(n - array[i])) {
            min = abs(n - array[i]);
            answer = array[i];
        }
    }
    return answer;
}