class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans (2) ;

        int arrSize = nums.size();
        vector <pair<int,int>> pairs (arrSize);

        for (int i = 0 ; i <arrSize ; i++)
            pairs[i] = {nums[i] , i};

        sort(pairs.begin(),pairs.end());
        
        int left = 0 ;
        int right = nums.size() - 1;
        while (left < right)
        {
            int sum = pairs[left].first + pairs[right].second ;
            if (sum == target)
            {
                ans = {pairs[left].second ,pairs[right].second};
                break;
            }
            else if (sum > target)
                right--;
            else
                left++;
        }
        return ans ;
    }
};