class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int m = a.size();
		int n = b.size();
		if(m == 0 || n == 0) return {};
		vector<int> res;
		int i = 0;
		int indexa = 0;
		int indexb = 0;
		while(indexa<m && indexb<n){
            if(a[indexa] < b[indexb]) indexa++;
            else if(a[indexa]>b[indexb]) indexb++;
            else{
                res.push_back(a[indexa]);
                
                while(indexa<m-1 && indexb<n-1 && a[indexa]==a[indexa+1] && b[indexb] ==b[indexb+1]){
                    indexa++;
                    indexb++;
                }
                indexa++;
                indexb++;
            }
        }
        return res;

            }
};