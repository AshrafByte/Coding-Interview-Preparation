//Topological Sort | Kahn's Algorithm

class Solution {
public:
    bool canFinish(int numCourses, vector <vector<int>> &prerequisites) {
        if (prerequisites.size() == 0)
            return true;
        vector <vector<int>> adj(numCourses, vector<int>());
        vector<int> inedges(numCourses + 1, 0);
        vector<int> visited(numCourses + 1, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inedges[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {

            if (inedges[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();

            cnt++;

            for (int i = 0; i < adj[tmp].size(); i++) {
                inedges[adj[tmp][i]]--;
                if (inedges[adj[tmp][i]] == 0) {
                    q.push(adj[tmp][i]);
                }

            }
        }
        cout << cnt << endl;
        return (cnt == numCourses);
    }

};