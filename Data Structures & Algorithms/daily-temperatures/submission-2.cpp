class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Dynamic Programming

        int n = temperatures.size();
        vector<int> res(n,0);

        for(int i = n-2; i>=0; i--){
            int j = i+1;
            while(j<n && temperatures[j]<= temperatures[i]){
                if(res[j]==0){
                    j = n;
                    break;
                }
                j+= res[j];
            }
            if(j<n){
                res[i] = j - i ;
            }

        }
        return res;
    }
    // Time Complexity - O(n)
    // Space Complexity - O(1) extra space and O(n) for output array
};
