class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int fptr = 0, sptr = 0;
        int fsize = firstList.size(), ssize = secondList.size();
        // vector<int> temp(2);

        while(fptr<fsize && sptr<ssize){
            if(secondList[sptr][0]<=firstList[fptr][1] && firstList[fptr][0]<=secondList[sptr][1]){
                res.push_back({max(firstList[fptr][0],secondList[sptr][0]), min(firstList[fptr][1],secondList[sptr][1])});
            }
            if(firstList[fptr][1]>secondList[sptr][1]){
                sptr++;
            }
            else{
                fptr++;
            }
        }
        return res;
    }
};