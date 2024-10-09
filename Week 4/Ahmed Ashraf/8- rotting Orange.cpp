
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {    
        auto que = initializeQueue(grid);
        return processRotting(que, grid);
    }

private:
    queue<pair<int, pair<int, int>>> initializeQueue(vector<vector<int>> &grid)
    {
        queue<pair<int, pair<int, int>>> que;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == 2)
                    que.push({0, {r, c}});

        return que;
    }

    int processRotting(queue<pair<int, pair<int, int>>> &que, vector<vector<int>> &grid)
    {
        int cnt = 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!que.empty())
        {
            auto [level, point] = que.front();
            auto [rf, cf] = point;
            que.pop();

            for (auto [dr, dc] : directions)
            {
                int nr = rf + dr;
                int nc = cf + dc;
                if (isValid(grid, nr, nc) && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    que.push({level + 1, {nr, nc}});
                    cnt = level + 1;
                }
            }
        }

        return checkForFreshOranges(grid, cnt);
    }

    bool isValid(vector<vector<int>> &grid, int row, int col)
    {
        int rows = grid.size() - 1;
        int cols = grid[0].size() - 1;
        return (0 <= row && row <= rows) && (0 <= col && col <= cols);
    }

    int checkForFreshOranges(const vector<vector<int>> &grid, int cnt)
    {
        for (const auto &row : grid)
            for (const auto &col : row)
                if (col == 1)
                    return -1;

        return cnt;
    }
};
