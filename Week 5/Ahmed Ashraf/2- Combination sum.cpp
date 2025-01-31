class Solution
{
public:

    vector<vector<int>> combinations;
    vector<int> candidates;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        
        sort(candidates.begin(), candidates.end()); 
        this->candidates = candidates;
        
        vector<int> combination;
        backTrack( combination , target, 0);
        return combinations;
    }

private:
    void backTrack(vector<int> &combination, int target, int start)
    {
        if (target == 0)
        {
            combinations.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i)
        {
            if (candidates[i] > target)
                return; 

            combination.push_back(candidates[i]);
            backTrack(combination, target - candidates[i], i);
            combination.pop_back();
        }
    }
};
