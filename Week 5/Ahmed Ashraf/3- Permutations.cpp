class Solution
{
public:
    vector<vector<int>> permutations;
    

    vector<vector<int>> permute(vector<int> &nums)
    {
        backTracking(nums,0);
        return permutations;
    }

    void backTracking(vector<int> &nums,int index)
    {
        if (index == nums.size()-1)
        {
            permutations.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backTracking(nums,index + 1);
            swap(nums[index], nums[i]);
        }
    }
};
