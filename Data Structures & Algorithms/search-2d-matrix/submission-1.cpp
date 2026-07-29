class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Staircase Search
        int m = matrix.size();
        int n = matrix[0].size();

        int r = 0,  c = n-1;
        while(r<m && c>=0){
            if(matrix[r][c] == target){
                return true;
            }else if(matrix[r][c]>target){
                c--;
            }else{
                r++;
            }
        }
        return false;
        // Time Complexity - O(m+n)
        // Space Complexity - O(1)
    }
};
