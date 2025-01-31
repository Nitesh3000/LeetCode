class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int minLength = INT_MAX;
        int sum = 0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target && start<=end){
                    minLength = min(minLength,end-start+1);
                sum-=nums[start++];
            }
            end++;
        }
        if(sum>=target){
            minLength = min(minLength,end-start+1);
        }
        if(minLength == INT_MAX)
            return 0;
        else{
            return minLength;
        }
    }
};