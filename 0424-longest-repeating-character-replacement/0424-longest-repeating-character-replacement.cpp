class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxlen = 0,  maxfreq = 0;
        int map[26] = {0};
        while(right<size(s)){
            map[s[right] - 'A']++;
            maxfreq = max(maxfreq,map[s[right] - 'A']);
            if((right - left + 1) - maxfreq >k){
                map[s[left] - 'A']--;
                maxfreq = 0;
                // for(int i = 0;i<25;i++){
                //     maxfreq = max(maxfreq,map[i]);
                // }
                left++;
            }
            if((right - left + 1) - maxfreq <= k){
                maxlen = max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};