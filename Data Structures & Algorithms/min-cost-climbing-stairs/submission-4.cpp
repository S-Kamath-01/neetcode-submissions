class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Space Optimized
        int prev1= 0;
        int prev2 = 0;
        int curr;
        for(int i = 2; i<=cost.size();i++){
            curr = min(prev1+cost[i-1], prev2+cost[i-2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        // Time Complexity - O(N)
        // Space Complexity - O(1)
    }
};
