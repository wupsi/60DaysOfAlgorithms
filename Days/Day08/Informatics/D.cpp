#include <iostream>
#define null 1e9
using namespace std;

int main(){
    int n, m, cnt = 0, max; 
    cin >> n >> m;
    int arr[n][m], arrmax[m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 0; i < m; i++) arrmax[i] = null;   

    for(int i = 0; i < n; i++){
        int min = arr[i][0];
        for(int j = 1; j < m; j++) if(min > arr[i][j]) min = arr[i][j];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == min){
                if(arrmax[j] != null) max = arrmax[j];
                else{
                    max = arr[i][j];
                    for(int k = 0; k < n; k++) if(max < arr[k][j]) max = arr[k][j];
                    arrmax[j] = max;
                }
                if(max == min) cnt++;
            }
        }
    }
    cout << cnt;
}