class Solution {
    int rob1(vector<int>& nums) {
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