#include <string>
#include <vector>
#include <set>
#include <array>

using namespace std;

//set 특징 : 중복은 제거하고 정렬되어 insert된다.
int solution(vector<int> topping) {
    int answer = 0;
    
    array<int, 10001> my_arr = {0,};
    array<int, 10001> bro_arr = {0,};
    
    int my_count = 0;
    int bro_count = 0;
    for (auto t : topping) {
        bro_arr[t]++;
        if (bro_arr[t] == 1) bro_count++;
    }
    
    for (int i = 0; i < topping.size(); i++) {
        bro_arr[topping[i]]--;
        if (bro_arr[topping[i]] == 0) bro_count--;
        
        if (my_arr[topping[i]] == 0) my_count++;
        my_arr[topping[i]]++;
        
        if (my_count == bro_count) {
            answer++;
        }
    }
    
    /*set<int> s1;
    set<int> s2;
    
    for (int i = 0; i < topping.size(); i++) {// i가 기준이 된다.
        for (int j = 0; j <= i; j++) {//i 기준 앞부분
            s1.insert(topping[j]);
        }
        for (int k = i + 1; k < topping.size(); k++) {//i 기준 뒷부분
            s2.insert(topping[k]);
        }
        
        if (s1.size() == s2.size()) answer++;
        
        s1.clear();
        s2.clear();
    }*/
    return answer;
}