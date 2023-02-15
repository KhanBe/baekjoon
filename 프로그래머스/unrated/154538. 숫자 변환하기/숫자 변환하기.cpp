#include <string>
#include <vector>
#include <queue>
#include <array>
#include <iostream>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0;
    
    array<int, 1000001> arr = {0,};
    
    queue<int> q; 
    q.push(x);
    
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        array<int, 3> calc = {num + n, num * 2, num * 3};
        
        for (int i = 0; i < 3; i++) {
            int next = calc[i];
            
            if (next > y) continue ;
            
            //이전에 arr[next]값이 높았으면 최소값으로 다시 줄이기 위해
            if (arr[next] == 0 || arr[next] > arr[num] + 1) {
                arr[next] = arr[num] + 1;
                q.push(next);
            }
        }
    }
    //for (int i = 1; i <= 40; i++) cout << arr[i] << " ";
    return arr[y] == 0 ? -1 : arr[y];
}