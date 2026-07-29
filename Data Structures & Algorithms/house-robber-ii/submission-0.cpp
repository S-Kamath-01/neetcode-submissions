class Solution {
// Memoization
private:
    int solve(vector<int>& nums, int i , int start, vector<int>& dp){
        if(i<start){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int robCurrent = nums[i] + solve(nums, i-2, start, dp);
        int skipCurrent = solve(nums,i-1,start,dp);
        return dp[i] = max(robCurrent,skipCurrent);
    }
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n,-1);
        int plan1 = solve(nums,n-2,0,dp);

        vector<int> dp2(n,-1);
        int plan2 = solve(nums,n-1,1,dp2);
        return max(plan1,plan2);
    }
    // Time Complexity- O(N)
    // Space Complexity - O(N)
};
