class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff=INT_MAX;
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        
        for(int i = 0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = nums.size() - 1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target - sum)<minDiff){
                    minDiff = abs(target - sum);
                    ans = sum;
                }
                if(sum == target){
                 
                    return sum;
                    
                }
                else if(sum>target) k--;
                else j++;
            }
        }
        return ans;
    }
};