class Solution {
public:
    // Using Tabulation
    int solve(vector<int>& dp, vector<int>& cost){
        dp[0] = 0;
        dp[1] =0;
        for(int i = 2; i<=cost.size(); i++){
            int left = dp[i-1] + cost[i-1];
            int right = dp[i-2] + cost[i-2];
            dp[i] = min(left,right);
        }

        return dp[cost.size()];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return solve(dp,cost);
    }
    // Time Complexity - O(N)
    // Space Complexity - O(N) for dp array
};
