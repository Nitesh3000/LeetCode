class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        for(int i = 0;i<strs.size();i++){
            vector<int> count(26,0);
            for(int j = 0;j<strs[i].size();j++){
                count[strs[i][j]-'a']++;
            }
            cout<<endl;
            string key = "";
            for(int k = 0;k<26;k++){
                key+= " , " + to_string(count[k]);
            }
            map[key].push_back(strs[i]);
        }
        for(auto& [key,value]:map){
            res.push_back(value);
        }
        return res;
    }
};