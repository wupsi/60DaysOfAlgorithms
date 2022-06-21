#include <iostream>
#include <deque>
using namespace std;

int main(){

    int n, x; cin >> n;
    char c;
    deque<int> dq, dq1;

    for(int i = 0; i < n; i++){
        
        cin >> c;

        if(c == '+'){
            cin >> x;
            if(dq1.empty()) dq1.push_front(x);
            else dq.push_front(x);
        }

        else if(c == '*'){
            cin >> x;
            dq.push_back(x);
        }


        else if(c == '-'){
            cout << dq1.back() << endl;
            dq1.pop_back();
        }

        if(dq.size() > dq1.size()){
            dq1.push_front(dq.back());
            dq.pop_back();
        }
    }

    return 0;
}