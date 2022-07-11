class Solution {
public:
    
int BinarySearch(vector<int>& array, int size, int value){
    int first = 0, last = size - 1, mid;

	while(true){
		mid = (first + last) / 2;

		if(value < array[mid])
			first = mid + 1;
		else if(value > array[mid])
			last = mid - 1;
		else
            return mid;
	}
}
    
void QuickSort(vector<int>& arr, int left, int right){
    if(left < right){
        int l = left, r = right;
        int mid = arr[(left + right) / 2];
        while(l <= r){
            while(arr[l] > mid) l++;
            while(arr[r] < mid) r--;
            if(l <= r) swap(arr[l++], arr[r--]);
        }
        QuickSort(arr, left, r);
        QuickSort(arr, l, right);
    }
}
    
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        vector<string> ans;
        
        QuickSort(sorted, 0, sorted.size() - 1);
        
        for(int i = 0; i < score.size(); i++){
            // cout << score[i] << " " << sorted[i] << endl;
            int pos = BinarySearch(sorted, sorted.size(), score[i]);
            if(pos == 0) ans.push_back("Gold Medal");
            else if(pos == 1) ans.push_back("Silver Medal");
            else if(pos == 2) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(pos + 1));
        }
        
        return ans;
    }
};