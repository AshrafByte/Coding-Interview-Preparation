class Solution {
public:

    int majorityElement(vector<int>& nums) 
    {
        unordered_map <int,int> freq;
        for (auto &num : nums)
            freq[num]++;
        auto maxElement = max_element(freq.begin(),freq.end(),comp);
        return maxElement->first;
    }

    static bool comp (const pair<int, int>& a , const pair<int, int>& b)
    {
        return a.second < b.second ;
    }
};