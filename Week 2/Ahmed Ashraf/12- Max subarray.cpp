class Solution 
{
public:
    // Kadane's Algorithm
    int maxSubArray(vector<int>& nums) 
    {
        int max_sum = nums[0];
        int current_sum = 0;
        
        for (int num : nums) 
        {
            current_sum += num;       
            max_sum = max(current_sum , max_sum);
            current_sum = max(current_sum,0);
        }
        
        return max_sum;
    }
};
