class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        int count = 0;
        int first = -1;
        int second = -1;
        for(int i = 0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                count++;
                if(first == -1){
                    first = i;
                }
                else if(second == -1){
                    second = i;
                }
                else{
                    return false;
                }
            }
        }
        if(first == -1 || second == -1) return false;
        if(s1[first] == s2[second] && s1[second] == s2[first]){
            return true;
        }
        return false;
    }
};