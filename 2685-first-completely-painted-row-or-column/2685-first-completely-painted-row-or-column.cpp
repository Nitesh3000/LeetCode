class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int rows = mat.size();
        const int cols = mat[0].size();

        vector<int> r(mat.size(),0);
        vector<int> c(mat[0].size(),0);

        map<int,vector<int>> m;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                m[mat[i][j]] = {i,j};
            }
        }
        int i = 0;
        for(auto a:arr){
            int row = (m[a])[0];
            int col = (m[a])[1];
            r[row]++;
            c[col]++;
            if(r[row]==cols || c[col]==rows){
                return i;
            }
            i++;
        }
        return 0;
        
    }
};