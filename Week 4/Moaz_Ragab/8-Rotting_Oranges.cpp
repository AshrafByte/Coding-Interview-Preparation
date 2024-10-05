class Solution {
public:
    int orangesRotting(vector <vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        function<int(int, int)> isvalid = [&](int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m) return false;
            return true;
        };
        queue <pair<int, int>> rotten;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
               
                    rotten.push({i, j});
                }

            }
        }
        int time = 0, ans = 0;
        while (!rotten.empty()) {
            time++;
            int tmp = rotten.size();
         
           
            for (int i = 0; i < tmp; i++) {
                auto [x, y] = rotten.front();
                rotten.pop();
            
                
                if (isvalid(x + 1, y) && grid[x + 1][y] == 1) {
                    rotten.push({x+ 1, y});
                    ans = max(time, ans);
                    grid[x + 1][y]=2;

                }
                if (isvalid(x - 1, y) && grid[x - 1][y] == 1) {
                    rotten.push({x- 1, y});
                     ans = max(time, ans);
                     grid[x - 1][y] = 2;
                }
                if (isvalid(x, y + 1) && grid[x][y + 1] == 1) {
                    rotten.push({x, y + 1});
                     ans = max(time, ans);
                     
                    grid[x][y + 1] = 2;
                }
                if (isvalid(x, y - 1) && grid[x][y - 1] == 1) {
                    rotten.push({x, y - 1});
                     ans = max(time, ans);
                grid[x][y - 1] = 2;
                }
            }
         

        }
    int flg=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                flg=1;
                break;
            }
        }
    }
if(flg)
return -1;
return ans;
    }
};