class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.push_back(0);
        int n = cost.size()-1;
        dp.push_back(cost[n]);
        bool flag = true;
        for(int i = n-1;i>=0;i--){
            if(flag){
                dp[0] = min(dp[0],dp[1])+cost[i];
                flag = false;
            }
            else{
                dp[1] = min(dp[0],dp[1])+cost[i];
                flag = true;
            }
        }
        return min(dp[0],dp[1]);
    }
};