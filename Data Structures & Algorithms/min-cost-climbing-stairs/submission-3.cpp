class Solution {
public:
    // Using Memoization
    int solve(int idx, vector<int>& cost, vector<int>& dp){
        if(idx<=1) return 0;
        if(dp[idx]!= -1) return dp[idx];
        int left = solve(idx-1,cost,dp) + cost[idx-1];
        int right = solve(idx-2,cost,dp) + cost[idx-2];
        
        dp[idx] = min(left,right);
        return dp[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(n, cost, dp);
    }

    // Time Complexity - O(N)
    // Space Complexity - O(N) for call stack + O(N) for dp vector
};
