class Solution
{
public:
    vector<vector<int>> mat;
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        this->mat = mat;
        auto [distance, que] = initializeDistanceAndQueue();
        BFS(distance, que);

        return distance;
    }

    pair<vector<vector<int>>, queue<pair<int, int>>> initializeDistanceAndQueue()
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> distance(m, vector<int>(n, -1));
        queue<pair<int, int>> que;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    distance[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        return {distance, que};
    }

    void BFS(vector<vector<int>> &distance, queue<pair<int, int>> &que)
    {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();

            for (auto [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;

                if (validCell(nx, ny) && distance[nx][ny] == -1)
                {
                    distance[nx][ny] = distance[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }
    }

    bool validCell(int i, int j)
    {
        int m = mat.size() - 1;
        int n = mat[0].size() - 1;
        return (0 <= i && i <= m) && (0 <= j && j <= n);
    }
};
