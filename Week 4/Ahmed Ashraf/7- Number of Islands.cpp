class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == '1')
                {
                    islands++;
                    dfs(grid, row, col);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        if (!valid(grid, row, col) || grid[row][col] == '0')
            return;

        grid[row][col] = '0';

        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

    bool valid(vector<vector<char>> &grid, int row, int col)
    {
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
        return (0 <= row && row <= m) && (0 <= col && col <= n);
    }
};