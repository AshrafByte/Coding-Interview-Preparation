class Solution {
public:
    vector <vector<int>> insert(vector <vector<int>> &intervals, vector<int> &newInterval) {
        int x = newInterval[0];
        int y = newInterval[1];
        vector <vector<int>> ans;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < x) {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < intervals.size() && intervals[i][0] <= y) {
            x = min(x, intervals[i][0]);
            y = max(y, intervals[i][1]);
            i++;
        }
        ans.push_back({x, y});
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};