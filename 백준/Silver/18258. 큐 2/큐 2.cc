#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    queue<int> q;

    string command;
    int pushValue;
    int answer = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> command;

        if (command == "push"){
            cin >> pushValue;
            q.push(pushValue);
            continue;
        }
        else if (command == "pop"){
            if (q.empty()) answer = -1;
            else{
                answer = q.front();
                q.pop();
            }
        }
        else if (command == "size") answer = q.size();
        else if (command == "empty"){
            if (q.empty()) answer = 1;
            else answer = 0;
        }
        else if (command == "front"){
            if (q.empty()) answer = -1;
            else answer = q.front();
        }
        else if (command == "back"){
            if (q.empty()) answer = -1;
            else answer = q.back();
        }

        cout << answer << "\n";
    }
}