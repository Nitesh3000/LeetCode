class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int resultSum = nums[0]+nums[1]+nums[2];
        int minDifference = INT_MAX;
        
        for(int i = 0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == target){
                    return sum;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
                int difference = abs(sum-target);
                if(difference<minDifference){
                    minDifference = difference;
                    resultSum = sum;
                }
            }
        }
        return resultSum;
    }
};