class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Using Iteration
        int n = position.size();
        vector<pair<int,int>> pr;
        for(int i = 0; i< n; i++){
            pr.push_back({position[i],speed[i]});
        }
        sort(pr.rbegin(),pr.rend());

        int fleets = 1;
        double prevTime = (double)(target-pr[0].first)/(pr[0].second);
        for(int i = 1; i<n; i++){
            double currTime = (double)(target - pr[i].first)/(pr[i].second);
            if(currTime>prevTime){
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
        // Time Complexity - O(n logn)
        // Space Complexity - O(n)
    }
};
