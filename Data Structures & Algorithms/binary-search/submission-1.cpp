class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Iterative Binary Search
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left<=right){
            mid = left + (right - left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                left = mid+1;
            }else if(nums[mid] > target){
                right = mid-1;
            }
        }
        return -1;
        // Time Complexity - O(log n)
        // Space Complexity - O(1)
    }
};
