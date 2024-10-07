class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue <pair<int,vector<int>>> closestPoints;
        for (auto &point : points)
        {
            int x = point[0];
            int y = point[1];
            int distance = x*x + y*y ;
            closestPoints.push({distance,point});

            if (closestPoints.size() > k)
                closestPoints.pop();

        }

        vector<vector<int>> result;
        while(!closestPoints.empty())
        {
            auto point = closestPoints.top().second;
            result.push_back(point);
            closestPoints.pop();
        }
        return result;
    }
    
};