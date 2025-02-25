class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int minIndex = INT_MAX;
        for(int i = 0;i<strs.size();i++){
            minIndex = min((int)strs[i].size(),minIndex);
        }
        
        for(int i = 0;i<minIndex;i++){
            bool flag = true;
            for(int j = 1;j<strs.size();j++){
                if(strs[j][i] != strs[j-1][i]){
                    flag = false; 
                    break;
                }
            }
            if(flag){
                res+=strs[0][i];
            }
            else{
                break;
            }
        }
        return res;
    }
};