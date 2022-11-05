#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    
    if (A == B) return 0;
    
    for (int i = 0; i < A.length(); i++) {
        answer++;
        
        string end_str = "";
        end_str = A[A.length() - 1];
        
        A.insert(0, end_str);
        A.erase(A.length() - 1);
        
        if (A == B) return answer;
        
    }
    return -1;
}