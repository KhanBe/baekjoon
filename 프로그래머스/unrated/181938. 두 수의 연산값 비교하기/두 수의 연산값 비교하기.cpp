#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    
    string ab = to_string(a) + to_string(b);
    int ab2 = a * b * 2;
    
    return stoi(ab) >= ab2 ? stoi(ab) : ab2;
}