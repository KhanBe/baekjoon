#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    vector<int> v1;
    
    for (int i = 0; i < t.length() - p.length() + 1; i++) {
        string s(t, i, p.length());
        if (p >= s) answer++;
        cout << s << " : " << p << "\n";
    }
    return answer;
}