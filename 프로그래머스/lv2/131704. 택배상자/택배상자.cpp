#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int scale = order.size();
    //queue<int> first_con;
    stack<int> second_con;
    
    //for (int i = 1; i <= scale; i++) first_con.push(i);
    
    int first_con = 1;
  
    for (int order_num = 0; order_num < scale;) {
        while (order[order_num] > first_con) {
            second_con.push(first_con);
            first_con++;
        }
        if (order[order_num] == first_con) {
            order_num++;
            first_con++;
            answer++;
        }
        else if (!second_con.empty() &&second_con.top() == order[order_num]) {
            order_num++;
            second_con.pop();
            answer++;
        }
        else break;
    }
    return answer;
}