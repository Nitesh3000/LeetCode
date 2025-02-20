class Solution {

public:
    string findDifferentBinaryString(vector<string>& nums) {
        int length = nums[0].size();
        string str = "";
        for(int i = 0;i<length;i++){
            if(nums[i][i] == '0'){
                str += '1';
            }
            else{
                str+='0';
            }
        }
        return str;
        
    }
};