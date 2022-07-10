class Solution {
public:
    
    void QuickSort(vector<int>& arr, int left, int right){
        if(left < right){
            int l = left, r = right;
            int mid = arr[(left + right) / 2];
            while(l <= r){
                while(arr[l] < mid) l++;
                while(arr[r] > mid) r--;
                if(l <= r) swap(arr[l++], arr[r--]);
            }
            QuickSort(arr, left, r);
            QuickSort(arr, l, right);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};