class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increase = 0, maxIncrease = 0;
        int decrease = 0, maxDecrease = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                ++decrease;
                maxDecrease = max(maxDecrease,decrease);
                increase = 0;
            }
            else if(nums[i-1]<nums[i]){
                ++increase;
                maxIncrease = max(maxIncrease,increase);
                decrease = 0;
            }
            else{
                increase = 0;
                decrease = 0;
            }
        }
        return max(maxIncrease,maxDecrease)+1;
    }
};