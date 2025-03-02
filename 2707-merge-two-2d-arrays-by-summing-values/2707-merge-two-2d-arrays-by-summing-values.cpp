class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int nums1Index = 0, nums2Index = 0;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        vector<vector<int>> mergedArray;
        while(nums1Index<nums1Size && nums2Index<nums2Size){
            int key1 = nums1[nums1Index][0], key2 = nums2[nums2Index][0];
            int value1 = nums1[nums1Index][1],value2 = nums2[nums2Index][1];
            if(key1 == key2){
                mergedArray.push_back({key1,value1+value2});
                nums1Index++;
                nums2Index++;
            }
            else if(key1<key2){
                mergedArray.push_back({key1,value1});
                nums1Index++;
            }
            else{
                mergedArray.push_back({key2,value2});
                nums2Index++;
            }
        }
        while(nums1Index<nums1Size){
            int key1 = nums1[nums1Index][0];
            int value1 = nums1[nums1Index][1];
            
            mergedArray.push_back({key1,value1});
            nums1Index++;
            
        }
        while(nums2Index<nums2Size){
            int key2 = nums2[nums2Index][0];
            int value2 = nums2[nums2Index][1];
            
            mergedArray.push_back({key2,value2});
            nums2Index++;
            
        }
        return mergedArray;
    }
};