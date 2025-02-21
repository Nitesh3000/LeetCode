class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n);
        dp[0] = true;
        dp[1] = false;
        for(int i = 2;i<=n;i++){
            for(int j = i/2;j>0;j=j/2){
                if(i%j == 0){
                    dp[i] = !(dp[i-j]);
                }
            }
        }
        return dp[n];
    }
};