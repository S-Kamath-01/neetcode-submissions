class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Using Stacks
        int n = heights.size();
        vector<int> leftMost(n,-1);
        vector<int> rightMost(n,n);
        stack<int> stk;

        for(int i = 0; i<n; i++){
            while(!stk.empty() && heights[stk.top()]>= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                leftMost[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();

        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && heights[stk.top()]>= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                rightMost[i] = stk.top();
            }
            stk.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i<n;i++){
            leftMost[i]+=1;
            rightMost[i]-=1;
            maxArea = max(maxArea, heights[i]*(rightMost[i]-leftMost[i]+1));
        }
        return maxArea;

        // Time Complexity - O(n)
        // Space Complexity - O(n)
    }
};
