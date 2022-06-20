// stack в готовом шаблоне

#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<int> st;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        st.push(num);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}