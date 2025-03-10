class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
        [abcde] [ace] dp[i][j] = 1+dp[i-1][j-1] if match
                                else max(dp[i][j-1],dp[i-1][j])
              a   c   e
          [0, 0, 0, 0]
        a[0, 1, 0, 0]
        b[0, 1, 1, 1]
        c[0, 1, 2, 2]
        d[0, 1, 2, 2]
        e[0, 1, 2, 3]
        
        */
         int n = text1.size();
         int m =  text2.size();

         vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
         for(int i = 0;i<=n;i++) dp[i][0] = 0;
         for(int j = 0;j<=m;j++)  dp[0][j] = 0;  
         for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
         }
         return dp[n][m];
    }
};