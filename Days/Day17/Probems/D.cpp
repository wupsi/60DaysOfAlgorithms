#include <iostream>
using namespace std;

int main(){

    int size; cin >> size;
    int ToBeFound[size];

    for(int i = 0; i < size; i++)
        cin >> ToBeFound[i];

    int n, m; cin >> n >> m;
    int arr[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    for(int i = 0; i < size; i++){
        int leftPos = -1, rightPos = -1;
        for(int j = 0; j < n; j++){
            int first = 0, last = m - 1;
            if(j % 2 == 0){
                while(true){
                    int mid = (first + last) / 2;
                    if(ToBeFound[i] > arr[j][first] or ToBeFound[i] < arr[j][last] or first > last) break;

                    if(ToBeFound[i] < arr[j][mid]) first = mid + 1;
                    else if(ToBeFound[i] > arr[j][mid]) last = mid - 1;
                    else{
                        leftPos = j;
                        rightPos = mid;
                        break;
                    }
                }   
            }
            else{
                while(true){
                    int mid = (first + last) / 2;
                    if(ToBeFound[i] < arr[j][first] or ToBeFound[i] > arr[j][last] or first > last) break;

                    if(ToBeFound[i] > arr[j][mid]) first = mid + 1;
                    else if(ToBeFound[i] < arr[j][mid]) last = mid - 1;
                    else{
                        leftPos = j;
                        rightPos = mid;
                        break;
                    }
                }   

            }
            if(rightPos != -1) break;
        }
        if(rightPos == -1) cout << "-1\n";
        else cout << leftPos << " " << rightPos << endl;
    }
}