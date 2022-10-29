#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> data(1001);
    
    //개수 넣기
    for (auto a : array) {
        data[a]++;
    }
    
    //최대값 구하기
    int max = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] > max) {
            max = data[i];
            answer = i;
        }
    }
    
    //최대값 개수 구하기
    int max_count = 0;
    for (int d : data) {
        if (d == max) max_count++;
    }
    return max_count == 1 ? answer : -1;
}