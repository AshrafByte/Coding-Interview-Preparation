class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points,int k) {
      
        priority_queue<pair<long long, pair<long long, long long>>> maxHeap;

      
        for(long long i = 0; i < points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];
         
            long long distance = x * x + y * y;

           
            maxHeap.push({distance, {x, y}});
            
           
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

       
        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
           int x = maxHeap.top().second.first;
            int y = maxHeap.top().second.second;
            ans.push_back({x, y});
            maxHeap.pop();
        }

        return ans;
    }
};
