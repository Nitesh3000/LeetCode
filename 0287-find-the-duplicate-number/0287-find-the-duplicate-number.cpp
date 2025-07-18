class Solution {
    // 1   3   4   2   2

    //              s
    //              f
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
           slow = nums[slow];
           fast = nums[nums[fast]]; 
        }while(slow!=fast);
        fast= nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
