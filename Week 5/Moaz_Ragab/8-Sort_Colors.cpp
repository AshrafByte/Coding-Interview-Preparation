class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int leftptr = 0, rightptr = nums.size() - 1, i = 0;

        while (i <= rightptr) {
            if (nums[i] == 0) {
                swap(nums[i], nums[leftptr]);
                leftptr++;
                i++; 
            } 
            else if (nums[i] == 2) {
                swap(nums[i], nums[rightptr]);
                rightptr--;
            } 
            else {
                i++; 
            }
        }

        return nums;
    }
};
