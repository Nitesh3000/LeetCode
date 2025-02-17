class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        s1 = a  b

        s2 = e  i   b   d   a   o   o   o
                i   j
        */
        if(s1.size()>s2.size()) return false;
        vector<int> s1map(26,0);
        vector<int> s2map(26,0);
    
        for(char c:s1){
            s1map[c - 'a']++;
        }
        int start = 0;
        int end = 0;
        while(end<s1.size()){
            s2map[s2[end] - 'a']++;
            end++;
        }
        if(s1map == s2map) return true;
        while(end<s2.size()){
            s2map[s2[start] - 'a']--;
            s2map[s2[end] - 'a']++;
            start++;
            end++;
            if(s1map == s2map) return true;
        }
        return false;
    }
};