class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>results(temperatures.size());
        stack<int> stk;
        for(int i = 0; i<temperatures.size();i++){
            int count = 1;
            int j = i+1;
            while(j< temperatures.size()){
                if(temperatures[j]>temperatures[i]){
                    break;
                }
                j++;
                count++;
            }
            count = (j== temperatures.size())?0:count;
            results[i] = count;
            

        }
        return results;
    }
    // Time Complexity - O(n²)
    // Space Complexity - O(1) extra space and O(n) space for the output array
};
