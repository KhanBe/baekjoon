#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int k;
    int n;
    int result = 0;
  
    cin >> k;
    
    stack<int> st;
    
    for(int i = 0; i<k;i++){
        cin >> n;
        if (n == 0) st.pop();
        else st.push(n);
    }
    
    while (!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result << endl;
}