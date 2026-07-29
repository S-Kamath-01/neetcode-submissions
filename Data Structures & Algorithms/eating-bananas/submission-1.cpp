class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary Search
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int res = r;

        while(l<=r){
            int k = l + (r-l)/2;
            long long totalTime = 0;
            for(int p: piles){
                totalTime += ceil(static_cast<double>(p)/k);
            }
            if(totalTime<=h){
                res = k;
                r = k-1;
            }else{
                l = k+1;
            }
        }
        return res;
        // Time Complexity - O(n*log(m))
        // Space Complexity - O(1)

    }
};
