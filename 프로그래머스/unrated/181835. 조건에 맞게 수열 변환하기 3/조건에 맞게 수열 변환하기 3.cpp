#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = k % 2 == 0 ? arr[i] + k : arr[i] * k;
    }
    return arr;
}