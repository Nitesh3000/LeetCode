class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        /*
        check for the conditions
        also see that 0 if multiplied by 0 will remain 0..so that should also be shifted
        */
        int i = 0;
        int count = 0;
        vector<int> res;
        while(i<nums.size()){
            if(i<nums.size()-1 && nums[i] != 0 && nums[i] == nums[i+1]){

                res.push_back(nums[i]*2);
                count++;
                i+=2;
            }
            else if(nums[i] == 0){
                count++;
                i++;
            }
            else{
                res.push_back(nums[i]);
                i++;
            }
        }
        for(int i = 0;i<count;i++){
            res.push_back(0);
        }
        return res;
    }
};