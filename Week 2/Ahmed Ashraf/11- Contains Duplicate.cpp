class Solution {
public:
    unordered_set <int> setu;
    bool containsDuplicate(vector<int>& nums) 
    {
        for (auto &num : nums)
        {
            if (setu.count(num))
                return true;
            setu.insert(num);
        }
        return false;
    }
};