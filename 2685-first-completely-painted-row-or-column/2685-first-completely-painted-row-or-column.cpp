class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int rows = mat.size();
        const int cols = mat[0].size();

        vector<int> r(mat.size(),0);
        vector<int> c(mat[0].size(),0);

        vector<pair<int, int>> positions(rows * cols + 1);
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                positions[mat[i][j]] = {i,j};
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            auto [row, col] = positions[arr[i]];
            r[row]++;
            c[col]++;
            if(r[row]==cols || c[col]==rows){
                return i;
            }
        }
        return 0;
        
    }
};