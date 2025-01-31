class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        vector <int> freq (3);
        for (auto &num : nums)
            freq[num]++;
        
        int index = 0 ;
        for (auto &num : nums)
        {
            while (freq[index] == 0)
                index++;
                
            num = index;
            freq[index]--;
        }
    }
};