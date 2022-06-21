#include <iostream>
using namespace std;

char st[100000];
int pos = 0;

char closed(char x){
	if(x == ')') return '(';
	if(x == ']') return '[';
	return '{';
}

int main(){

	string s; cin >> s;
	
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' or s[i] == '[' or s[i] == '{')
	        st[pos++] = s[i];
        else{
            if(st[pos - 1] == closed(s[i]))
				pos--;
            else{
				cout << "no";
				return 0;
			}
		}
	}

    cout << (pos == 0 ? "yes" : "no");

	return 0;
}