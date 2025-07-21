class Solution {

    // 1  2   3   4   4   5   5   7   8   10
    //                             l
    //                             h
    //                             m
private:
    int upperBound(vector<int>& nums, int target){
        int low = 0, high = nums.size(), ans;
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]<=target) low=mid+1;
            else{
                high = mid;
            }
        }
        return high;
    }
    int countLessOrEq(vector<vector<int>>& matrix, int target){
        int count = 0, lowerBound = 0;
        for(int i = 0;i<matrix.size();i++){
            lowerBound = upperBound(matrix[i],target);
            count+=lowerBound;
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), low = matrix[0][0], high = matrix[n-1][n-1];
        while(low<high){
            int mid = low + (high-low)/2;
            int count = countLessOrEq(matrix,mid);

            if(count<k) low = mid+1;
            else high = mid;
        }
        return low;
    }
};