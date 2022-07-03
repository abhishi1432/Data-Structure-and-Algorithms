class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high){
            if(nums[low]%2!=0){
                swap(nums[high--],nums[low]);
            }
            else
                low+=1;
        }
        return nums;
    }
};