class Solution {
public:
    bool check(vector<int>& nums) {
        int decreased = 0;
        
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                decreased++;
                // cout<<nums[i-1]<<" "<<nums[i]<<endl;
            }
            if(decreased==2){
                return false;
            }
        }
        if(nums[0]<nums[nums.size()-1]){
            decreased++;
        }
        return decreased<2;
    }
};