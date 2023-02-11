#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <stdlib.h>

using namespace std;

int get_int_time(string s) {
    int int_time = 0;
    string c_string = "";
    
    c_string = s[0];
    int_time += stoi(c_string) * 600;
    c_string = s[1];
    int_time += stoi(c_string) * 60;
    c_string = s[3];
    int_time += stoi(c_string) * 10;
    c_string = s[4];
    int_time += stoi(c_string);
    return int_time;    
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    array<int, 1440> arr_time = {0,};
    sort(book_time.begin(), book_time.end());
    
    for (auto b : book_time) {
        int int_start_time = get_int_time(b[0]);
        int int_finish_time = get_int_time(b[1]) + 9;//10분청소시간증가
        
        for (int i = int_start_time; i <= int_finish_time; i++) {
            arr_time[i]++;
        }

        
        //cout << int_start_time << " : " << int_finish_time << "\n";
    }
    for (auto a : arr_time) {
        if (answer < a) {
            answer = a;
        }
    }
    return answer;
}