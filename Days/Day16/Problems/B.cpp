class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while(left < right){
            if(nums[left] % 2 != 0 and nums[right] % 2 != 0) right--;
            else if(nums[left] % 2 == 0 and nums[right] % 2 == 0) left++;
            else if(nums[left] % 2 != 0 and nums[right] % 2 == 0) swap(nums[left++], nums[right--]);
            else left++, right--;
        }
        
        return nums;    
    }
};