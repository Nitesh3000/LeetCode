class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        if(intervals.size() == 1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> current = intervals[0];
        
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i][0]<=current[1]){
                current[1] = max(current[1],intervals[i][1]);
            }
            else{
                res.push_back(current);
                current = intervals[i];
            }
        }
        res.push_back(current);
        return res;
    }
};