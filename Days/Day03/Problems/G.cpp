#include <iostream>
#include <stack>
using namespace std;

int main(){

    string s; getline(cin, s);
    stack<int> st;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' or s[i] == '-' or s[i] == '*'){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            
            if(s[i] == '+') st.push(y + x);
            if(s[i] == '-') st.push(y - x);
            if(s[i] == '*') st.push(y * x);

        }
        else if(s[i] != ' ') st.push(s[i] - 48);
    }
    cout << st.top();
}

// Example
// 8 9 + 1 7 - *

// 8 -> [8]
// 9 -> [9, 8]
// + -> [17]
// 1 -> [1, 17]
// 7 -> [7, 1, 17]
// - -> [-6, 17]
// * -> [-102]