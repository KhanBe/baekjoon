#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    bool flag = true;
    stack<int> st;
    vector<char> answer;
    int count = 1;
    int value;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)//n회 입력
    {
        cin >> value;//현재 입력된 수
        while (count <= value)
        {
            st.push(count);
            answer.push_back('+');
            count++;
        }
        if (st.top() == value)
        {
            st.pop();
            answer.push_back('-');
        }
        else
            flag = false;
    }
    if (!flag)
        cout << "NO\n";
    else
    {
        for (auto v : answer)
        {
            cout << v << "\n";
        }
    }
}