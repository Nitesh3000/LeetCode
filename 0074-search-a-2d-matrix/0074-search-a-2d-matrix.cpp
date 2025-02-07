class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix[0].size()*matrix.size() -1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();
            if(target == matrix[row][col]) return true;
            else if(target>matrix[row][col]) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};