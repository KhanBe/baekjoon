#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.length() == 6 || s.length() == 4) {
        for (auto c : s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    return false;
}