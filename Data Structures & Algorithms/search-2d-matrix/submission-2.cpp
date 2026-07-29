class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search (One Pass)
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int l = 0;
        int r = ROWS*COLS -1 ;
        int m;
        while(l<=r){
            m = l + (r-l)/2;
            int row = m/COLS;
            int col = m%COLS;
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] < target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return false;
        // Time Complexity - O(log(m*n))
        // Space Complexity - O(1)
    }
};
