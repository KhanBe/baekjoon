#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    set<int> s;
    sort(sides.begin(), sides.end());
    
    for (int i = sides[1]; i < sides[0] + sides[1]; i++) {
        if (sides[0] + sides[1] > i) {
            s.insert(i);
        }
    }
    
    for (int i = 1; i < sides[1]; i++) {
        if (sides[0] + i > sides[1]) {
            s.insert(i);
        }
    }
    
    return s.size();
}