class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();           
        int m = mat[0].size();       
        vector<vector<int>> dp(n, vector<int>(m, 1e8)); 
        queue<pair<int, int>> q;

       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                    q.push({i, j});  
                }
            }
        }

     
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

       
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

           
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;

              
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (dp[ni][nj] > dp[i][j] + 1) {
                        dp[ni][nj] = dp[i][j] + 1; 
                        q.push({ni, nj});          
                    }
                }
            }
        }

        return dp;
    }
};
