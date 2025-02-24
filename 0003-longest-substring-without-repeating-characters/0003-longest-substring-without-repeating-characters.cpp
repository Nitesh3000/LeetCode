class Solution {
/*
a   b   c   a   b   c   b    b 

*/

public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int res = 0;
        unordered_set<int> set;
        while(end<s.size()){
            if(set.find(s[end]) == set.end()){
                set.insert(s[end++]);
                res = max(end-start,res);
            }
            else{
                while(set.find(s[end])!=set.end()){
                    set.erase(s[start++]);
                }
            }
        }
        return res;
    }
};