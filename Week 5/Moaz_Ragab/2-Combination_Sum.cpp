class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
        function<void(vector<int>&, int, int)> go = [&](vector<int>& v, int ind, int sum) {
            if (sum < 0 || ind == candidates.size()) {
                return; 
            }
            if (sum == 0) {
                ans.push_back(v); 
                return;
            }

            v.push_back(candidates[ind]);
            go(v, ind, sum - candidates[ind]);
            v.pop_back();

         
            go(v, ind + 1, sum); 
        };

        vector<int> tmp; 
        go(tmp, 0, target); 
        return ans;
    }
};
