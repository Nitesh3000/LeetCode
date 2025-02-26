class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<string> temp;
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        for(int i = 0;i<strs.size();i++){
            string temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            map[strs[i]].push_back(temp);
        }
        for(auto &[key,value]:map){
            res.push_back(value);
        }
        return res;

    }
};