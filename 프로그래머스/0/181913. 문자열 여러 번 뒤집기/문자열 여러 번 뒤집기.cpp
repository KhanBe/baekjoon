#include <string>
#include <vector>
#include <algorithm>

using namespace std;



string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    
    for (auto q : queries) {
        int start = q[0];
        int end = q[1];
        
        reverse(my_string.begin() + start, my_string.begin() + end + 1);
    }
    return my_string;
}