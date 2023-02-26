#include <string>
#include <vector>
#include <array>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    array<int, 1000001> arr = {0,};
    
    for (int i = 0; i < elements.size(); i++) {
        for (int count = 1; count <= elements.size(); count++) {//2
            int get_count = 0;
            int sum = 0;
            while (get_count < count) {
                int index = i + get_count;
                
                if (index > elements.size() - 1) index -= elements.size();
                sum += elements[index];
                
                //cout << sum << " ";
                if (!arr[sum]) arr[sum] = 1;
                
                get_count++;
            }
        }
    }
    
    for (auto a : arr) if (a) answer++;
    return answer;
}