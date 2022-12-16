#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

//사용자 지정 compare
bool compare_vector_size(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();    
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vi;
    
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i++] == '{') {//'{' 이후부터 조건 실행
            int j = 0;
            string temp = "";
            while (s[i + j] != '}') {// '}' 이전까지 실행
                if (s[i + j] == ',') temp += " ";
                else temp += s[i + j];
                j++;
            }//{1,2,3} >> "1 2 3" 으로 값 저장 
            i = i + j - 1;//저장했던 index 까지 증가
            
            //2차원 int 배열에 저장
            int n = 0;
            stringstream ss(temp);
            vector<int> temp_vector;
            while (ss >> n) temp_vector.push_back(n);
            vi.push_back(temp_vector);
        }
    }
    
    sort(vi.begin(), vi.end(), compare_vector_size);
    
    //answer값
    for (auto i : vi) {
        for (auto ii : i) {
            if (find(answer.begin(), answer.end(), ii) == answer.end()) {
                answer.push_back(ii);
            }
        }
    }
    return answer;
}