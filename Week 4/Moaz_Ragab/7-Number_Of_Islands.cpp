class Solution {
public:
    int numIslands(vector <vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector visited(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        vector <pair<int, int>> direc = {{1,  0},
                                         {-1, 0},
                                         {0,  1},
                                         {0,  -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {

                    ans++;
                    queue <pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto [xtmp, ytmp]: direc) {
                            int xnext, ynext;
                            xnext = x + xtmp;
                            ynext = y + ytmp;
                            if (xnext >= 0 && xnext < n && ynext >= 0 && ynext < m && !visited[xnext][ynext] &&
                                grid[xnext][ynext] == '1') {
                                visited[xnext][ynext] = 1;
                                q.push({xnext, ynext});
                            }

                        }

                    }

                }
            }
        }
        return ans;
    }
};