class Solution {
// Tabulation
private:
    int solve(vector<int>& nums, int start , int end){
        int range_size = end - start + 1;
        vector<int> dp(range_size);
        dp[0] = nums[start];
        dp[1] = max(nums[start],nums[start+1]);

        for(int i = 2; i< range_size; i++){
            int currentHouseValue = nums[start+i];
            dp[i] = max(dp[i-1], currentHouseValue+dp[i-2]);

        }
        return dp[range_size-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        int plan1 = solve(nums, 0, n-2);
        int plan2 = solve(nums,1, n-1);
        return max(plan1,plan2);
    }
};
