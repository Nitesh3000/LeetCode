class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        if(s.size() == 0){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }

        int maxlen = 1;

        unordered_set<int> set;

        while(end<s.size()){
            if(set.contains(s[end])){
                while(set.contains(s[end])){
                    set.erase(s[start]);
                    start++;
                }
            }
            set.insert(s[end]);
            maxlen = max(maxlen,end-start+1);
            end++;
        }
        return maxlen;
    }
};