/*
    [[1,3],[6,9]], newInterval = [2,5]
    1 2 3 4 5 6 7 8 9
    2 3 0 0 0 3 0 0 0
    1 2 3 4 5 6 7 8 9
    intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    [[1,2],[3,5],[4,8],[6,7],[8,10],[12,16]]
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector <vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0 ; i < intervals.size() ; i++)
            pq.push({intervals[i][0],intervals[i][1]});

        pq.push({newInterval[0] , newInterval[1]});
        pq.push({1000000 , 1000000});

        int st = pq.top()[0];
        int en = pq.top()[1];
        pq.pop();
        while (!pq.empty())
        {
            if (st < pq.top()[0] && en < pq.top()[0])
            {
                ans.push_back({st , en});
                st = pq.top()[0];
                en = pq.top()[1];
            }
            else
                en = max(en , pq.top()[1]);
                
            pq.pop();
        }
        
        return ans;
    }
};
///////////////////////////////////////
//another solution

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        ans.push_back(newInterval);

        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
