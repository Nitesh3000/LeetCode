class Solution {
    int rob1(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int maxAmount = dp[0];
        for (int i = 2; i < nums.size(); i++) {

            // for(int j = 0;j<i-1;j++){
            maxAmount = max(maxAmount, dp[i - 2]);
            // }
            dp[i] = maxAmount + nums[i];
        }
        return max(dp[dp.size() - 1], dp[dp.size() - 2]);
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> temp1(nums.begin(), nums.end() - 1),
            temp2(nums.begin() + 1, nums.end());
        int first = rob1(temp1);
        int second = rob1(temp2);
        return max(first, second);
    }
};