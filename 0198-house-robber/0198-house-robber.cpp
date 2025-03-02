class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        nums = [1,2,3,1]
                0,1,2,3
            dp=[1,2,4,3]
        nums = [2,7,9,3,1]
                0,1,2,3,4
            dp=[2,7,11,10,12]

        
        */
        if (nums.size() == 1)
            return nums[0];
        // vector<int> dp(nums.size(), 0);
        int first = nums[0];
        int second = nums[1];
        int maxAmount = nums[0];
        for (int i = 2; i < nums.size(); i++) {

            // for(int j = 0;j<i-1;j++){
            maxAmount = max(maxAmount, first);
            // }
            int temp = maxAmount + nums[i];

            first = second;
            second = temp;
        }
        return max(second, first);
    }
};