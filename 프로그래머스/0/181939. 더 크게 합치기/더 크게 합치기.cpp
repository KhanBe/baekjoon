#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    
    return stoi(s1) < stoi(s2) ? stoi(s2) : stoi(s1);
}