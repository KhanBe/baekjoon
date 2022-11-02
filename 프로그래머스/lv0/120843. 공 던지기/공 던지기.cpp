#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    int index = (k - 1) * 2;
    index = index % numbers.size();
    
    return numbers[index];
}