class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        int n = intervals.size();
        vector <vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < intervals.size()) {
            int x, y;
            x = intervals[i][0];
            y = intervals[i][1];

            while (i + 1 < n && intervals[i + 1][0] <= y) {
                y = max(y, intervals[i + 1][1]);
                i++;
            }

            vector<int> tmp = {x, y};
            ans.push_back(tmp);
            i++;
        }
        return ans;
    }
};