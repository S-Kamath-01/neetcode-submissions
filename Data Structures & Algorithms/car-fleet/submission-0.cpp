class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Using Stacks
        vector<pair<int,int>> pr;
        for(int i =  0; i<position.size();i++){
            pr.push_back({position[i],speed[i]});
        }
        sort(pr.rbegin(),pr.rend());
        vector<double> stk;
        for(auto &p : pr){
            stk.push_back((double)(target-p.first)/p.second);
            if(stk.size()>=2 && stk.back()<= stk[stk.size()-2]){
                stk.pop_back();
            }
        }
        return stk.size();
        // Time Compelxity - O(nlogn)
        // Space Complexity - O(n)
    }
};
