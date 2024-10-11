class Solution
{
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> recStack;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        visited = vector<bool>(numCourses, false);
        recStack = vector<bool>(numCourses, false); // recursion stack.
        graph = vector<vector<int>>(numCourses);

        for (auto &pre : prerequisites)
            graph[pre[0]].push_back(pre[1]);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && haveCycle(i))
                return false;
        }
        return true;
    }

    bool haveCycle(int node)
    {
        if (recStack[node])
            return true;

        if (visited[node])
            return false;

        visited[node] = true;
        recStack[node] = true;

        for (auto &neighbor : graph[node])
        {
            if (haveCycle(neighbor))
                return true;
        }

        recStack[node] = false;
        return false;
    }
};