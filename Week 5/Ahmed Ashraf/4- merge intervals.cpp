class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end());

        auto current = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= current[1])
                current[1] = max(current[1], intervals[i][1]);
            else
            {
                results.push_back(current);
                current = intervals[i];
            }
        }

        results.push_back(current);
        return results;
    }
};
