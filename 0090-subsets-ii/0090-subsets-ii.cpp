class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> s;
        backtracking(nums,0,temp,res,s);
        return res;
    }
    void backtracking(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& res, set<vector<int>>& s){
        vector<int> t = temp;
        sort(t.begin(),t.end());
        if(!s.contains(t)){
            
            s.insert(t);
            res.push_back(t);
        }
        while(i<nums.size()){
            temp.push_back(nums[i]);
            backtracking(nums,i+1,temp,res,s);
            temp.erase(temp.begin()+temp.size()-1);
            i++;
        }
    }
};