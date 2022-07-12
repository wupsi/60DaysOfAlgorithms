#include <iostream>
using namespace std;

int main(){

    int n, m; cin >> n >> m;
    int arr[n][m], sums[n], pos[n], mins[n];

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        sums[i] = sum;
        pos[i] = i;
        mins[i] = arr[i][0];
    }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(sums[i] < sums[j]){
                swap(sums[i], sums[j]);
                swap(pos[i], pos[j]);
                swap(mins[i], mins[j]);
            }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(mins[i] > mins[j] and sums[i] == sums[j]){
                swap(sums[i], sums[j]);
                swap(pos[i], pos[j]);
                swap(mins[i], mins[j]);
            }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(sums[i] == sums[j] and mins[i] == mins[j] and pos[i] > pos[j]){
                swap(sums[i], sums[j]);
                swap(pos[i], pos[j]);
                swap(mins[i], mins[j]);
            }
        
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << arr[pos[i]][j] << " ";   
        cout << endl;
    }

}