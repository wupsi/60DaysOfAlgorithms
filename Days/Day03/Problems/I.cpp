#include <iostream>
#include <deque>
using namespace std;

int main(){

    int n, m, x; cin >> n;
    size_t cnt = 0;
    bool ok = true;
    deque<int> dq[n + 11];
    deque< pair<int, int> > ans;

    for(int i = 1; i <= n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> x;
            dq[i].push_back(x);
            if(x != i) ok = false;
            if(x == 1) cnt++;
        }
    }

    if(ok) return 0;
    else if(n < 2) return 0;
    else if(n >= 2){
        for(int i = 2; i <= n; i++){
            while(!dq[i].empty()){
                ans.push_back(make_pair(i, 1));
                dq[1].push_back(dq[i].back());
                dq[i].pop_back();
            }
        }

        if(n == 2){
            while(dq[1].back() != 1){
                ans.push_back(make_pair(1, 2));
                dq[2].push_back(dq[1].back());
                dq[1].pop_back();
            }
            if(dq[1].size() != cnt){
                cout << "0\n";
                return 0;
            }
        }

        else if(n > 2){
            while(!dq[1].empty()){
                if(dq[1].back() == 1 or dq[1].back() == 2){
                    ans.push_back(make_pair(1, 2));
                    dq[2].push_back(dq[1].back());
                    dq[1].pop_back();
                }
                else{
                    ans.push_back(make_pair(1, dq[1].back()));
                    dq[dq[1].back()].push_back(dq[1].back());
                    dq[1].pop_back();
                }
            }

            while(!dq[2].empty()){
                if(dq[2].back() == 1){
                    ans.push_back(make_pair(2, 1));
                    dq[1].push_back(dq[2].back());
                    dq[2].pop_back();
                }
                else if(dq[2].back() == 2){
                    ans.push_back(make_pair(2, 3));
                    dq[3].push_back(dq[2].back());
                    dq[2].pop_back();
                }
            }
            while(dq[3].back() != 3){
                ans.push_back(make_pair(3, 2));
                dq[2].push_back(dq[3].back());
                dq[3].pop_back();
            }
        }
    }
    
    deque< pair<int, int> > :: iterator it;
    for(it = ans.begin(); it != ans.end(); it++){
        cout << it->first << " " << it->second << endl;
    }    
}