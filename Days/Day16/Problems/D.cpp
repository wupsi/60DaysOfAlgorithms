class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0, right = 0, mid = 0;
        vector<int> newNums1 = nums1;
        
        while(left < m and right < n){
            if(newNums1[left] <= nums2[right])
                nums1[mid++] = newNums1[left++];
            else
                nums1[mid++] = nums2[right++];
        }
        
        while(left < m)
            nums1[mid++] = newNums1[left++];
        while(right < n)
            nums1[mid++] = nums2[right++];
    }
};