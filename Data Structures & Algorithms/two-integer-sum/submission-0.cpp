class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> numsWithIndex;
        for(int i = 0;i<n;i++){
            int complement = target - nums[i];
            if(numsWithIndex.find(complement)!= numsWithIndex.end()){
                return {numsWithIndex[complement],i};
            }
            numsWithIndex[nums[i]] = i;
        }
        return {-1,-1};

    }
};
