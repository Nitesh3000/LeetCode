class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = n*(n-1)/2;
        long count=0;
        unordered_map<int,int> map;
        for(int i = 0;i<nums.size();i++){
            if(map.find(nums[i]- i) != map.end()){
                count += map[nums[i] - i];
            }
            map[nums[i] - i]++;
        }
        return totalPairs -  count;
    }
};