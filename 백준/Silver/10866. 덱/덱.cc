#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    deque<int> dq;

    string command;
    int pushValue;
    int answer = 0;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command;

        if (command == "push_front"){
            cin >> pushValue;
            dq.push_front(pushValue);
        }
        else if (command == "push_back"){
            cin >> pushValue;
            dq.push_back(pushValue);
        }
        else if (command == "pop_front"){
            if (dq.empty()) answer = -1;
            else{
                answer = dq.front();
                dq.pop_front();
            }
        }
        else if (command == "pop_back"){
            if (dq.empty()) answer = -1;
            else{
                answer = dq.back();
                dq.pop_back();
            }
        }
        else if (command == "size") answer = dq.size();
        else if (command == "empty"){
            if(dq.empty()) answer = 1;
            else answer = 0;
        }
        else if (command == "front"){
            if (dq.empty()) answer = -1;
            else answer = dq.front();
        }
        else if (command == "back"){
            if (dq.empty()) answer = -1;
            else answer = dq.back();
        }
        if (!(command == "push_back" || command == "push_front"))
            cout << answer << "\n";
    }
}//직관적이게 코딩